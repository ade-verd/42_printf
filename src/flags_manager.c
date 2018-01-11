/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:44:23 by ade-verd          #+#    #+#             */
/*   Updated: 2018/01/11 13:11:11 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_manage_zero(t_indic **ind, t_buff **buff, char *str)
{
	int		width;
	int		len;
	int		i;

	if (!(ft_strchr((*ind)->flags, '0')))
		return ;
	width = (*ind)->width;
	len = ft_strlen(str);
	i = 0;
	while (i < (width - len))
	{
		ft_putcbuffer(buff, '0');
		i++;
	}
}
