/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 17:52:58 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/12 15:19:30 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_iscapital_c(t_indic **ind)
{
	if ((*ind)->type == 'C')
    {
        (*ind)->type = 'c';
		if ((*ind)->size)
		{
			(*ind)->size[0] = 'l';
			(*ind)->size[1] = '\0';
		}
		else
		{
			(*ind)->size = ft_strnew(1);
			(*ind)->size[0] = 'l';
        }
    }
}

void 	ft_convert_unicode(t_indic **ind, t_buff **buff)
{
	unsigned int 	v;
	int 			nb_bits;
	unsigned char 	byte;

	v = (*ind)->c;
	nb_bits = ft_bitlen(v);
	if (nb_bits >= 8 && nb_bits <= 11)
	{
		byte = MASK_BYTE1 | ((*ind)->c >> 6 & (MASK_BYTE1 - 1));
		ft_putcbuffer(buff, byte); 
		byte = MASK_BYTE10 | ((*ind)->c & (MASK_BYTE10 - 1));
		ft_putcbuffer(buff, byte);
	}
//	else if (nb_bits >= 12 && nb_bits <= 16)
//	else if (nb_bits >= 17 && nb_bits <= 21)
}

void	ft_arg_char(va_list ap, t_indic **ind, t_buff **buff)
{
    ft_iscapital_c(ind);
	ft_get_chars_csp(ind, ap);
	if ((*ind)->c <= 127)
		ft_putcbuffer(buff, (*ind)->c);
	else
		ft_convert_unicode(ind, buff);
}