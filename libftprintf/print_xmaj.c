/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xmaj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:54:01 by jtsang            #+#    #+#             */
/*   Updated: 2020/01/09 12:08:40 by jtsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnbr_hex_maj(unsigned long nb)
{
	int				c;
	static int		ret;

	ret = 0;
	if (nb >= 16)
		ft_putnbr_hex_maj(nb / 16);
	c = nb % 16 + (nb % 16 < 10 ? '0' : 'A' - 10);
	ret += ft_putchar(c);
	return (ret);
}

int		print_xmaj(va_list av)
{
	unsigned long	x;

	x = va_arg(av, unsigned int);
	return (ft_putnbr_hex_maj(x));
}
