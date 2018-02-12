/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 17:52:58 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/12 12:06:05 by ade-verd         ###   ########.fr       */
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

void	ft_arg_char(va_list ap, t_indic **ind, t_buff **buff)
{
    ft_iscapital_c(ind);
	ft_get_chars_csp(ind, ap);
    ft_putcbuffer(buff, (*ind)->c);
}