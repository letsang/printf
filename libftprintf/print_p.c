/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:52:01 by jtsang            #+#    #+#             */
/*   Updated: 2020/01/27 14:54:08 by jtsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putadress(unsigned long nb, t_flag list_flag)
{
	int				c;
	static int		ret;

	if (list_flag.dot && list_flag.precision == 0 && nb == 0)
		return (0);
	ret = 0;
	if (nb >= 16)
		ft_putadress((nb / 16), list_flag);
	c = nb % 16 + (nb % 16 < 10 ? '0' : 'a' - 10);
	ret += ft_putchar(c);
	return (ret);
}

int		print_p_precision(unsigned long p, int precision, t_flag list_flag)
{
	int			ret;

	ret = 0;
	ret += ft_putchar('0');
	ret += ft_putchar('x');
	while (precision > 0)
	{
		ret += ft_putchar('0');
		precision--;
	}
	ret += ft_putadress(p, list_flag);
	return (ret);
}

int		print_p_padding(t_flag *list_flag, int *width)
{
	int			ret;

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

int		print_p_next(int width, int precision,
		unsigned long p, t_flag list_flag)
{
	int			ret;

	ret = 0;
	if (width > 0)
	{
		if (list_flag.justify)
		{
			ret += print_p_precision(p, precision, list_flag);
			ret += print_space(&width);
		}
		else
		{
			ret += print_p_padding(&list_flag, &width);
			ret += print_p_precision(p, precision, list_flag);
		}
	}
	else
		ret += print_p_precision(p, precision, list_flag);
	return (ret);
}

int		print_p(va_list av, t_flag list_flag)
{
	void		*p;
	int			width;
	int			precision;
	int			ret;

	ret = 0;
	p = va_arg(av, void *);
	precision = (list_flag.precision) ?
			list_flag.precision - count_hex((unsigned long)p, list_flag) : 0;
	width = list_flag.width - (count_hex((unsigned long)p, list_flag) + 2);
	ret += print_p_next(width, precision, (unsigned long)p, list_flag);
	return (ret);
}
