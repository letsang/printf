/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:50:31 by jtsang            #+#    #+#             */
/*   Updated: 2020/01/09 12:08:29 by jtsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnbr_un(unsigned int n, t_flag list_flag)
{
	static int		ret;

	ret = 0;
	if (list_flag.dot && list_flag.precision == 0 && n == 0)
		return (0);
	if (n > 9)
		ft_putnbr_un((n / 10), list_flag);
	ret += ft_putchar(n % 10 + 48);
	return (ret);
}

int		print_u_precision(t_flag list_flag, int *n, int precision)
{
	int 		ret;

	ret = 0;
	if (list_flag.pos && (*n >= 0))
		ret += ft_putchar('+');
	while (precision > 0)
	{
		if (*n < 0)
		{
			ret += ft_putchar('-');
			*n *= -1;
		}
		ret += ft_putchar('0');
		precision--;
	}
	return (ret);
}

int		print_u_space(int *width)
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

int		print_u_padding(t_flag *list_flag, int *n, int *width)
{
	int		ret;

	ret = 0;
	while (*width > 0)
	{
		if (list_flag->padding && *width && !list_flag->precision)
		{
			if (*n < 0)
			{
				ret += ft_putchar('-');
				*n *= -1;
			}
			else if (list_flag->pos && (*n >= 0))
			{
				ret += ft_putchar('+');
				list_flag->pos = 0;
			}
			ret += ft_putchar('0');
			(*width)--;
		}
		else
			ret += print_u_space(width);
	}
	return (ret);
}


int		print_u(va_list av, t_flag list_flag)
{
	int				ret;
	int				width;
	int				precision;
	int				n;

	ret = 0;
	n = va_arg(av, unsigned int);
	precision = (list_flag.precision) ?
			list_flag.precision - count_digit(n, list_flag) : 0;
	if (list_flag.precision && (list_flag.pos == 1 || n < 0))
		precision++;
	width = (precision > 0) ? list_flag.width - (count_digit(n, list_flag) + precision) : list_flag.width - (count_digit(n, list_flag));
	if (width > 0)
	{
		if (list_flag.justify)
		{
			ret += print_u_precision(list_flag, &n, precision);
			ret += ft_putnbr_un(n, list_flag);
			ret += print_u_space(&width);
		}
		else
		{
			ret += print_u_padding(&list_flag, &n, &width);
			ret += print_u_precision(list_flag, &n, precision);
			ret += ft_putnbr_un(n, list_flag);
		}
	}	
	else
	{
		ret += print_u_precision(list_flag, &n, precision);
		ret += ft_putnbr_un(n, list_flag);
	}
	return (ret);
}
