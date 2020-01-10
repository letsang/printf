/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:00:07 by jtsang            #+#    #+#             */
/*   Updated: 2020/01/09 17:03:36 by jtsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#		ifndef FT_PRINTF_H
#		define FT_PRINTF_H

#		include <stdlib.h>
#		include <stdarg.h>
#		include <unistd.h>

typedef enum {
	CHAR, STR, POINTER, INT_D, INT_I, UN,
	HEX_MIN, HEX_MAJ, NO_FORMAT, END, NB_FORMAT
}	t_type;

typedef struct	s_flag {
	int			justify;
	int			padding;
	int			width;
	int			precision;
}				t_flag;

typedef struct	s_format {
	char			type;
	int			(*f)(va_list av, t_flag list_flag);
}				t_format;

int				ft_putchar(int c);
int				ft_putnbr_hex_min(unsigned long nb);
int				ft_atoi(const char *str);
int				count_digit(long nb);
int				check_fmt(va_list av, t_flag list_flag, const char *fmt);
int				ft_printf(const char *fmt, ...);
int				print_s(va_list av, t_flag list_flag);
int				print_c(va_list av, t_flag list_flag);
int				print_di(va_list av, t_flag list_flag);
int				print_u(va_list av, t_flag list_flag);
int				print_p(va_list av, t_flag list_flag);
int				print_xmin(va_list av, t_flag list_flag);
int				print_xmaj(va_list av, t_flag list_flag);
int				print_percent(va_list av, t_flag list_flag);

#		endif
