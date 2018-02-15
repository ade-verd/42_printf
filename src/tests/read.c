/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 09:52:20 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/15 13:42:14 by ade-verd         ###   ########.fr       */
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

int 	ft_remove(char *path)
{
	if (remove(path) == -1)
	{
		printf("remove() error\n");
		return (-1);
	}
	return (1);
}

int		ft_read_fd(int fd, char **str, int buf_size)
{
	int		ret;
	int 	pos;
	char	buf[buf_size + 1];
	char	*tmp;

	*str = ft_strnew(0);
	if ((pos = lseek(fd, 0, SEEK_SET)) < 0)
	{
		printf("lseek() error\npos = %d\n", pos);
		return (-1);
	}
	while ((ret = read(fd, buf, buf_size)) > 0)
	{
		buf[ret] = '\0';
		if (!(tmp = ft_strjoin(*str, buf)))
			return (-1);
		if (*str)
			ft_strdel(str);
		if (!(*str = ft_strdup(tmp)))
			return (-1);
		if (tmp)
			ft_strdel(&tmp);
	}
	return (ret);
}


/*int		ft_read_fd(int fd, char **str, int buf_size)
{
	char	buf[buf_size + 1];
	int		ret;
	int		pos;

	if (buf_size < 0)
		buf_size = 0;
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
}*/
