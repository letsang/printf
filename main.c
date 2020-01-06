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

	x = 42;
	ret = 0;
	ret = ft_printf("MY PRINTF : %s %d, %p %X %% %d", av[1], x, &ac, x, x);
	printf("\nRETURN VALUE : %d\n", ret); 
	ret = printf("CP PRINTF : %s %d, %p %X %% %d", av[1], x, &ac, x, x);
	printf("\nRETURN VALUE : %d", ret); 
	return (0); 
}
