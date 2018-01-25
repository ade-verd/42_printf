/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 12:30:54 by ade-verd          #+#    #+#             */
/*   Updated: 2018/01/25 18:41:29 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_string_di(t_indic **ind, va_list ap)
{
	if (!(*ind)->size)
		return (ft_itoa_base((int)va_arg(ap, intmax_t), 10));
	if (ft_strcmp((*ind)->size, "hh") == 0)
		return (ft_itoa_base((signed char)va_arg(ap, intmax_t), 10));
	if (ft_strcmp((*ind)->size, "h") == 0)
		return (ft_itoa_base((short int)va_arg(ap, intmax_t), 10));
	if (ft_strcmp((*ind)->size, "l") == 0)
		return (ft_itoa_base((long int)va_arg(ap, intmax_t), 10));
	if (ft_strcmp((*ind)->size, "ll") == 0)
		return (ft_itoa_base((long long int)va_arg(ap, intmax_t), 10));
	if (ft_strcmp((*ind)->size, "j") == 0)
		return (ft_itoa_base((intmax_t)va_arg(ap, intmax_t), 10));
	if (ft_strcmp((*ind)->size, "z") == 0)
		return (ft_uitoa_base((size_t)va_arg(ap, intmax_t), 10));
	if (ft_strcmp((*ind)->size, "t") == 0)
		return (ft_itoa_base((ptrdiff_t)va_arg(ap, intmax_t), 10));
	//if (ft_strcmp((*ind)->size, "L") == 0)
	//	return ("");
	return (ft_itoa_base((int)va_arg(ap, intmax_t), 10));
}
