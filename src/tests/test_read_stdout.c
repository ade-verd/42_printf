/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_read_stdout.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:00:37 by ade-verd          #+#    #+#             */
/*   Updated: 2018/01/12 15:20:33 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int		ft_open(char *path, int oflag)
{
	int		fd;

	if ((fd = open(path, oflag)) == -1)
	{
		printf("open() error\n");
		return (-1);
	}
	return (fd);
}

int		ft_close(int fd)
{
	if ((close(fd)) == -1)
	{
		printf("close() error\n");
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

int		ft_read_close(int fd, char **my_print, int my_ret)
{
	if ((ft_read_fd(fd, my_print, my_ret)) <= 0)
		return (-1);
	return (1);
}
