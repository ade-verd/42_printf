/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_stdout.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 13:32:41 by ade-verd          #+#    #+#             */
/*   Updated: 2017/12/18 18:59:52 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int		ft_read_stdout(char **str, int buf_size)
{
	char	buf[buf_size + 1];
	int		ret;
	int		pos;

	fflush(stdout);
//	if ((pos = lseek(1, -(buf_size), SEEK_END)) <= 0)
//		return (-1);
	//if ((ret = read(1, buf, buf_size)) <= 0)
	if ((ret = read(STDOUT_FILENO, buf, 1)) <= 0)
		return (-1);
	buf[buf_size] = '\0';
	*str = ft_strjoin("", buf);
	//printf("buf_size : %d\n", buf_size);
	printf("str : %s\n", *str);
	return (1);
}
