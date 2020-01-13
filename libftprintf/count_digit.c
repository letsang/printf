/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:25:54 by jtsang            #+#    #+#             */
/*   Updated: 2019/11/12 16:56:00 by jtsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_digit(long nb, t_flag list_flag)
{
	int		nbr;
	int		count;

	nbr = nb;
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
	if (list_flag.pos && nb >= 0)
		count++;
	return (count);
}
