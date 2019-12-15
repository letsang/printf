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
	va_list			ap;
	char			c, *s;
	int				*p, d, i, x;
	unsigned int	u;

	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%' && *(fmt + 1) == 'c')
		{
			c = (int)va_arg(ap, int);
			write(1, &c, 1);
		}
		else if (*fmt == '%' && *(fmt + 1) == 's')
		{
			s = va_arg(ap, char *);
			ft_putstr(s);
		}
		else if (*fmt == '%' && *(fmt + 1) == 'p')
			p = va_arg(ap, int	*);
		else if (*fmt == '%' && *(fmt + 1) == 'd')
		{
			d = va_arg(ap, int);
			ft_putnbr(d);
		}
		else if (*fmt == '%' && *(fmt + 1) == 'i')
			i = va_arg(ap, int);
		else if (*fmt == '%' && *(fmt + 1) == 'u')
			u = va_arg(ap, unsigned int);
		else if (*fmt == '%' && (*(fmt + 1) == 'x' || *(fmt + 1) == 'X'))
			x = va_arg(ap, int);
		else if (*fmt == '%' && *(fmt + 1) == '%')
			write(1, "%", 1);
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
