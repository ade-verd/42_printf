/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_no.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 09:51:37 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/15 20:09:36 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int		ft_flag_no(void)
{
	int		fd;
	char	*line;
	if ((fd = ft_open(EXAMPLE_FILE, O_RDONLY , S_IRUSR)) == -1)
		return (-1);
	ft_init_counters();
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
	printf("\n*** No Flag [%d/%d] ***\n", g_counter_ok, g_counter_ok + g_counter_ko);
	if ((ft_close(fd)) == -1)
		return (-1);
	return (1);
}
