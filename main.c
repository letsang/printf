/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 07:48:38 by jtsang            #+#    #+#             */
/*   Updated: 2020/01/09 11:14:44 by jtsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <string.h>

int		main(int ac, char **av)
{
	int		n;
	int		ret;

	n = 42;
	ret = 0;
	ret = ft_printf("MY_PRINTF : %5p", NULL);
	printf("\nRETURN VALUE : %d\n\n", ret);
	ret = printf("CP_PRINTF : %5p", NULL);
	printf("\nRETURN VALUE : %d\n\n", ret);
	return (0); 
}
