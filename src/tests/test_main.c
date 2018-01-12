/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:51:33 by ade-verd          #+#    #+#             */
/*   Updated: 2018/01/12 14:07:25 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int		ft_run_all(void)
{
	STOPIF0(ft_test_flag_d());
	return (1);
}

int		ft_choose_flag(char *str)
{
	int		ret;

	ret = -10;
	if (ft_strchr(str, 'd'))
		ret = ft_test_flag_d();
	return (ret);
}

int		main(int ac, char **av)
{
	if (ac == 1)
		ft_run_all();
	else if (ac == 2)
	{
		if ((ft_choose_flag(av[1])) == -10)
			fprintf(stderr, "Usage: ./test [conversion letter(s)]\n");
	}
	else
	{
		fprintf(stderr, "Usage: ./test [conversion letter(s)]\n");
	}
	return (0);
}
