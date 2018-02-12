/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:22:06 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/12 15:19:05 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>
# include <stddef.h> /*ptrdiff_t*/
# include "libft.h"

# include <stdio.h> /* /!\ /!\ A SUPPRIMER /!\ /!\ */

# define BUFF_MAX_SIZE	4096

/*Unicode masks*/
# define MASK_BYTE0		0x0		/*0000 0000*/
# define MASK_BYTE1		0xC0	/*1100 0000*/ 
# define MASK_BYTE2		0xE0	/*1110 0000*/
# define MASK_BYTE3		0xF0	/*1111 0000*/
# define MASK_BYTE10	0x80	/*1000 0000*/

/*Buffer*/
typedef struct		s_buff
{
	char			*str;
	char			*prefix;
	char			*suffix;
	int				sign_printed;
	int				iszero;
	int				printed;
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
	intmax_t		nb;
	unsigned int	c;
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
	void			(*f3)(t_indic**, va_list, char **str, int base);
	void			(*f4)(t_indic**, va_list);
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
void				ft_arg_int(va_list ap, t_indic **ind, t_buff **buff);
void				ft_arg_char(va_list ap, t_indic **ind, t_buff **buff);

/*Flags*/
void				ft_print_sign_before(t_indic **i, t_buff **buff, char **s);
void				ft_manage_hashtag(t_indic **ind, t_buff **buff, char **str);
void				ft_manage_zero(t_indic **ind, t_buff **buff, char **str);
void				ft_manage_plus_signed(t_indic **i, t_buff **b, char **s);
void				ft_manage_plus_unsigned(t_indic **i, t_buff **b, char **s);
void				ft_manage_minus(t_indic **ind, t_buff **buff, char **str);

/*Precision*/
void				ft_precision_int(t_indic **ind, t_buff **buff, char **str);

/*Size*/
void				ft_get_string(t_indic **ind, va_list ap, char **str);
void				ft_get_chars_csp(t_indic **ind, va_list ap);

#endif
