/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 14:14:31 by ade-verd          #+#    #+#             */
/*   Updated: 2018/01/10 18:57:35 by ade-verd         ###   ########.fr       */
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
void	ft_init_indic(t_indic **ind);
void	ft_free_indic(t_indic **ind);

int		main(void)
{
	char	*str;

	str = "%#+-0 123156156.4d";
	printf("str: |%s|\n", str);
	ft_printf(str, 10);

	str = "%#+-0 *d";
	printf("str: |%s|\n", str);
	ft_printf(str, 10, 1531);

	str = "%#+-0 *.4d";
	printf("str: |%s|\n", str);
	ft_printf(str, 10, 21561);

	str = "%#+-0 *.4hd";
	printf("str: |%s|\n", str);
	ft_printf(str, 10, 321561);

	str = "%#+-0 *.4hhD";
	printf("str: |%s|\n", str);
	ft_printf(str, 10, 1321561);

	str = "%#+-0 *.4lu";
	printf("str: |%s|\n", str);
	ft_printf(str, 10, 321561);

	str = "%#+-0 *.4llU";
	printf("str: |%s|\n", str);
	ft_printf(str, 10, 21561);

	str = "%#+-0 *.4jC";
	printf("str: |%s|\n", str);
	ft_printf(str, 10, 1561);

	str = "%#+-0 *.4zp";
	printf("str: |%s|\n", str);
	ft_printf(str, 10, 561);

	str = "%#+-0 *.4zP";
	printf("str: |%s|\n", str);
	ft_printf(str, 10);

	return(0);
}

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
	return (0);
}
*/
