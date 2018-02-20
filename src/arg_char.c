/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 17:52:58 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/20 19:52:13 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_iscapital_c(t_indic **ind)
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
	char	*str;
	int		iszero;
	int		i;

	i = 0;
	str = ft_strnew(4);
	ft_bzero(str, 4);
	ft_iscapital_c(ind);
	if ((*ind)->type == '%')
		(*ind)->c = '%';
	else
		ft_get_string(ind, ap, &str);
	ft_unicode_to_str(ind, buff, &str, &i);
	iszero = (*ind)->c == 0 ? 1 : 0;
	if (iszero == 1)
		str[0] = '.';
	ft_indicators_manager(ind, buff, &str);
	iszero == 1 ? ft_putcbuffer(buff, 0) : ft_putsbuffer(buff, str);
	if ((*buff)->suffix)
		ft_putsbuffer(buff, (*buff)->suffix);
	ft_strdel(&str);
}
