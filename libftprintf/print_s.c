/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:46:10 by jtsang            #+#    #+#             */
/*   Updated: 2020/01/28 10:45:59 by jtsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putstr(const char *s, t_flag list_flag)
{
	int		ret;
	int		i;

	ret = 0;
	if (list_flag.dot == 1 && list_flag.precision == 0)
		return (0);
	else if (s)
	{
		i = 0;
		if (list_flag.precision &&
				((list_flag.precision < ft_strlen(s)) ||
					list_flag.precision > ft_strlen(s)))
		{
			while (s[i] && (i < list_flag.precision))
				ret += write(1, &s[i++], 1);
		}
		else
		{
			while (s[i])
				ret += write(1, &s[i++], 1);
		}
	}
	return (ret);
}

int		print_s_padding(t_flag *list_flag, int *width)
{
	int		ret;

	ret = 0;
	while (*width > 0)
	{
		if (list_flag->padding && *width && !list_flag->precision)
		{
			ret += ft_putchar('0');
			(*width)--;
		}
		else
			ret += print_space(width);
	}
	return (ret);
}

int		print_s_next(int width, char *s, t_flag list_flag)
{
	int			ret;

	ret = 0;
	if (width > 0)
	{
		if (list_flag.justify)
		{
			ret += ft_putstr(s, list_flag);
			ret += print_space(&width);
		}
		else
		{
			ret += print_s_padding(&list_flag, &width);
			ret += ft_putstr(s, list_flag);
		}
	}
	else
		ret += ft_putstr(s, list_flag);
	return (ret);
}

int		print_s(va_list av, t_flag list_flag)
{
	int			ret;
	int			width;
	int			precision;
	char		*s;
	char		*null;

	ret = 0;
	s = va_arg(av, char *);
	null = NULL;
	if (!s)
	{
		null = ft_strdup("(null)");
		s = null;
	}
	precision = (list_flag.precision) ?
			list_flag.precision - ft_strlen(s) : 0;
	width = ((precision > 0) || !list_flag.dot) ?
	list_flag.width - ft_strlen(s) : list_flag.width - list_flag.precision;
	ret += print_s_next(width, s, list_flag);
	if (null)
		free(null);
	return (ret);
}
