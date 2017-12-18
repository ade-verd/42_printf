/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 13:01:35 by ade-verd          #+#    #+#             */
/*   Updated: 2017/12/18 18:59:48 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include <unistd.h>
# include <stdio.h>
# include "libft.h"

int		ft_read_stdout(char **str, int buf_size);
void	ft_compare(int my_ret, int off_ret, char *my_print, char *off_print);

int		test_flag_d(int nb);


#endif
