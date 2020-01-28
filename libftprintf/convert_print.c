/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 14:16:41 by jtsang            #+#    #+#             */
/*   Updated: 2020/01/28 14:17:27 by jtsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*check_value(va_list av, const char *fmt, t_flag *list_flag)
{
	int				i;

	i = 0;
	if (fmt[i] >= '0' && fmt[i] <= '9')
		list_flag->width = ft_atoi(fmt + i);
	else if (fmt[i] == '*')
	{
		list_flag->width = va_arg(av, int);
		if (list_flag->width < 0)
		{
			list_flag->width *= -1;
			list_flag->justify = 1;
		}
		i++;
	}
	while (fmt[i] && (fmt[i] >= '0' && fmt[i] <= '9'))
		i++;
	return (fmt + i);
}

const char	*check_value_next(va_list av, const char *fmt, t_flag *list_flag)
{
	int				i;

	i = 0;
	if (fmt[i] == '.' && (fmt[i + 1] >= '0' && fmt[i + 1] <= '9'))
		list_flag->precision = ft_atoi(fmt + (i + 1));
	else if (fmt[i] == '.' && fmt[i + 1] == '*')
	{
		list_flag->precision = va_arg(av, int);
		if (list_flag->precision < 0)
		{
			list_flag->precision = 0;
			list_flag->dot = 0;
		}
		i++;
	}
	while (fmt[i] && (fmt[i] >= '0' && fmt[i] <= '9'))
		i++;
	return (fmt);
}

t_flag		check_flag(va_list av, const char *fmt)
{
	int				i;
	t_flag			list_flag;

	i = 0;
	list_flag = init_list_flag();
	while (fmt[i] == '-' || fmt[i] == '0' || fmt[i] == '+')
	{
		if (!(list_flag.justify))
			list_flag.justify = (fmt[i] == '-') ? 1 : 0;
		if (!(list_flag.justify) && (!(list_flag.padding)))
			list_flag.padding = (fmt[i] == '0') ? 1 : 0;
		if (!(list_flag.pos))
			list_flag.pos = (fmt[i] == '+') ? 1 : 0;
		i++;
	}
	fmt = check_value(av, fmt + i, &list_flag);
	list_flag.dot = (*fmt == '.') ? 1 : 0;
	fmt = check_value_next(av, fmt, &list_flag);
	return (list_flag);
}

int			check_fmt(va_list av, t_flag list_flag, const char *fmt)
{
	int				i;
	int				ret;
	t_format		list_fmt[NB_FORMAT];
	t_type			current_type;

	if (!fmt)
		return (0);
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

int			convert_print(const char *fmt, va_list av)
{
	int				i;
	int				ret;
	t_flag			list_flag;

	i = 0;
	ret = 0;
	while (fmt[i])
	{
		if ((fmt[i] == '%') && (ft_strlen(fmt + i) > 1) &&
				is_spec_in_fmt(fmt + i + 1))
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
	return (ret);
}
