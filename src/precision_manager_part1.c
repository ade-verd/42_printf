/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_manager_part1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:49:33 by ade-verd          #+#    #+#             */
/*   Updated: 2018/01/17 17:57:11 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_precision_int(t_indic **ind, t_buff **buff, char **str)
{
	int		width;
	int		len;

	if ((*ind)->precision == 0 && ft_atoi(*str) == 0)
		ft_strclr(*str);
		//Besoin de créer un isprecision ?
		//*str[0] = '\0';
	width = (*ind)->width;
	len = ft_strchr("+-", *str[0]) ? ft_strlen(*str) - 1 : ft_strlen(*str);
	printf("len : %d\n", len);
}
