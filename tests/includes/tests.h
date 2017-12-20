/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 13:01:35 by ade-verd          #+#    #+#             */
/*   Updated: 2017/12/20 15:14:53 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"

typedef struct	s_txt
{
	int			fd;
	int			my_ret;
	int			off_ret;
	char		*my_print;
	char		*off_print;
	char		trash[100];
}				t_txt;

int		ft_redirect_stdout(void);
int		ft_open_read_close(int fd, char **my_print, int my_ret);
void	ft_compare(int my_ret, int off_ret, char *my_print, char *off_print);

int		test_flag_d(int nb);


#endif
