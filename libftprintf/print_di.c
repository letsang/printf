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

int		print_di(va_list av, t_flag list_flag)
{
	int				ret;
	int				n;
	int				diff;

	ret = 0;
	n = va_arg(av, int);
	diff = list_flag.width - count_digit(n);
	if (diff > 0)
	{
		if (list_flag.justify)
		{
			ret += ft_putnbr(n);
			while (diff)
			{
				ret += ft_putchar(' ');
				diff--;
			}
		}
		else
		{
			while (diff)
			{
				ret += ft_putchar(' ');
				diff--;
			}
			ret += ft_putnbr(n);
		}
	}	
	else
		ret += ft_putnbr(n);
	return (ret);
}
