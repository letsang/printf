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

int		ft_putnbr_hex_min(unsigned long nb, t_flag list_flag)
{
	int				c;
	static int		ret;

	if (list_flag.dot && list_flag.precision == 0 && nb == 0)
		return (0);
	ret = 0;
	if (nb >= 16)
		ft_putnbr_hex_min((nb / 16), list_flag);
	c = nb % 16 + (nb % 16 < 10 ? '0' : 'a' - 10);
	ret += ft_putchar(c);
	return (ret);
}
