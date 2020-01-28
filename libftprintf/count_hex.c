/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 12:11:33 by jtsang            #+#    #+#             */
/*   Updated: 2020/01/09 12:11:53 by jtsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		count_hex(unsigned long nb, t_flag list_flag)
{
	int			count;

	if (list_flag.dot && list_flag.precision == 0 && nb == 0)
		return (0);
	count = 1;
	while (nb >= 16)
	{
		nb = nb / 16;
		count++;
	}
	return (count);
}
