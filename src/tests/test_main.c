/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:51:33 by ade-verd          #+#    #+#             */
/*   Updated: 2018/01/29 14:55:49 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int		ft_run_all(void)
{
	int		i;

	i = 0;
	while (g_test[i].letter)
	{
		STOPIF0(g_test[i].f());
		i++;
	}
	return (1);
}

int		ft_choose_flag(char *str)
{
	int		ret;
	int		i;
	int		j;

	ret = -10;
	i = 0;
	while (g_test[i].letter)
	{
		j = 0;
		while (str[j])
		{
			if (ft_strchr(g_test[i].letter, str[j]))
				STOPIF0(ret = g_test[i].f());
			j++;
		}
		i++;
	}
	return (ret);
}

void	ft_available_types(void)
{
	int		i;

	i = 0;
	printf("Avalaibable types: ");
	while (g_test[i].letter)
	{
		printf("%s", g_test[i].letter);
		i++;
	}
	printf("\n");
}

int		main(int ac, char **av)
{
	if (ac == 1)
		ft_run_all();
	else if (ac == 2)
	{
		if (strcmp(av[1], "-h") == 0 || strcmp(av[1], "--help") == 0
				|| (ft_choose_flag(av[1])) == -10)
		{
			fprintf(stderr, "Usage: ./test [conversion letter(s)]\n");
			ft_available_types();
		}
	}
	else
	{
		fprintf(stderr, "Usage: ./test [conversion letter(s)]\n");
	}
	return (0);
}
