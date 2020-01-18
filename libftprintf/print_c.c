/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:47:32 by jtsang            #+#    #+#             */
/*   Updated: 2020/01/09 12:07:37 by jtsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_c_space(int *width)
{
	int		ret;

	ret = 0;
	while (*width > 0)
	{
		ret += ft_putchar(' ');
		(*width)--;
	}
	return (ret);
}

int		print_c(va_list av, t_flag list_flag)
{
	int			ret;
	int			width;
	char			c;

	ret = 0;
	c = va_arg(av, int);
	width = list_flag.width - 1;
	if (width > 0)
	{
		if (list_flag.justify)
		{
			ret += ft_putchar(c);
			ret += print_c_space(&width);
		}
		else
			ret += ft_putchar(c);
	}	
	else
		ret += ft_putchar(c);
	return (ret);
}
