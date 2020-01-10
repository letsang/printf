/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:52:01 by jtsang            #+#    #+#             */
/*   Updated: 2020/01/09 12:13:47 by jtsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_p(va_list av, t_flag list_flag)
{
	void			*p;
	int				ret;

	(void)list_flag;
	ret = 0;
	p = va_arg(av, void *);
	ret = ft_putchar('0');
	ret += ft_putchar('x');
	ret += ft_putnbr_hex_min((unsigned long)p);
	return (ret);
}
