/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:25:54 by jtsang            #+#    #+#             */
/*   Updated: 2020/01/27 10:59:33 by jtsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_digit(long nb, t_flag list_flag)
{
	long	nbr;
	int		count;

	nbr = nb;
	if (list_flag.dot && list_flag.precision == 0 && nb == 0)
		return (0);
	count = 1;
	if (nb < 0)
	{
		nbr = -nb;
		count++;
	}
	while (nbr >= 10)
	{
		nbr = nbr / 10;
		count++;
	}
	if (list_flag.pos && (nb >= 0))
		count++;
	return (count);
}
