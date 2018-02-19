/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_novalid_conv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 17:52:58 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/19 15:32:02 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_arg_novalid_conv(t_indic **ind, t_buff **buff)
{
	char 	*str;
	int 	i;

	i = 0;
	if ((*ind)->type == '\0')
		return ;
	str = ft_strnew(4);
	ft_bzero(str, 4);
	(*ind)->c = (*ind)->type;
	(*ind)->type = '0';
	ft_unicode_to_str(ind, &str, (*ind)->c, &i);
	ft_indicators_manager(ind, buff, &str);
	ft_putsbuffer(buff, str);
	if ((*buff)->suffix)
		ft_putsbuffer(buff, (*buff)->suffix);
	ft_strdel(&str);
}