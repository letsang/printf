/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:46:10 by jtsang            #+#    #+#             */
/*   Updated: 2020/01/09 12:08:18 by jtsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putstr(const char *s)
{
	int				ret;
	int				i;

	ret = 0;
	if (!s)
		ret += write(1, "(null)", 6);
	if (s)
	{
		i = 0;
		while (s[i])
		{
			ret += write(1, &s[i], 1);
			i++;
		}
	}
	return (ret);
}

int		print_s(va_list av)
{
	char			*s;

	s = va_arg(av, char *);
	return (ft_putstr(s));
}
