/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 09:52:08 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/16 12:39:44 by ade-verd         ###   ########.fr       */
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
	printf(" --%s\t%s\n", "all  ", "Displays all details until the first error");
	printf(" --%s\t%s\n", "light", "Displays a check when the test is good otherwise error's details");
	printf(" --%s\t%s\n", "errors", "Displays only errors");
}


int		main(int ac, char **av)
{
	setlocale(LC_ALL, "en_US.UTF-8");
	int 	i;
	int 	explicit;

	i = ac;
	while (i > 1 && explicit != 1)
	{
		i--;
		g_display_code = !g_display_code && strcmp(av[i], "--all") == 0 
						? ALL : g_display_code;
		g_display_code = !g_display_code && strcmp(av[i], "--errors") == 0
						? ERR_ONLY : g_display_code;
		g_display_code = !g_display_code && strcmp(av[i], "--light") == 0
						? LIGHT : g_display_code;
		explicit = g_display_code ? 1 : 0;
	}
	g_display_code = explicit != 1 ? ALL : g_display_code;
	if (ac == 1 || (ac == 2 && explicit == 1))
		ft_run_all();
	else if (ac == 2 || ac == 3)
	{
		if (strcmp(av[1], "-h") == 0 || (ft_choose_flag(av[1])) == -10)
		{
			fprintf(stderr, "Usage: ./test [conversion letter(s)] [Display code]\n");
			ft_available_types();
		}
	}
	else
		fprintf(stderr, "Usage: ./test [conversion letter(s)] [Display code]\n");
	return (0);
}
