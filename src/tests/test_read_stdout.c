/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_read_stdout.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:00:37 by ade-verd          #+#    #+#             */
/*   Updated: 2018/01/12 11:26:41 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int		ft_redirect_stdout(void)
{
	int		fd;

	fd = dup(fileno(stdout));
	if (!(freopen("/tmp/out.txt", "a", stdout)))
	{
		printf("redirect_stdout() error\n");
		return (-1);
	}
	return (fd);
}

int		ft_restore_stdout(int fd)
{
	fflush(stdout);
	dup2(fd, fileno(stdout));
	if (close(fd) == -1)
	{
		printf("restore_stdout() error\n");
		return (-1);
	}
	return (1);
}

int		ft_read_fd(int fd, char **str, int buf_size)
{
	char	buf[buf_size + 1];
	int		ret;
	int		pos;

	if ((pos = lseek(fd, -(buf_size), SEEK_END)) < 0)
	{
		printf("lseek() error\npos = %d\n", pos);
		return (-1);
	}
	if ((ret = read(fd, buf, buf_size)) <= 0)
	{
		printf("read() error\n");
		return (-1);
	}
	buf[buf_size] = '\0';
	*str = ft_strjoin("", buf);
	return (1);
}

int		ft_open_read_close(int fd, char **my_print, int my_ret)
{
	if ((ft_restore_stdout(fd)) == -1)
		return (-1);
	if ((fd = open("/tmp/out.txt", O_RDONLY)) == -1)
	{
		printf("open() error\n");
		return (-1);
	}
	if ((ft_read_fd(fd, my_print, my_ret)) <= 0)
		return (-1);
	if ((close(fd)) == -1)
	{
		printf("close() error\n");
		return (-1);
	}
	return (1);
}
