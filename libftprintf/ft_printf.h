/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:00:07 by jtsang            #+#    #+#             */
/*   Updated: 2020/01/28 14:18:11 by jtsang           ###   ########.fr       */
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
	int			dot;
	int			precision;
	int			pos;
}				t_flag;

typedef struct	s_format {
	char			type;
	int				(*f)(va_list av, t_flag list_flag);
}				t_format;

void			init_list_fmt(t_format list_fmt[NB_FORMAT]);
t_flag			init_list_flag(void);
char			*ft_strdup(const char *s1);
int				ft_strlen(const char *s);
int				ft_putchar(int c);
int				ft_atoi(const char *str);
int				is_spec(char c);
int				is_spec_in_fmt(const char *fmt);
int				count_digit(long nb, t_flag list_flag);
int				count_hex(unsigned long nb, t_flag list_flag);
int				check_fmt(va_list av, t_flag list_flag, const char *fmt);
int				convert_print(const char *fmt, va_list av);
int				ft_printf(const char *fmt, ...);
int				print_space(int *width);
int				print_s(va_list av, t_flag list_flag);
int				print_c(va_list av, t_flag list_flag);
int				print_di(va_list av, t_flag list_flag);
int				print_u(va_list av, t_flag list_flag);
int				print_p(va_list av, t_flag list_flag);
int				print_xmin(va_list av, t_flag list_flag);
int				print_xmaj(va_list av, t_flag list_flag);
int				print_percent(va_list av, t_flag list_flag);

#		endif
