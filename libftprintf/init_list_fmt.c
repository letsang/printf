/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list_fmt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 12:49:12 by jtsang            #+#    #+#             */
/*   Updated: 2020/01/28 12:49:20 by jtsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		init_list_fmt(t_format list_fmt[NB_FORMAT])
{
	list_fmt[CHAR].type = 'c';
	list_fmt[STR].type = 's';
	list_fmt[POINTER].type = 'p';
	list_fmt[INT_D].type = 'd';
	list_fmt[INT_I].type = 'i';
	list_fmt[UN].type = 'u';
	list_fmt[HEX_MIN].type = 'x';
	list_fmt[HEX_MAJ].type = 'X';
	list_fmt[NO_FORMAT].type = '%';
	list_fmt[CHAR].f = print_c;
	list_fmt[STR].f = print_s;
	list_fmt[POINTER].f = print_p;
	list_fmt[INT_D].f = print_di;
	list_fmt[INT_I].f = print_di;
	list_fmt[UN].f = print_u;
	list_fmt[HEX_MIN].f = print_xmin;
	list_fmt[HEX_MAJ].f = print_xmaj;
	list_fmt[NO_FORMAT].f = print_percent;
}
