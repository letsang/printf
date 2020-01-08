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

#include "ft_printf.h"
#include <unistd.h>

int	ft_putchar(int c)
{
	int		ret;

	ret = write(1, &c, 1);
	return (ret);
}

int	ft_putstr(const char *s)
{
	int		ret;
	int		i;

	ret = 0;
	if (!s)
		ret += write(1, "(null)", 6);
	if (s)
	{
		i = 0;
		while (s[i])
		{
			ret += write(1, &s[i], 1);
			i++;
		}
	}
	return (ret);
}

int	ft_putnbr(int n)
{
	static int	ret;
	unsigned int	nbr;

	nbr = n;
	ret = 0;
	if (n < 0)
	{
		ret = ft_putchar('-');
		nbr *= -1;
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	ret += ft_putchar(nbr % 10 + 48);
	return (ret);
}

int	ft_putnbr_un(unsigned int n)
{
	static int	ret;

	ret = 0;
	if (n > 9)
		ft_putnbr_un(n / 10);
	ret += ft_putchar(n % 10 + 48);
	return (ret);
}

int	ft_putnbr_hex_min(unsigned long nb)
{
    int			c;
    static int		ret;
    
    ret = 0;
    if (nb >= 16)
        ft_putnbr_hex_min(nb / 16);
    c = nb % 16 + (nb % 16 < 10 ? '0' : 'a' - 10);
    ret += ft_putchar(c);
    return (ret);
}

int	ft_putnbr_hex_maj(unsigned long nb)
{
    int			c;
    static int		ret;
    
    ret = 0;
    if (nb >= 16)
        ft_putnbr_hex_maj(nb / 16);
    c = nb % 16 + (nb % 16 < 10 ? '0' : 'A' - 10);
    ret += ft_putchar(c);
    return (ret);
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
	list_fmt[INT_D].f = print_di;
	list_fmt[INT_I].f = print_di;
	list_fmt[UN].f = print_u;
	list_fmt[HEX_MIN].f = print_xmin;
	list_fmt[HEX_MAJ].f = print_xmaj;
	list_fmt[NO_FORMAT].f = print_percent;
}

int	check_fmt(va_list av, char c)
{
	int	ret;
	Format list_fmt[NB_FORMAT];
	type_list current_fmt;

	ret = 0;
	init_list_fmt(list_fmt);
	current_fmt = CHAR;
	while (current_fmt != END)
	{
		if (list_fmt[current_fmt].type == c)
			ret += list_fmt[current_fmt].f(av);
		current_fmt++;
	}
	return (ret);
}
	
/* Fin machine à état */

int	print_s(va_list av)
{
	char	*s;

	s = va_arg(av, char *);
	return (ft_putstr(s));
}

int	print_c(va_list av)
{
	char	c;

	c = va_arg(av, int);
	return (ft_putchar(c));
}

int	print_di(va_list av)
{
	int	n;

	n = va_arg(av, int);
	return (ft_putnbr(n));
}

int	print_u(va_list av)
{
	int	n;

	n = va_arg(av, unsigned int);
	return (ft_putnbr_un(n));
}

int	 print_p(va_list av)
{
	void	*p;
	int		ret;

	ret = 0;
	p = va_arg(av, void *);
	ret = ft_putchar('0');
	ret += ft_putchar('x');
	ret += ft_putnbr_hex_min((unsigned long)p);
	return (ret);
}

int	print_xmin(va_list av)
{
	unsigned long x;

	x = va_arg(av, unsigned int);
	return (ft_putnbr_hex_min(x));
}

int	print_xmaj(va_list av)
{
	unsigned long x;

	x = va_arg(av, unsigned int);
	return (ft_putnbr_hex_maj(x));
}

int	print_percent(va_list av)
{
	return (ft_putchar('%'));
}

int	ft_printf(const char *fmt, ...)
{
	va_list	av;
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	va_start(av, fmt);
	while (fmt[i])
	{
		if ((fmt[i]) == '%')
			ret += check_fmt(av, fmt[++i]);
		else
			ret += ft_putchar(fmt[i]);
		i++;
	}
	va_end(av);
	return (ret);
}
