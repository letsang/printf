/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_min.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 12:11:33 by jtsang            #+#    #+#             */
/*   Updated: 2020/01/09 12:11:53 by jtsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnbr_hex_min(unsigned long nb)
{
	int				c;
	static int		ret;

	ret = 0;
	if (nb >= 16)
		ft_putnbr_hex_min(nb / 16);
	c = nb % 16 + (nb % 16 < 10 ? '0' : 'a' - 10);
	ret += ft_putchar(c);
	return (ret);
}
