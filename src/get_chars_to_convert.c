/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_chars_to_convert.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 10:42:04 by ade-verd          #+#    #+#             */
/*   Updated: 2018/01/09 14:37:29 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_get_flags(t_indic **ind, char *str, int *i)
{
	int		j;

	j = 0;
	while (str[*i] && ft_strchr_pos("#0+- ", str[*i]) == 0)
	{
		j++;
		(*i)++;
	}
	if (j)

	while (j--)
		

//	tmp = ft_strchr_pos("#0+- ", str);
//	if (ft_strcmp(tmp, str + *i) == 0)
}

