/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_stdout.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 13:32:41 by ade-verd          #+#    #+#             */
/*   Updated: 2017/12/19 19:40:03 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	get_buffer(void)
{
	int		c;

	c = 0;
	while (c != '\n' && c != EOF)
		c = fgetc(stdout);
}

int		ft_redirect_stdout(void)
{
	int fd;

	fd = dup(fileno(stdout));
	if (!(freopen("out.txt", "a", stdout)))
		return (-1);
	return (fd);
}

int		ft_restore_stdout(int fd);
{
	dup2(fd,fileno(stdout));
	if (close(fd) == -1)
		return (-1);
}

int		ft_read_stdout(char **str, int buf_size)
{
	char	buf[buf_size + 1];
	int		ret;
//	int		pos;

//	get_buffer();
	fflush(stdout);
//	if ((pos = lseek(1, -(buf_size), SEEK_END)) <= 0)
//	{
//		printf("lseek() error\npos = %d\n", pos);
//		return (-1);
//	}
	if ((ret = read(1, buf, buf_size)) <= 0)
		return (-1);
//	if ((ret = read(STDOUT_FILENO, buf, 1)) < 0)
//		return (-1);
	buf[buf_size] = '\0';
	*str = ft_strjoin("", buf);
	//printf("buf_size : %d\n", buf_size);
	printf("str : %s\n", *str);
	return (1);
}
