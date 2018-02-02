/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_no.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 09:51:37 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/02 09:51:47 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int		ft_flag_no(void)
{
	int		fd;
	char	*line;
	if ((fd = ft_open(EXAMPLE_FILE, O_RDONLY , S_IRUSR)) == -1)
		return (-1);
	printf("*** No Flag ***\n");

	STOPIF0(ft_call_both(""));
	STOPIF0(ft_call_both("Hey"));
	STOPIF0(ft_call_both("Hey", 10, 12, 13));
	while (get_next_line(fd, &line) > 0)
	{
		if (!ft_strchr(line, '%'))
			STOPIF0(ft_call_both(line));
		ft_strdel(&line);
	}
	printf("*** No Flag : all tests passed ***\n");
	if ((ft_close(fd)) == -1)
		return (-1);
	return (1);
}
