/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:22:06 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/22 13:05:09 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>
# include <stddef.h>
# include "libft.h"

# include <stdio.h> /* A SUPPRIMER */

# define PRINT_IN_STRING	-123456789

/*
** Unicode masks
**	MASK_BYTE00		0x0		0xxx xxxx	||	RMASK_BYTE00	0x7F	0111 1111
**	MASK_BYTE01		0xC0	110x xxxx	||	RMASK_BYTE01	0x1F	0001 1111
**	MASK_BYTE02		0xE0	1110 xxxx	||	RMASK_BYTE02	0x0F	0000 1111
**	MASK_BYTE03		0xF0	1111 0xxx	||	RMASK_BYTE03	0x07	0000 0111
**	MASK_BYTE10		0x80	10xx xxxx	||	RMASK_BYTE10	0x3F	0011 1111
*/
# define MASK_BYTE00	0x0
# define RMASK_BYTE00	0x7F
# define MASK_BYTE01	0xC0
# define RMASK_BYTE01	0x1F
# define MASK_BYTE02	0xE0
# define RMASK_BYTE02	0x0F
# define MASK_BYTE03	0xF0
# define RMASK_BYTE03	0x07
# define MASK_BYTE10	0x80
# define RMASK_BYTE10	0x3F

/*
** Buffer
*/
typedef struct		s_buff
{
	intmax_t		size_max;
	char			*str;
	char			*prefix;
	char			*suffix;
	int				sign_printed;
	int				iszero;
	int				printed;
	intmax_t		index;
	intmax_t		total;
	int				fd;
	int				err;
}					t_buff;

/*
** Indicators
*/
typedef struct		s_indic
{
	char			*flags;
	int				width;
	int				isprec;
	int				precision;
	char			*size;
	char			type;
	intmax_t		nb;
	unsigned int	c;
	wchar_t			*ws;
}					t_indic;

/*
** ft_printf and cie
*/
int					ft_printf(const char *str, ...);
int					ft_dprintf(int fd, const char *str, ...);
int					ft_asprintf(char **str, const char *fmt, ...);
int					ft_vprintf(const char *str, va_list ap);
int					ft_vdprintf(int fd, const char *str, va_list ap);
int					ft_vasprintf(char **str, const char *fmt, va_list ap);

/*
** Struct init and free
*/
int					ft_init_indic(t_indic **ind);
void				ft_free_indic(t_indic **ind);
int					ft_init_buffer(t_buff **buff, int fd);
void				ft_free_buff(t_buff **buff);
void				ft_reset_struct(t_indic **ind, t_buff **buff);

/*
** Printer
*/
void				ft_putcbuffer(t_buff **buff, char c);
void				ft_putsbuffer(t_buff **buff, char *str);
char				*ft_print_buffer(t_buff **buff);

/*
** Get chars to convert
*/
void				ft_get_all_indics(t_indic **in, va_list a, char *s, int *i);
void				ft_get_flags(t_indic **ind, char *str, int *i);
void				ft_get_width(t_indic **ind, va_list ap, char *str, int *i);
void				ft_get_precision(t_indic **in, va_list ap, char *s, int *i);
void				ft_get_size(t_indic **ind, char *str, int *i);
void				ft_get_type(t_indic **ind, char *str, int *i);

/*
** Parse
*/
void				ft_parse_str(va_list ap, char *str, t_buff **buff);

/*
** Convert
*/
void				ft_arg_int(va_list ap, t_indic **ind, t_buff **buff);
void				ft_arg_char(va_list ap, t_indic **ind, t_buff **buff);
void				ft_arg_string(va_list ap, t_indic **ind, t_buff **buff);
void				ft_arg_novalid_conv(t_indic **i, t_buff **b);

/*
** Flags
*/
void				ft_indicators_manager(t_indic **i, t_buff **buff, char **s);
void				ft_print_sign_before(t_indic **i, t_buff **buff, char **s);
void				ft_manage_hashtag(t_indic **ind, t_buff **buff, char **str);
void				ft_manage_zero(t_indic **ind, t_buff **buff, char **str);
void				ft_manage_plus_signed(t_indic **i, t_buff **b, char **s);
void				ft_manage_plus_unsigned(t_indic **i, t_buff **b, char **s);
void				ft_manage_plus_string(t_indic **ind, t_buff **b, char **s);
void				ft_manage_minus(t_indic **ind, t_buff **buff, char **str);

/*
** Precision
*/
void				ft_precision_int(t_indic **ind, t_buff **buff, char **str);
void				ft_precision_string(t_indic **i, t_buff **buff, char **str);

/*
** Size
*/
void				ft_get_string(t_indic **ind, va_list ap, char **str);
void				ft_get_chars_csp(t_indic **ind, va_list ap);

/*
** Unicode
*/
void				ft_unicode_to_str(t_indic **ind,
									t_buff **b, char **s, int *i);
void				ft_convert_unicode(t_indic **ind, char **byte, int *i);

/*
** Errors
*/
void				ft_error_manager(t_buff **buff);

/*
** Associated function types and pointers
*/
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
	void			(*f3)(t_indic**, va_list, char **str, int base);
	void			(*f4)(t_indic**, va_list, char **str);
}					t_ft;

#endif
