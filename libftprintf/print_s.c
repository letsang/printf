/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:46:10 by jtsang            #+#    #+#             */
/*   Updated: 2020/01/09 12:08:18 by jtsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen(const char *s)
{
	int				i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_putstr(const char *s, t_flag list_flag)
{
	int				ret;
	int				i;

	ret = 0;
	if (!s)
		ret += write(1, "(null)", 6);
	if (s)
	{
		i = 0;
		if (list_flag.precision && (list_flag.precision < ft_strlen(s)))
		{
			while (s[i] && (i < list_flag.precision))
			{
				ret += write(1, &s[i], 1);
				i++;
			}
		}
		else if (!list_flag.precision || (list_flag.precision > ft_strlen(s)))
		{
			while (s[i])
			{
				ret += write(1, &s[i], 1);
				i++;
			}
		}
		else
		{
			while (s[i])
			{
				ret += write(1, &s[i], 1);
				i++;
			}
		}
	}
	return (ret);
}

int		print_s_space(int *width)
{
	int		ret;

	ret = 0;
	while (*width > 0)
	{
		ret += ft_putchar(' ');
		(*width)--;
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
			ret += print_s_space(width);
	}
	return (ret);
}

int		print_s(va_list av, t_flag list_flag)
{
	int			ret;
	int			width;
	int			precision;
	char			*s;

	ret = 0;
	s = va_arg(av, char *);
	precision = (list_flag.precision) ?
			list_flag.precision - ft_strlen(s) : 0;
	width = (precision > 0) ? list_flag.width - (ft_strlen(s) + precision) : list_flag.width - ft_strlen(s);
	if (width > 0)
	{
		if (list_flag.justify)
		{
			ret += ft_putstr(s, list_flag);
			ret += print_s_space(&width);
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
