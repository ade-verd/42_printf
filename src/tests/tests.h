/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 13:01:35 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/16 13:23:44 by ade-verd         ###   ########.fr       */
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
# include <locale.h>
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

# define TMP_OUT		"/tmp/out.txt"
# define EXAMPLE_FILE	"../Makefile"
# define ALL			1000
# define LIGHT			1001
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
int 			ft_remove(char *path);
int				ft_read_fd(int fd, char **str, int buf_size);
int				ft_compare(int my_ret, int off_ret, char *my_print,
							char *off_print, char *str);
int				ft_call_both(char *str, ...);
void			ft_init_counters(void);

int				ft_flag_no(void);
int				ft_flag_d(void);
int				ft_flag_o(void);
int				ft_flag_u(void);
int				ft_flag_x(void);
int				ft_flag_capital_D(void);
int				ft_flag_capital_O(void);
int				ft_flag_capital_U(void);
int				ft_flag_capital_X(void);
int				ft_flag_c(void);
int				ft_flag_s(void);
int				ft_flag_p(void);
int				ft_flag_percent(void);
int				ft_flag_b_bonus(void);

int				g_display_code;
int				g_counter_ok;
int				g_counter_ko;

static const t_test	g_test[] = {
	{"0", "no conversion", ft_flag_no},
	{"di", "int -> signed decimal (base 10)", ft_flag_d},
	{"o", "int -> unsigned octal (base 8)", ft_flag_o},
	{"u", "int -> unsigned decimal (base 10)", ft_flag_u},
	{"x", "int -> unsigned hexadecimal (base 16)", ft_flag_x},
	{"D", "long int -> signed decimal (base 10) (eq. %ld)", ft_flag_capital_D},
	{"O", "long int -> unsigned octal (base 8) (eq. %ld)", ft_flag_capital_O},
	{"U", "long int -> unsigned decimal (base 10) (eq. %ld)", ft_flag_capital_U},
	{"X", "int -> UNSIGNED HEXADECIMAL (BASE 16)", ft_flag_capital_X},
	{"cC", "int -> unsigned char", ft_flag_c},
	{"s", "char* -> pointer to a string (or to an array of character type)", ft_flag_s},
	{"p", "pointer void* -> unsigned hexadecimal (base 16)", ft_flag_p},
	{"%", "percent", ft_flag_percent},
	{"b", "int -> binary (base 2)", ft_flag_b_bonus},
	{0, 0, 0}
};

#endif
