/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 12:38:04 by jtsang            #+#    #+#             */
/*   Updated: 2019/12/15 14:36:17 by jtsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int		ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		d;
	char	c, *s;

	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%' && *(fmt + 1) == 's')
			s = va_arg(ap, char *);
		else if (*fmt == '%' && *(fmt + 1) == 'c')
			c = va_arg(ap, int);
		else if (*fmt == '%' && *(fmt + 1) == 'd')
			d = va_arg(ap, int);
		fmt++;
	}
	va_end(ap);
	return (1);
}

int		main()
{
	int		i = 42;
	char	str[15] = "Hello World !";
	ft_printf("Here we are %d, so %s", i, str);
	return (0);
}
