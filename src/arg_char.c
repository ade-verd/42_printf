/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 17:52:58 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/13 13:32:38 by ade-verd         ###   ########.fr       */
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

void 	ft_convert_unicode(t_indic **ind, char **byte)
{
	int 	nb_bits;

	nb_bits = ft_bitlen((*ind)->c);
	if (nb_bits <= 7)
		(*byte)[0] = (*ind)->c;
	else if (nb_bits <= 11)
	{
		(*byte)[0] = MASK_BYTE01 | ((*ind)->c >> 6 & RMASK_BYTE01);
		(*byte)[1] = MASK_BYTE10 | ((*ind)->c & RMASK_BYTE10);
	}
	else if (nb_bits <= 16)
	{
		(*byte)[0] = MASK_BYTE02 | ((*ind)->c >> 12 & RMASK_BYTE02);
		(*byte)[1] = MASK_BYTE10 | ((*ind)->c >> 6 & RMASK_BYTE10);
		(*byte)[2] = MASK_BYTE10 | ((*ind)->c & RMASK_BYTE10);
	}
	else
	{
		(*byte)[0] = MASK_BYTE03 | ((*ind)->c >> 18 & RMASK_BYTE03);
		(*byte)[1] = MASK_BYTE10 | ((*ind)->c >> 12 & RMASK_BYTE10);
		(*byte)[2] = MASK_BYTE10 | ((*ind)->c >> 6 & RMASK_BYTE10);
		(*byte)[3] = MASK_BYTE10 | ((*ind)->c & RMASK_BYTE10);
	}
}

void	ft_arg_char(va_list ap, t_indic **ind, t_buff **buff)
{
	char 	*str;
	int		iszero;

    (*ind)->c = va_arg(ap, wchar_t);
	iszero = (*ind)->c == 0 ? 1 : 0;
	str = ft_strnew(4);
	ft_bzero(str, 4);
    ft_iscapital_c(ind);
	if ((*ind)->size && ft_strcmp((*ind)->size, "l") == 0)
		ft_convert_unicode(ind, &str);
	else
		str[0] = (*ind)->c;
	if (iszero == 1)
		str[0] = '.';
	ft_indicators_manager(ind, buff, &str);
	iszero == 1 ? ft_putcbuffer(buff, 0) : ft_putsbuffer(buff, str);
	if ((*buff)->suffix)
		ft_putsbuffer(buff, (*buff)->suffix);
	ft_strdel(&str);
}