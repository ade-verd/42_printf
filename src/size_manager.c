/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 12:30:54 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/02 16:52:49 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_get_string(t_indic **ind, va_list ap, char **str)
{
	const t_ft	g_length[] = {
		{"di", 0, 0, ft_get_string_di},
		{"uoxX", 0, 0, ft_get_string_ouxx},
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
			g_length[i].f3(ind, ap, str, 10);
			return ;
		}
		i++;
	}
	*str = NULL;
}

void	ft_get_string_di(t_indic **ind, va_list ap, char **str, int base)
{
	if ((*ind)->size && ft_strcmp((*ind)->size, "hh") == 0)
		(*ind)->nb = (signed char)va_arg(ap, int);
	else if ((*ind)->size && ft_strcmp((*ind)->size, "h") == 0)
		(*ind)->nb = (short int)va_arg(ap, int);
	else if ((*ind)->size && ft_strcmp((*ind)->size, "l") == 0)
		(*ind)->nb = va_arg(ap, long int);
	else if ((*ind)->size && ft_strcmp((*ind)->size, "ll") == 0)
		(*ind)->nb = va_arg(ap, long long int);
	else if ((*ind)->size && ft_strcmp((*ind)->size, "j") == 0)
		(*ind)->nb = va_arg(ap, intmax_t);
	else if ((*ind)->size && ft_strcmp((*ind)->size, "t") == 0)
		(*ind)->nb = va_arg(ap, ptrdiff_t);
	else if ((*ind)->size && ft_strcmp((*ind)->size, "z") == 0)
		(*ind)->nb = va_arg(ap, size_t);
	else
		(*ind)->nb = va_arg(ap, int);
	*str = ft_itoa_base((*ind)->nb, base);
}

void	ft_get_string_ouxx(t_indic **ind, va_list ap, char **str, int base)
{
	if ((*ind)->type == 'o' || (*ind)->type == 'O')
		base = 8;
	else if ((*ind)->type == 'x' || (*ind)->type == 'X')
		base = 16;
	if ((*ind)->size && ft_strcmp((*ind)->size, "hh") == 0)
		(*ind)->nb = (unsigned char)va_arg(ap, unsigned int);
	else if ((*ind)->size && ft_strcmp((*ind)->size, "h") == 0)
		(*ind)->nb = (unsigned short int)va_arg(ap, unsigned int);
	else if ((*ind)->size && ft_strcmp((*ind)->size, "l") == 0)
		(*ind)->nb = va_arg(ap, unsigned long int);
	else if ((*ind)->size && ft_strcmp((*ind)->size, "ll") == 0)
		(*ind)->nb = va_arg(ap, unsigned long long int);
	else if ((*ind)->size && ft_strcmp((*ind)->size, "j") == 0)
		(*ind)->nb = va_arg(ap, uintmax_t);
	else if ((*ind)->size && ft_strcmp((*ind)->size, "z") == 0)
		(*ind)->nb = va_arg(ap, size_t);
	else if ((*ind)->size && ft_strcmp((*ind)->size, "t") == 0)
		(*ind)->nb = va_arg(ap, ptrdiff_t);
	else
		(*ind)->nb = va_arg(ap, unsigned int);
	*str = ft_uitoa_base((*ind)->nb, base);
}
