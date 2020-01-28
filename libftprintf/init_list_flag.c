/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 12:49:29 by jtsang            #+#    #+#             */
/*   Updated: 2020/01/28 12:49:53 by jtsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag		init_list_flag(void)
{
	t_flag			list_flag;

	list_flag.justify = 0;
	list_flag.padding = 0;
	list_flag.width = 0;
	list_flag.dot = 0;
	list_flag.precision = 0;
	list_flag.pos = 0;
	return (list_flag);
}
