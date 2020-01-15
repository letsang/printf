/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:52:01 by jtsang            #+#    #+#             */
/*   Updated: 2020/01/09 12:13:47 by jtsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_p_precision(int precision)
{
	int 		ret;

	ret = 0;
	while (precision > 0)
	{
		ret += ft_putchar('0');
		precision--;
	}
	return (ret);
}

int		print_p_space(int *width)
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

int		print_p_padding(t_flag *list_flag, int *width)
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
			ret += print_p_space(width);
	}
	return (ret);
}


int		print_p(va_list av, t_flag list_flag)
{
	void			*p;
	int			width;
	int			precision;
	int			ret;

	ret = 0;
	p = va_arg(av, void *);
	precision = (list_flag.precision) ?
			list_flag.precision - count_hex((unsigned long)p) : 0;
	width = list_flag.width - (count_hex((unsigned long)p) + 2);
	if (width > 0)
	{
		if (list_flag.justify)
		{
			ret += print_p_precision(precision);
			ret = ft_putchar('0');
			ret += ft_putchar('x');
			ret += ft_putnbr_hex_min((unsigned long)p);
			ret += print_p_space(&width);
		}
		else
		{
			ret += print_p_padding(&list_flag, &width);
			ret += print_p_precision(precision);
			ret = ft_putchar('0');
			ret += ft_putchar('x');
			ret += ft_putnbr_hex_min((unsigned long)p);
		}
	}	
	else
	{
		ret += print_p_precision(precision);
		ret = ft_putchar('0');
		ret += ft_putchar('x');
		ret += ft_putnbr_hex_min((unsigned long)p);
	}
	return (ret);
}
