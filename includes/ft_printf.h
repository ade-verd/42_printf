/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:22:06 by ade-verd          #+#    #+#             */
/*   Updated: 2018/01/10 18:57:36 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "stdlib.h"
# include "libft.h"

# include "stdio.h" /* /!\ /!\ A SUPPRIMER /!\ /!\ */

# define BUFF_MAX_SIZE	10

/*Buffer*/
typedef struct		s_buff
{
	char			*str;
	int				index;
	int				total;
	int				fd;
}					t_buff;

/*Indicators*/
typedef struct		s_indic
{
	char			*flags;
	int				width;
	int				precision;
	char			*size;
	char			type;
}					t_indic;

/*Associated function types and pointers*/
typedef struct		s_conv
{
	char			*letters;
	void			(*f)(va_list, t_indic**, t_buff**);
}					t_conv;

typedef struct		s_ft
{
	char			letter;
	void			(*f)(void*, t_indic**, t_buff**);
}					t_ft;

int					ft_printf(const char *str, ...);

/*Buffer and printer*/
void				ft_init_buffer(t_buff **buff, int fd);
void				ft_free_buff(t_buff **buff);
void				ft_putbuffer(t_buff **buff, char c);
void				ft_print_buffer(t_buff **buff);

/*Get chars to convert*/
void				ft_get_all_indics(t_indic **ind, va_list ap, char *str, int *i);
void				ft_get_flags(t_indic **ind, char *str, int *i);
void				ft_get_width(t_indic **ind, va_list ap, char *str, int *i);
void				ft_get_precision(t_indic **ind, va_list ap, char *str, int *i);
void				ft_get_size(t_indic **ind, char *str, int *i);
void				ft_get_type(t_indic **ind, char *str, int *i);

/*Parse*/
void				ft_parse_str(va_list ap, char *str, int *ret, int fd);

/*Convert*/
void				ft_int_arg(va_list ap, t_indic **ind, t_buff**);
void				ft_int_type_d(int *to_convert, t_indic **ind, t_buff **buff);

static const t_conv	g_tab[] = {
	{ "bdiouxX", ft_int_arg }/*,
	{ "DOU", ft_dou_arg },
	{ "Cc", ft_c_arg },
	{ "s", ft_s_arg },
	{ "S", ft_ws_arg },
	{ "p", ft_p_arg },
	{ "%", ft_pct_arg }*/
	};

#endif
