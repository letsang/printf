/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xmin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:53:01 by jtsang            #+#    #+#             */
/*   Updated: 2020/01/09 12:14:01 by jtsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_xmin(va_list av)
{
	unsigned long	x;

	x = va_arg(av, unsigned int);
	return (ft_putnbr_hex_min(x));
}
