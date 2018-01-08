/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:22:06 by ade-verd          #+#    #+#             */
/*   Updated: 2018/01/08 17:58:23 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "stdlib.h"
# include "libft.h"
# define BUFF_MAX_SIZE	10

typedef struct	s_conv
{
	char		*flags;
	int			width;
	int			precision;
	char		size;
	char		type;
	char		*conversion;
	void		*f(va_list, char*, int*);
}				t_conv;

typedef struct	s_buff
{
	//char		str[BUFF_MAX_SIZE + 1];
	char		*str;
	int			index;
	int			total;
}				t_buff;

void			ft_init_buffer(t_buff **buff);
void			ft_putbuffer(t_buff **buff, char c, int fd);
void			ft_print_buffer(t_buff **buff, int fd);
//void			ft_parse_str(va_list ap, char *str, int *ret, int fd);

#endif
