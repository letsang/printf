/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 08:12:46 by jtsang            #+#    #+#             */
/*   Updated: 2019/12/21 17:26:41 by jtsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cprintf.h"
#include <unistd.h>

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_putstr(const char *s)
{
	int i;

	if (s)
	{
		i = 0;
		while (s[i])
		{
			write(1, &s[i], 1);
			i++;
		}
	}
}

void	ft_putnbr(int n)
{
	unsigned int nbr;

	nbr = n;
	if (n < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + 48);
}

void    ft_printhex(unsigned long p)
{
    int c;
    unsigned long nb;
    
    nb = p;
    if (nb >= 16)
        ft_printhex(nb / 16);
    c = nb % 16 + (nb % 16 < 10 ? '0' : 'a' - 10);
    ft_putchar(c);
}

void    ft_print_x(unsigned int x)
{
    int c;
    unsigned long nb;
    
    nb = (unsigned long)x;
    if (nb >= 16)
        ft_print_x(nb / 16);
    c = nb % 16 + (nb % 16 < 10 ? '0' : 'a' - 10);
    ft_putchar(c);
}

void    ft_print_X(unsigned int X)
{
    int c;
    unsigned long nb;
    
    nb = (unsigned long)X;
    if (nb >= 16)
        ft_print_X(nb / 16);
    c = nb % 16 + (nb % 16 < 10 ? '0' : 'A' - 10);
    ft_putchar(c);
}

/* Machine à état */

void init_list_fmt(Format list_fmt[NB_FORMAT])
{
	list_fmt[CHAR].type = 'c';
	list_fmt[STR].type = 's';
	list_fmt[POINTER].type = 'p';
	list_fmt[INT_D].type = 'd';
	list_fmt[INT_I].type = 'i';
	list_fmt[UN].type = 'u';
	list_fmt[HEX_MIN].type = 'x';
	list_fmt[HEX_MAJ].type = 'X';
	list_fmt[NO_FORMAT].type = '%';

	list_fmt[CHAR].f = print_c;
	list_fmt[STR].f = print_s;
	list_fmt[POINTER].f = print_p;
	list_fmt[INT_D].f = print_int;
	list_fmt[INT_I].f = print_int;
	list_fmt[HEX_MIN].f = print_x;
	list_fmt[HEX_MAJ].f = print_X;
	list_fmt[NO_FORMAT].f = print_no_fmt;
}

void check_fmt(va_list av, char c)
{
	Format list_fmt[NB_FORMAT];
	init_list_fmt(list_fmt);
	type_list current_fmt = CHAR;
	while (current_fmt != END)
	{
		if (list_fmt[current_fmt].type == c)
			list_fmt[current_fmt].f(av);
		current_fmt++;
	}
}
	
/* Fin machine à état */

int print_s(va_list av)
{
	char	*s;
	s = va_arg(av, char *);
	ft_putstr(s);
	return (1);
}

int print_c(va_list av)
{
	char	c;
	c = va_arg(av, int);
	ft_putchar(c);
	return (1);
}

int print_int(va_list av)
{
	int	n;
	n = va_arg(av, int);
	ft_putnbr(n);
	return (1);
}

int print_p(va_list av)
{
	void	*p;
	p = va_arg(av, void *);
	ft_putchar('0');
	ft_putchar('x');
	ft_printhex((unsigned long)p);
	return (1);
}

int print_x(va_list av)
{
	unsigned int x;
	x = va_arg(av, unsigned int);
	ft_print_x(x);
	return (1);
}

int print_X(va_list av)
{
	unsigned int X;
	X = va_arg(av, unsigned int);
	ft_print_X(X);
	return (1);
}

int print_no_fmt(va_list av)
{
	ft_putchar('%');
	return (1);
}

void ft_printf(const char *fmt, ...)
{
	va_list av;
	size_t i;

	va_start(av, fmt);
	i = 0;
	while (fmt[i])
	{
		if ((fmt[i]) == '%')
			check_fmt(av, fmt[++i]);
		else
			ft_putchar(fmt[i]);
		i++;
	}
	va_end(av);
}
