/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 12:30:54 by ade-verd          #+#    #+#             */
/*   Updated: 2018/01/26 13:24:42 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_get_string(t_indic **ind, va_list ap, char **str)
{
	const t_ft	g_length[] = {
		{"di", 0, 0, ft_get_string_di},
		//{"uoxX", 0, },
		//{"fFgGaAeE", 0, },
		//{"csp", 0, },
		//{"n", 0, },
		{0, 0, 0, 0}
	};
	int		i;

	i = 0;
	while (g_length[i].letter)
	{
		if ((*ind)->type && ft_strchr(g_length[i].letter, (*ind)->type))
		{
			g_length[i].f3(ind, ap, str);
			return ;
		}
		i++;
	}
	*str = NULL;
}

void	ft_get_string_di(t_indic **ind, va_list ap, char **str)
{
	if ((*ind)->size && ft_strcmp((*ind)->size, "hh") == 0)
		*str = ft_itoa_base((signed char)va_arg(ap, intmax_t), 10);
	else if ((*ind)->size && ft_strcmp((*ind)->size, "h") == 0)
		*str = ft_itoa_base((short int)va_arg(ap, intmax_t), 10);
	else if ((*ind)->size && ft_strcmp((*ind)->size, "l") == 0)
		*str = ft_itoa_base((long int)va_arg(ap, intmax_t), 10);
	else if ((*ind)->size && ft_strcmp((*ind)->size, "ll") == 0)
		*str = ft_itoa_base((long long int)va_arg(ap, intmax_t), 10);
	else if ((*ind)->size && ft_strcmp((*ind)->size, "j") == 0)
		*str = ft_itoa_base((intmax_t)va_arg(ap, intmax_t), 10);
	else if ((*ind)->size && ft_strcmp((*ind)->size, "z") == 0)
		*str = ft_uitoa_base((size_t)va_arg(ap, intmax_t), 10);
	else if ((*ind)->size && ft_strcmp((*ind)->size, "t") == 0)
		*str = ft_itoa_base((ptrdiff_t)va_arg(ap, intmax_t), 10);
	else
		*str = ft_itoa_base((int)va_arg(ap, intmax_t), 10);
}
