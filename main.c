/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 07:48:38 by jtsang            #+#    #+#             */
/*   Updated: 2019/12/21 17:25:37 by jtsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int		main(int ac, char **av)
{
	unsigned int	x;
	int		ret;

	x = 101010;
	ret = 0;
	ret = ft_printf("MY PRINTF : Here we are %d, %p %X %% %s", x, &ac, x, av[1]);
	printf("\nRETURN VALUE : %d\n", ret); 
	ret = printf("CP PRINTF : Here we are %d, %p %X %% %s", x, &ac, x, av[1]);
	printf("\nRETURN VALUE : %d", ret); 
	return (0); 
}
