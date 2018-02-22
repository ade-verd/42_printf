/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d0_arg_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:09:01 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/22 15:05:50 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_int_bdiouxx(va_list ap, t_indic **ind, t_buff **buff)
{
	char	*str;

	ft_get_string(ind, ap, &str);
	if ((*ind)->type == 'x')
		str = ft_strlower(str);
	ft_indicators_manager(ind, buff, &str);
	ft_putsbuffer(buff, str);
	if ((*buff)->suffix)
		ft_putsbuffer(buff, (*buff)->suffix);
	if (str)
		ft_strdel(&str);
}

void	ft_int_p(va_list ap, t_indic **ind, t_buff **buff)
{
	char	*str;

	(*buff)->prefix[0] = '0';
	(*buff)->prefix[1] = 'x';
	(*buff)->sign_printed += 2;
	ft_get_string(ind, ap, &str);
	str = ft_strlower(str);
	if ((*ind)->isprec == 1 && (*ind)->precision == 0 && (*ind)->nb == 0)
		ft_strclr(str);
	ft_indicators_manager(ind, buff, &str);
	ft_putsbuffer(buff, str);
	if ((*buff)->suffix)
		ft_putsbuffer(buff, (*buff)->suffix);
	if (str != NULL)
		ft_strdel(&str);
}

void	ft_arg_int(va_list ap, t_indic **ind, t_buff **buff)
{
	if (ft_strchr("DOU", (*ind)->type))
	{
		(*ind)->type = ft_tolower((*ind)->type);
		if ((*ind)->size)
		{
			(*ind)->size[0] = 'l';
			(*ind)->size[1] = '\0';
		}
		else
		{
			if (!((*ind)->size = ft_strnew(1)))
			{
				ft_error_manager(buff);
				return ;
			}
			(*ind)->size[0] = 'l';
		}
	}
	if ((*ind)->type == 'p')
		ft_int_p(ap, ind, buff);
	else
		ft_int_bdiouxx(ap, ind, buff);
}
