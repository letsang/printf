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
	int		n;
	int		ret;

	n = -94400;
	ret = 0;
	ret = ft_printf("MY PRINTF : %s %015d, %p %X %% %d", av[1], n, &ac, n, n);
	printf("\nRETURN VALUE : %d\n", ret); 
	ret = printf("CP PRINTF : %s %015d, %p %X %% %d", av[1], n, &ac, n, n);
	printf("\nRETURN VALUE : %d\n\n", ret);

	ret = ft_printf("MY PRINTF : %s %-015d, %p %X %% %d", av[1], n, &ac, n, n);
	printf("\nRETURN VALUE : %d\n", ret); 
	ret = printf("CP PRINTF : %s %-015d, %p %X %% %d", av[1], n, &ac, n, n);
	printf("\nRETURN VALUE : %d\n\n", ret);

	ret = ft_printf("MY PRINTF : %s %-15d, %p %X %% %d", av[1], n, &ac, n, n);
	printf("\nRETURN VALUE : %d\n", ret); 
	ret = printf("CP PRINTF : %s %-15d, %p %X %% %d", av[1], n, &ac, n, n);
	printf("\nRETURN VALUE : %d\n\n", ret);

	ret = ft_printf("MY PRINTF : %s %15d, %p %X %% %d", av[1], n, &ac, n, n);
	printf("\nRETURN VALUE : %d\n", ret); 
	ret = printf("CP PRINTF : %s %15d, %p %X %% %d", av[1], n, &ac, n, n);
	printf("\nRETURN VALUE : %d\n\n", ret);
	return (0); 
}
