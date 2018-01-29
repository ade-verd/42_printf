/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_flag_no.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:11:07 by ade-verd          #+#    #+#             */
/*   Updated: 2018/01/29 16:49:52 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int		ft_test_flag_no(void)
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
		STOPIF0(ft_call_both(line));
		ft_strdel(&line);
	}
	printf("*** No Flag : all tests passed ***\n");
	if ((ft_close(fd)) == -1)
		return (-1);
	return (1);
}
