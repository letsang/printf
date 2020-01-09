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

int		ft_putnbr_un(unsigned int n)
{
	static int		ret;

	ret = 0;
	if (n > 9)
		ft_putnbr_un(n / 10);
	ret += ft_putchar(n % 10 + 48);
	return (ret);
}

int		print_u(va_list av)
{
	int				n;

	n = va_arg(av, unsigned int);
	return (ft_putnbr_un(n));
}
