/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c5_capital_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 15:19:44 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/22 19:06:01 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_capital_type(t_indic **ind)
{
	if ((*ind)->type >= 'A' && (*ind)->type <= 'Z')
	{
		(*ind)->type = ft_tolower((*ind)->type);
		(*ind)->size[0] = 'l';
		(*ind)->size[1] = '\0';
	}
}
