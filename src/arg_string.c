/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 14:12:59 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/13 18:24:16 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_iscapital_s(t_indic **ind)
{
	if ((*ind)->type == 'S')
    {
        (*ind)->type = 's';
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

void	ft_arg_string(va_list ap, t_indic **ind, t_buff **buff)
{
	char 	*str;

    ft_iscapital_s(ind);
	ft_get_string(ind, ap, &str);
	ft_indicators_manager(ind, buff, &str);
	ft_putsbuffer(buff, str);
	if ((*buff)->suffix)
		ft_putsbuffer(buff, (*buff)->suffix);
}