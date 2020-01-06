/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:09:09 by jtsang            #+#    #+#             */
/*   Updated: 2019/12/21 17:10:28 by jtsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PRINTF_H
#define FT_PRINTF_H
#include <stdlib.h>
#include <stdarg.h>

typedef enum {
	CHAR, STR, POINTER, INT_D, INT_I, UN, HEX_MIN, HEX_MAJ, NO_FORMAT, END, NB_FORMAT
} type_list;

typedef struct s_Format {
	char		type;
	int		(*f)(va_list av);
}Format;

int	check_fmt(va_list av, char c);
int	ft_printf(const char *fmt, ...);
int	print_s(va_list av);
int	print_c(va_list av);
int	print_di(va_list av);
int	print_u(va_list av);
int	print_p(va_list av);
int	print_xmin(va_list av);
int	print_xmaj(va_list av);
int	print_percent(va_list av);

#endif
