/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 10:51:00 by jtsang            #+#    #+#             */
/*   Updated: 2020/01/09 12:44:06 by jtsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_list_fmt(t_format list_fmt[NB_FORMAT])
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

int		check_fmt(va_list av, char c)
{
	int				ret;
	t_format		list_fmt[NB_FORMAT];
	t_type			current_type;

	ret = 0;
	init_list_fmt(list_fmt);
	current_type = CHAR;
	while (current_type != END)
	{
		if (list_fmt[current_type].type == c)
			ret += list_fmt[current_type].f(av);
		current_type++;
	}
	return (ret);
}

int		ft_printf(const char *fmt, ...)
{
	va_list			av;
	int				i;
	int				ret;

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
