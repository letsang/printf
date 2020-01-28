/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_spec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 11:08:57 by jtsang            #+#    #+#             */
/*   Updated: 2020/01/28 11:09:25 by jtsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_spec(char c)
{
	int				i;
	char			*spec;

	i = 0;
	spec = ft_strdup("cspdiuxX%");
	while (spec[i])
	{
		if (spec[i] == c)
			return (1);
		i++;
	}
	if (spec)
		free(spec);
	return (0);
}
