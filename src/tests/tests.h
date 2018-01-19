/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 13:01:35 by ade-verd          #+#    #+#             */
/*   Updated: 2018/01/19 11:47:01 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"

# define STOPIF0(x) if((x) == 0)	return (0);

typedef struct	s_txt
{
	int			fd;
	int			my_ret;
	int			off_ret;
	char		*my_print;
	char		*off_print;
	char		trash[100];
}				t_txt;

typedef struct	s_test
{
	char		letter;
	int			(*f)(void);
}				t_test;

int				ft_open(char *path, int oflag, int perm);
int				ft_close(int fd);
int				ft_read_fd(int fd, char **str, int buf_size);
int				ft_compare(int my_ret, int off_ret, char *my_print,
							char *off_print, char *str);
int				ft_call_both(char *str, ...);

int				ft_test_flag_d(void);

static const t_test	g_test[] = {
	{'d', ft_test_flag_d},
	{0, 0}
};

#endif
