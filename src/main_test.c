/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 14:14:31 by ade-verd          #+#    #+#             */
/*   Updated: 2018/01/08 15:51:05 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

/*BUFFER TEST*/
int		main(int ac, char **av)
{
	int		i;
	t_buff	*buff;

	i = 0;
	ft_init_buffer(&buff);
	if (ac == 2)
	{
		while (av[1][i])
		{
			ft_putbuffer(&buff, av[1][i], 1);
			i++;
		}
		ft_print_buffer(&buff, 1);
		printf("\nret = %d\n", buff->total);
	}
	return(ac);
}
