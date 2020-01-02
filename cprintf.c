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

/* Machine à état */

void init_list_fmt(Format list_fmt[NB_FORMAT])
{
	list_fmt[CHAR].type = 'c';
	list_fmt[STR].type = 's';
	list_fmt[POINTER].type = 'p';
	list_fmt[INT_D].type = 'd';
	list_fmt[INT_I].type = 'i';
	list_fmt[INT_U].type = 'u';
	list_fmt[HEX_MIN].type = 'x';
	list_fmt[HEX_MAJ].type = 'X';
	list_fmt[NO_FORMAT].type = '%';

	list_fmt[CHAR].f = print_c;
	list_fmt[STR].f = print_s;
	list_fmt[INT_D].f = print_d;
	list_fmt[INT_I].f = print_d;
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

int print_d(va_list av)
{
	int	d;
	d = va_arg(av, int);
	ft_putnbr(d);
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
	ft_putchar('\n');
}
