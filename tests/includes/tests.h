/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 13:01:35 by ade-verd          #+#    #+#             */
/*   Updated: 2017/12/20 12:03:41 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"

int		ft_read_stdout(int fd, char **str, int buf_size);
void	ft_compare(int my_ret, int off_ret, char *my_print, char *off_print);

int		ft_redirect_stdout(void);
int		ft_restore_stdout(int fd);
int		test_flag_d(int nb);


#endif
