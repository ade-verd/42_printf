/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_chars_to_convert.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 10:42:04 by ade-verd          #+#    #+#             */
/*   Updated: 2018/01/09 17:28:38 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

void	ft_get_flags(t_indic **ind, char *str, int *i)
{
	int		j;
	int		k;

	j = 0;
	k = 0;
	while (str[*i + j] && ft_strchr_pos("#0+- ", str[*i + j]) != -1)
		j++;
	if (j > 0)
		(*ind)->flags = ft_strnew(j);
	while (j--)
		(*ind)->flags[k++] = str[(*i)++];
}

//void	ft_get_width(t_indic **ind, char *str, int *i)

