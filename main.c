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

int		main(int ac, char **av)
{
	unsigned int	x;
	int		ret;

	x = 42424242;
	ret = 0;
	ret = ft_printf("MY PRINTF : %s %d, %p %X %% %d", av[1], x, &ac, x, x);
	printf("\nRETURN VALUE : %d\n", ret); 
	ret = printf("CP PRINTF : %s %d, %p %X %% %d", av[1], x, &ac, x, x);
	printf("\nRETURN VALUE : %d", ret); 
	return (0); 
}
