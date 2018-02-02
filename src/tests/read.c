/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 09:52:20 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/02 09:52:26 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int		ft_open(char *path, int oflag, int perm)
{
	int		fd;

	if ((fd = open(path, oflag, perm)) == -1)
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
	if ((ret = read(fd, buf, buf_size)) < 0)
	{
		printf("read() error\n");
		return (-1);
	}
	buf[buf_size] = '\0';
	*str = ft_strjoin("", buf);
	return (1);
}
