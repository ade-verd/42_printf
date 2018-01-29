/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:22:06 by ade-verd          #+#    #+#             */
/*   Updated: 2018/01/29 13:23:51 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>
# include <inttypes.h> /*intmax_t uintmax_t*/
# include <stddef.h> /*ptrdiff_t*/
# include "libft.h"

# include <stdio.h> /* /!\ /!\ A SUPPRIMER /!\ /!\ */

# define BUFF_MAX_SIZE	1000

/*Buffer*/
typedef struct		s_buff
{
	char			*str;
	char			*suffix;
	int				sign_printed;
	int				index;
	int				total;
	int				fd;
}					t_buff;

/*Indicators*/
typedef struct		s_indic
{
	char			*flags;
	int				width;
	int				isprec;
	int				precision;
	char			*size;
	char			type;
	int				type_index;
}					t_indic;

/*Associated function types and pointers*/
typedef struct		s_conv
{
	char			*letters;
	void			(*f)(va_list, t_indic**, t_buff**);
}					t_conv;

typedef struct		s_ft
{
	char			*letter;
	void			(*f1)(va_list, t_indic**, t_buff**);
	void			(*f2)(t_indic**, t_buff**, char **str);
	void			(*f3)(t_indic**, va_list, char **str);
}					t_ft;

/*ft_printf and cie*/
int					ft_printf(const char *str, ...);
int					ft_dprintf(int fd, const char *str, ...);
int					ft_vprintf(const char *str, va_list ap);
int					ft_vdprintf(int fd, const char *str, va_list ap);

/*Buffer and printer*/
void				ft_init_buffer(t_buff **buff, int fd);
void				ft_free_buff(t_buff **buff);
void				ft_putcbuffer(t_buff **buff, char c);
void				ft_putsbuffer(t_buff **buff, char *str);
void				ft_print_buffer(t_buff **buff);

/*Get chars to convert*/
void				ft_get_all_indics(t_indic **in, va_list a, char *s, int *i);
void				ft_get_flags(t_indic **ind, char *str, int *i);
void				ft_get_width(t_indic **ind, va_list ap, char *str, int *i);
void				ft_get_precision(t_indic **in, va_list ap, char *s, int *i);
void				ft_get_size(t_indic **ind, char *str, int *i);
void				ft_get_type(t_indic **ind, char *str, int *i);

/*Parse*/
void				ft_parse_str(va_list ap, char *str, int *ret, int fd);

/*Convert*/
void				ft_indicators_manager(t_indic **i, t_buff **buff, char **s);
void				ft_int_arg(va_list ap, t_indic **ind, t_buff**);
void				ft_int_type_d(va_list ap, t_indic **i, t_buff **buff);

/*Flags*/
void				ft_print_sign_before(t_indic **i, t_buff **buff, char **s);
void				ft_manage_hashtag(t_indic **ind, t_buff **buff, char **str);
void				ft_manage_zero(t_indic **ind, t_buff **buff, char **str);
void				ft_manage_plus(t_indic **ind, t_buff **buff, char **str);
void				ft_manage_minus(t_indic **ind, t_buff **buff, char **str);

/*Precision*/
void				ft_precision_int(t_indic **ind, t_buff **buff, char **str);

/*Size*/
void				ft_get_string(t_indic **ind, va_list, char **str);
void				ft_get_string_di(t_indic **ind, va_list, char **str);


static const t_conv	g_tab[] = {
	{ "bdDiouxX", ft_int_arg },/*
	{ "DOU", ft_dou_arg },
	{ "Cc", ft_c_arg },
	{ "s", ft_s_arg },
	{ "S", ft_ws_arg },
	{ "p", ft_p_arg },
	{ "%", ft_pct_arg },*/
	{ 0, 0}
};

#endif
