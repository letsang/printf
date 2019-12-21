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

void ini_ListFormat_Token(Format list_format[NB_FORMATS])
{
	list_format[INT].token = 'd';
	list_format[CHAR].token = 'c';
	list_format[STR].token = 's';

	list_format[INT].next_format = CHAR;
	list_format[CHAR].next_format = STR;
	list_format[STR].next_format = NO_FORMAT;

	list_format[INT].f = affInt;
	list_format[CHAR].f = affCh;
	list_format[STR].f = affStr;
}

void formatCmp(va_list av, char c)
{
	Format list_format[NB_FORMATS];
	ini_ListFormat_Token(list_format);
	FORMATS_TOKEN current_format = INT;
	while (current_format != NO_FORMAT)
	{
		if (list_format[current_format].token == c)
			list_format[current_format].f(av);
		current_format = list_format[current_format].next_format;
	}
}
	
/* Fin machine à état */

int affStr(va_list av)
{
	char	*s;
	s = va_arg(av, char *);
	ft_putstr(s);
	return true;
}

int affCh(va_list av)
{
	char c;
	c = va_arg(av, int);
	ft_putchar(c);
	return true;
}

int affInt(va_list av)
{
	int	d;
	d = va_arg(av, int);
	ft_putnbr(d);
	return true;
}

void cprintf(char *str, ...)
{
	va_list av;
	size_t i;
	va_start(av, str);
	for (i = 0; str[i]; i++)
		if ((str[i]) == '%')
			formatCmp(av, str[++i]);
		else ft_putchar(str[i]);
	va_end(av);
	ft_putchar('\n');
}
