/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 14:14:31 by ade-verd          #+#    #+#             */
/*   Updated: 2018/01/11 13:13:03 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

/*GET FLAGS TEST*/
///*
int		main(void)
{
	char	*str;

	str = "Le nombre est %#+-0 123.4d !\n";
//	printf("str: |%s|\n", str);
	ft_printf(str, 10);

	str = "Le nombre est %#+-0 *d !\n";
//	printf("str: |%s|\n", str);
	ft_printf(str, 10, 1531);

	str = "Le nombre est %#+-0 *.4d !\n";
//	printf("str: |%s|\n", str);
	ft_printf(str, 10, 21561);

	str = "Le nombre est %#+-0 *.4hd !\n";
//	printf("str: |%s|\n", str);
	ft_printf(str, 10, 321561);

	str = "Le nombre est %#+-0 *.4hhD !\n";
//	printf("str: |%s|\n", str);
	ft_printf(str, 10, 1321561);

	str = "Le nombre est %#+-0 *.4lu !\n";
//	printf("str: |%s|\n", str);
	ft_printf(str, 10, 321561);

	str = "Le nombre est %#+-0 *.4llU !\n";
//	printf("str: |%s|\n", str);
	ft_printf(str, 10, 21561);

	str = "Le nombre est %#+-0 *.4jC !\n";
//	printf("str: |%s|\n", str);
	ft_printf(str, 10, 1561);

	str = "Le nombre est %#+-0 *.4zp !\n";
//	printf("str: |%s|\n", str);
	ft_printf(str, 10, 561);

	return(0);
}
//*/
/*Some tests*/
/*
int		main(void)
{
	printf("%%d, 153\t|%d|\n", 153);
	printf("%%-30d, 153\t|%-30d|\n", 153);
	printf("%%+30d, 153\t|%+30d|\n", 153);
	printf("%%+*d, 10, 30\t|%+*d|\n", 10, 30);
	printf("%%*d, 30, 10\t|%*d|\n", 30, 10);
	printf("%%+*2d\tfonctionne pas\n");
//	printf("%%2$d\t|%+*2$d|\n", 30, 10);
	printf("Parameter list without reordering: %s %s %s %s\n","first", "second", "third", "fourth");
	printf("Parameter list after reordering: %4$s %3$s %2$s %1$s\n", "first", "second", "third", "fourth");
	return (0);
}
*/
