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
#include <string.h>

typedef enum {
	false, true
} bool;

typedef enum {
	INT = 0, FLOAT, CHAR, STR, NB_FORMATS, NO_FORMAT
} FORMATS_TOKEN;

typedef struct s_Format {
	char			token;
	int				(*f)(va_list av);
	FORMATS_TOKEN	next_format;
}Format;

void	formatCmp(va_list av, char c);
void	cprintf(char *str, ...);
int		affStr(va_list av);
int		affCh(va_list av);
int		affInt(va_list av);

#endif
