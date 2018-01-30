/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:51:33 by ade-verd          #+#    #+#             */
/*   Updated: 2018/01/30 15:17:39 by ade-verd         ###   ########.fr       */
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
	printf(" -h\thelp\n");
	printf("Avalaibable types:\n");
	while (g_test[i].letter)
	{
		printf(" %s\t%s\n", g_test[i].letter, g_test[i].designation);
		i++;
	}
	printf("\nDisplay code:\n");
	printf(" --%s\t%s\n", "errors", "Displays only errors");
}


int		main(int ac, char **av)
{
	int		i;

	i = 1;
	g_display_code = ALL;
	if (ac == 1)
		ft_run_all();
	else if (ac == 2 || ac == 3)
	{
		if (av[2] && strcmp(av[2], "--errors") == 0)
			g_display_code = ERR_ONLY;
		if (strcmp(av[1], "-h") == 0 || (ft_choose_flag(av[i])) == -10)
		{
			fprintf(stderr, "Usage: ./test [conversion letter(s)] [Display code]\n");
			ft_available_types();
		}
	}
	else
		fprintf(stderr, "Usage: ./test [conversion letter(s)] [Display code]\n");
	return (0);
}
