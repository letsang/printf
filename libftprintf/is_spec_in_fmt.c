/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_spec_in_fmt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 11:09:38 by jtsang            #+#    #+#             */
/*   Updated: 2020/01/28 11:09:56 by jtsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_spec_in_fmt(const char *fmt)
{
	int				i;
	int				j;
	char			*spec;

	if (!fmt)
		return (0);
	i = 0;
	spec = ft_strdup("cspdiuxX%");
	while (fmt[i])
	{
		j = 0;
		while (spec[j])
		{
			if (spec[j] == fmt[i])
				return (1);
			j++;
		}
		i++;
	}
	if (spec)
		free(spec);
	return (0);
}
