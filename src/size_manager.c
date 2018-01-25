/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 12:30:54 by ade-verd          #+#    #+#             */
/*   Updated: 2018/01/25 12:41:58 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_string_di(t_indic **ind, void *to_convert)
{
	if (!(*ind)->size)
		return (ft_itoa_base(*(int*)to_convert, 10));
	if (ft_strcmp((*ind)->size, "hh") == 0)
		return (ft_itoa_base(*(signed char*)to_convert, 10));
	if (ft_strcmp((*ind)->size, "h") == 0)
		return (ft_itoa_base(*(short int*)to_convert, 10));
	if (ft_strcmp((*ind)->size, "l") == 0)
		return (ft_itoa_base(*(long int*)to_convert, 10));
	if (ft_strcmp((*ind)->size, "ll") == 0)
		return (ft_itoa_base(*(long long int*)to_convert, 10));
	if (ft_strcmp((*ind)->size, "j") == 0)
		return (ft_itoa_base(*(intmax_t*)to_convert, 10));
	if (ft_strcmp((*ind)->size, "z") == 0)
		return (ft_itoa_base(*(size_t*)to_convert, 10));
	if (ft_strcmp((*ind)->size, "t") == 0)
		return (ft_itoa_base(*(ptrdiff_t*)to_convert, 10));
	//if (ft_strcmp((*ind)->size, "L") == 0)
	//	return ("");
	return (ft_itoa_base(*(int*)to_convert, 10));
}
