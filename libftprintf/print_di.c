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
	static int		ret;
	unsigned int	nbr;

	nbr = n;
	ret = 0;
	if (n < 0)
	{
		ret = ft_putchar('-');
		nbr *= -1;
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	ret += ft_putchar(nbr % 10 + 48);
	return (ret);
}

int		print_di(va_list av)
{
	int				n;

	n = va_arg(av, int);
	return (ft_putnbr(n));
}
