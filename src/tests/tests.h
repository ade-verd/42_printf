/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 13:01:35 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/01 17:13:27 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

# define TMP_OUT		"/tmp/out.txt"
# define EXAMPLE_FILE	"../Makefile"
# define ALL			1000
//# define LIGHT			1001
# define ERR_ONLY		1002
# define STOPIF0(x)		if((x) == 0)	return (0);
# define NONE			"\033[0m"
# define CYAN			"\033[036m"
# define RED			"\033[031m"
# define GREEN			"\033[032m"
# define YELLOW			"\x1b[33m"

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
	char		*letter;
	char		*designation;
	int			(*f)(void);
}				t_test;

int				ft_open(char *path, int oflag, int perm);
int				ft_close(int fd);
int				ft_read_fd(int fd, char **str, int buf_size);
int				ft_compare(int my_ret, int off_ret, char *my_print,
							char *off_print, char *str);
int				ft_call_both(char *str, ...);

int				ft_test_flag_no(void);
int				ft_test_flag_d(void);
int				ft_test_flag_o(void);
int				ft_test_flag_upper_D(void);

int		g_display_code;

static const t_test	g_test[] = {
	{"0", "no conversion", ft_test_flag_no},
	{"di", "int -> signed decimal (base 10)", ft_test_flag_d},
	{"o", "int -> unsigned octal (base 8)", ft_test_flag_o},
	//{"u", "int -> unsigned decimal (base 10)", ft_test_flag_u},
	//{"x", "int -> unsigned hexadecimal (base 16)", ft_test_flag_x},
	//{"X", "int -> UNSIGNED HEXADECIMAL (BASE 16)", ft_test_flag_upper_X},
	{"D", "long int -> signed decimal (base 10) (eq. %ld)", ft_test_flag_upper_D},
	//{"O", "long int -> unsigned octal (base 8) (eq. %ld)", ft_test_flag_upper_O},
	//{"U", "long int -> unsigned decimal (base 10) (eq. %ld)", ft_test_flag_upper_U},
	{0, 0, 0}
};

#endif
