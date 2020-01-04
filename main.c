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

#include "cprintf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int		main(int ac, char **av)
{
	int x;

	x = 2147483647;
	ft_printf("MY PRINTF : Here we are %d, %p %X %% %s", ac, &ac, x, av[1]);
	printf("\nCP PRINTF : Here we are %d, %p %X %% %s", ac, &ac, x, av[1]);
	return (0); 
}
