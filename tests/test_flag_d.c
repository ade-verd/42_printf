/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_flag_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 13:09:43 by ade-verd          #+#    #+#             */
/*   Updated: 2017/12/20 13:27:25 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int		ft_redirect_stdout(void)
{
	int		fd;

	fd = dup(fileno(stdout));
	if (!(freopen("out.txt", "a", stdout)))
	{
		printf("redirect_stdout() error\n");
		return (-1);
	}
	return (fd);
}

int		ft_restore_stdout(int fd)
{
	dup2(fd, fileno(stdout));
	if (close(fd) == -1)
	{
		printf("restore_stdout() error\n");
		return (-1);
	}
	return (1);
}

int		test_flag_d(int nb)
{
	int		fd;
	int		my_ret;
	int		off_ret;
	char	*my_print;
	char	*off_print;
	char	trash[100];

	if ((fd = ft_redirect_stdout()) == -1)
		return (-1);
	my_ret = printf("Mine : %d\n", nb);
	fflush(stdout);
	if ((ft_restore_stdout(fd)) == -1)
		return (-1);
	if ((fd = open("out.txt", O_RDONLY)) == -1)
	{
		printf("open() error\n");
		return (-1);
	}
	if ((ft_read_stdout(fd, &my_print, my_ret)) <= 0)
		return (-1);
	close(fd);

	off_ret = sprintf(trash, "Off  : %d\n", nb);
	off_print = ft_strnew(off_ret);
	sprintf(off_print, "Off  : %d\n", nb);

	printf("my_print  : %soff_print : %s", my_print, off_print);

	printf("\033[036m%s(%d)\033[0m\t", __func__, nb);
	ft_compare(my_ret, off_ret, my_print + 6, off_print + 6);

	ft_memdel((void**)&my_print);
	ft_memdel((void**)&off_print);
	return (1);
}
