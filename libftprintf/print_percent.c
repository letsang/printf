/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:55:00 by jtsang            #+#    #+#             */
/*   Updated: 2020/01/27 13:09:04 by jtsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_percent_padding(t_flag *list_flag, int *width)
{
	int		ret;

	ret = 0;
	while (*width > 0)
	{
		if (list_flag->padding && *width)
		{
			ret += ft_putchar('0');
			(*width)--;
		}
		else
			ret += print_space(width);
	}
	return (ret);
}

int		print_percent(va_list av, t_flag list_flag)
{
	int		ret;
	int		width;

	(void)av;
	ret = 0;
	width = list_flag.width - 1;
	if (width > 0)
	{
		if (list_flag.justify)
		{
			ret += ft_putchar('%');
			ret += print_space(&width);
		}
		else
		{
			ret += print_percent_padding(&list_flag, &width);
			ret += ft_putchar('%');
		}
	}
	else
		ret += ft_putchar('%');
	return (ret);
}
