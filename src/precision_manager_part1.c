/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_manager_part1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:49:33 by ade-verd          #+#    #+#             */
/*   Updated: 2018/01/18 13:10:50 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_precision_int(t_indic **ind, t_buff **buff, char **str)
{
	int		i;
	int		prec;
	int		width;
	int		len;

	i = 0;
	prec = (*ind)->precision;
	if ((*ind)->isprec == 1 && prec == 0 && ft_atoi(*str) == 0)
		ft_strclr(*str);
	else
	{
		width = (*ind)->width;
		len = ft_strchr("+-", *str[0]) ? ft_strlen(*str) - 1 : ft_strlen(*str);
		while (i++ < (prec - len))
			ft_putcbuffer(buff, '0');
	}
}
