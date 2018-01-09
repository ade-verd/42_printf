/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 14:14:31 by ade-verd          #+#    #+#             */
/*   Updated: 2018/01/09 18:57:38 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

/*BUFFER TEST
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
}*/

/*GET FLAGS TEST
void	ft_init_indic(t_indic **ind);
void	ft_free_indic(t_indic **ind);

int		main(void)
{
	int		*i;
	t_indic	*ind;
	char	*str;

	i = (int*)malloc(sizeof(int));
	*i = 1;
	str = "%#+-0 30d\n";
	ft_init_indic(&ind);
	ft_get_flags(&ind, str, i);
	if (ind->flags)
		printf("Flags:\t|%s|\n", ind->flags);
	ft_free_indic(&ind);
	return(0);
}*/


int		main(void)
{
	printf("%%d\t|%d|\n", 153);
	printf("%%-30d\t|%-30d|\n", 153);
	printf("%%+30d\t|%+30d|\n", 153);
	printf("%%+*2d\tfonctionne pas\n");
	printf("%%+*2$d\t|%*2$d|\n", 153, 10);
	printf("%%+*d\t|%+*d|\n", 153, 10);
	return (0);
}
