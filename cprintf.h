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

#ifndef	CPRINTF_H
#define CPRINTF_H
#include <stdlib.h>
#include <stdarg.h>

typedef enum {
	CHAR, STR, POINTER, INT_D, INT_I, INT_U, HEX_MIN, HEX_MAJ, NO_FORMAT, END, NB_FORMAT
} type_list;

typedef struct s_Format {
	char		type;
	int		(*f)(va_list av);
}Format;

void	check_fmt(va_list av, char c);
void	ft_printf(const char *fmt, ...);
int		print_s(va_list av);
int		print_c(va_list av);
int		print_d(va_list av);
int		print_no_fmt(va_list av);

#endif
