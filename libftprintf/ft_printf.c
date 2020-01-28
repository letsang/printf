/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 10:51:00 by jtsang            #+#    #+#             */
/*   Updated: 2020/01/28 14:22:13 by jtsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *fmt, ...)
{
	va_list			av;
	int				ret;

	ret = 0;
	if (!fmt)
		return (0);
	va_start(av, fmt);
	ret += convert_print(fmt, av);
	va_end(av);
	return (ret);
}
