/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 10:51:00 by jtsang            #+#    #+#             */
/*   Updated: 2020/01/09 16:07:20 by jtsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_spec(char c)
{
	int				i;
	char				spec[10] = "cspdiuxX%";
	
	i = 0;
	while (spec[i])
	{
		if (spec[i] == c)
			return (1);
		i++;
	}
	return (0);
}

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

t_flag		check_flag(va_list av, const char *fmt)
{
	int				i;
	t_flag				list_flag = {0, 0, 0, 0, 0};

	i = 0;
	while (fmt[i] == '-' || fmt[i] == '0' || fmt[i] == '+' || fmt[i] == ' ')
	{
		if (!(list_flag.justify))
			list_flag.justify = (fmt[i] == '-') ? 1 : 0;
		if (!(list_flag.justify) && (!(list_flag.padding)))
			list_flag.padding = (fmt[i] == '0') ? 1 : 0;
		if (!(list_flag.pos))
			list_flag.pos = (fmt[i] == '+') ? 1 : 0;
		i++;
	}
	if (fmt[i] >= '0' && fmt[i] <= '9')
		list_flag.width = ft_atoi(fmt + i);
	else if (fmt[i] == '*')
	{
		list_flag.width = va_arg(av, int);
		i++;
	}
	while (fmt[i] && (fmt[i] >= '0' && fmt[i] <= '9'))
		i++;
	if (fmt[i] == '.' && (fmt[++i] >= '0' && fmt[i] <= '9'))
		list_flag.precision = ft_atoi(fmt + i);
	else if (fmt[i] == '.' && fmt[++i] == '*')
	{
		list_flag.precision = va_arg(av, int);
		i++;
	}
	while (fmt[i] && (fmt[i] >= '0' && fmt[i] <= '9'))
		i++;
	return (list_flag);
}

int		check_fmt(va_list av, t_flag list_flag, const char *fmt)
{
	int				i;
	int				ret;
	t_format		list_fmt[NB_FORMAT];
	t_type			current_type;

	i = 0;
	ret = 0;
	init_list_fmt(list_fmt);
	current_type = CHAR;
	while (current_type != END)
	{
		if (list_fmt[current_type].type == fmt[i])
			ret += list_fmt[current_type].f(av, list_flag);
		current_type++;
	}
	return (ret);
}

int		ft_printf(const char *fmt, ...)
{
	va_list			av;
	t_flag			list_flag;
	int				i;
	int				ret;

	i = 0;
	ret = 0;
	va_start(av, fmt);
	while (fmt[i])
	{
		if ((fmt[i]) == '%')
		{
			i++;
			list_flag = check_flag(av, fmt + i);
			while (fmt[i] && !(is_spec(fmt[i])))
				i++;
			ret += check_fmt(av, list_flag, fmt + i);
		}
		else
			ret += ft_putchar(fmt[i]);
		i++;
	}
	va_end(av);
	return (ret);
}
