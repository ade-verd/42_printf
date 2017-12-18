/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_stdout.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 13:32:41 by ade-verd          #+#    #+#             */
/*   Updated: 2017/12/18 14:57:26 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int		ft_read_stdout(char **str, int buf_size)
{
	char	buf[buf_size + 1];
	int		ret;

	lseek(0, -(buf_size), SEEK_END);
	ret = read(0, buf, buf_size);
	if (ret <= 0)
		return (-1);
	buf[buf_size] = '\0';
	*str = ft_strjoin("", buf);
	return (1);
}
