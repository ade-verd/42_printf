/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:22:06 by ade-verd          #+#    #+#             */
/*   Updated: 2018/01/09 12:00:20 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "stdlib.h"
# include "libft.h"
# define BUFF_MAX_SIZE	10

/*Associated function types and pointers*/
typedef struct	s_conv
{
	char		*conversion;
	void		*f(va_list, char*, int*);
}				t_conv;

/*Indicators*/
typedef struct	s_indic
{
	char		*flags;
	int			width;
	int			precision;
	char		size;
	char		type;
}				t_params;

/*Buffer*/
typedef struct	s_buff
{
	char		*str;
	int			index;
	int			total;
}				t_buff;

/*Buffer and printer*/
void			ft_init_buffer(t_buff **buff);
void			ft_putbuffer(t_buff **buff, char c, int fd);
void			ft_print_buffer(t_buff **buff, int fd);

/*Get chars to convert*/
void			ft_get_flags(t_indic **ind, char *str);

/*Parse*/
void			ft_parse_str(va_list ap, char *str, int *ret, int fd);

#endif
