/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_chars_to_convert.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 10:42:04 by ade-verd          #+#    #+#             */
/*   Updated: 2018/01/09 12:00:17 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_get_flags(t_indic **ind, char *str, int **i)
{
	int		*tmp;
	int		x;

	*i++;
	x = 0;
	tmp = ft_strchr("#0+- ", str);
	if (ft_strcmp(tmp, str + *i) == 0)
	{
		while (tmp[x] == '#' || tmp[x] == '0' || tmp[])
	}
}
