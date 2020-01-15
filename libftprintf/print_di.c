/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:49:35 by jtsang            #+#    #+#             */
/*   Updated: 2020/01/09 12:07:50 by jtsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnbr(int n)
{
	static int	ret;
	unsigned int	nbr;

	ret = 0;
	nbr = n;
	if (n < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	ret += ft_putchar(nbr % 10 + 48);
	return (n < 0) ? ret + 1 : ret;
}

int		print_di_precision(t_flag list_flag, int *n, int precision)
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

int		print_di_space(int *width)
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

int		print_di_padding(t_flag *list_flag, int *n, int *width)
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
			ret += print_di_space(width);
	}
	return (ret);
}

int		print_di(va_list av, t_flag list_flag)
{
	int				ret;
	int				n;
	int				width;
	int				precision;

	ret = 0;
	n = va_arg(av, int);
	precision = (list_flag.precision) ?
			list_flag.precision - count_digit(n, list_flag) : 0;
	if (list_flag.precision && (list_flag.pos == 1 || n < 0))
		precision++;
	width = (precision > 0) ? list_flag.width - (count_digit(n, list_flag) + precision) : list_flag.width - (count_digit(n, list_flag));
	if (width > 0)
	{
		if (list_flag.justify)
		{
			ret += print_di_precision(list_flag, &n, precision);
			ret += ft_putnbr(n);
			ret += print_di_space(&width);
		}
		else
		{
			ret += print_di_padding(&list_flag, &n, &width);
			ret += print_di_precision(list_flag, &n, precision);
			ret += ft_putnbr(n);
		}
	}	
	else
	{
		ret += print_di_precision(list_flag, &n, precision);
		ret += ft_putnbr(n);
	}
	return (ret);
}
