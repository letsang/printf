/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xmaj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:54:01 by jtsang            #+#    #+#             */
/*   Updated: 2020/01/27 14:32:07 by jtsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnbr_hex_maj(unsigned long nb, t_flag list_flag)
{
	int				c;
	static int		ret;

	if (list_flag.dot && list_flag.precision == 0 && nb == 0)
		return (0);
	ret = 0;
	if (nb >= 16)
		ft_putnbr_hex_maj((nb / 16), list_flag);
	c = nb % 16 + (nb % 16 < 10 ? '0' : 'A' - 10);
	ret += ft_putchar(c);
	return (ret);
}

int		print_xmaj_precision(t_flag list_flag, unsigned long x, int precision)
{
	int				ret;

	ret = 0;
	if (list_flag.pos)
		ret += ft_putchar('+');
	while (precision > 0)
	{
		ret += ft_putchar('0');
		precision--;
	}
	ret += ft_putnbr_hex_maj(x, list_flag);
	return (ret);
}

int		print_xmaj_padding(t_flag *list_flag, int *width)
{
	int				ret;

	ret = 0;
	while (*width > 0)
	{
		if (list_flag->padding && *width && !list_flag->precision)
		{
			if (list_flag->pos)
			{
				ret += ft_putchar('+');
				list_flag->pos = 0;
			}
			ret += ft_putchar('0');
			(*width)--;
		}
		else
			ret += print_space(width);
	}
	return (ret);
}

int		print_xmaj_next(int width, int precision,
		unsigned long x, t_flag list_flag)
{
	int				ret;

	ret = 0;
	if (width > 0)
	{
		if (list_flag.justify)
		{
			ret += print_xmaj_precision(list_flag, x, precision);
			ret += print_space(&width);
		}
		else
		{
			ret += print_xmaj_padding(&list_flag, &width);
			ret += print_xmaj_precision(list_flag, x, precision);
		}
	}
	else
		ret += print_xmaj_precision(list_flag, x, precision);
	return (ret);
}

int		print_xmaj(va_list av, t_flag list_flag)
{
	int				ret;
	int				width;
	int				precision;
	unsigned long	x;

	ret = 0;
	x = va_arg(av, unsigned int);
	precision = (list_flag.precision) ?
			list_flag.precision - count_hex(x, list_flag) : 0;
	if (list_flag.precision && (list_flag.pos == 1))
		precision++;
	width = (precision > 0) ?
		list_flag.width - (count_hex(x, list_flag) + precision) :
		list_flag.width - (count_hex(x, list_flag));
	ret += print_xmaj_next(width, precision, x, list_flag);
	return (ret);
}
