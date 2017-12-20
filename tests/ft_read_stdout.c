/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_stdout.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 13:32:41 by ade-verd          #+#    #+#             */
/*   Updated: 2017/12/20 13:07:34 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int		ft_read_stdout(int fd, char **str, int buf_size)
{
	char	buf[buf_size + 1];
	int		ret;
	int		pos;

	if ((pos = lseek(fd, -(buf_size), SEEK_END)) <= 0)
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
