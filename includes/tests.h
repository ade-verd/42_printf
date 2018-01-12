/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 13:01:35 by ade-verd          #+#    #+#             */
/*   Updated: 2018/01/12 16:45:14 by ade-verd         ###   ########.fr       */
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

int				ft_redirect_stdout(void);
//int				ft_open(char *path, int oflag, int perm);
//int				ft_close(int fd);
//int				ft_read_fd(int fd, char **str, int buf_size);
int				ft_open_read_close(int fd, char **my_print, int my_ret);
int				ft_compare(int my_ret, int off_ret, char *my_print, char *off_print, char *str);
int				ft_call_both(char *str, ...);



int				ft_test_flag_d(void);

#endif
