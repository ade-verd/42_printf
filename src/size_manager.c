/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 12:30:54 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/13 16:10:10 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void	ft_get_string_bouxx(t_indic **ind, va_list ap, char **str, int base)
{
	if ((*ind)->type == 'b')
		base = 2;
	else if ((*ind)->type == 'o' || (*ind)->type == 'O')
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

void	ft_get_chars_cs(t_indic **ind, va_list ap, char **str)
{
	if ((*ind)->type == 'c')
	{
		if ((*ind)->size && ft_strcmp((*ind)->size, "l") == 0)
	    	(*ind)->c = va_arg(ap, wchar_t);
		else
	    	(*ind)->c = (char)va_arg(ap, int);
	}
	else if ((*ind)->type == 's')
	{
		if ((*ind)->size && ft_strcmp((*ind)->size, "l") == 0)
    		*str = (char*)va_arg(ap, wchar_t*);
		else
    		*str = va_arg(ap, char*);
	}
}


void	ft_get_string(t_indic **ind, va_list ap, char **str)
{
	const t_ft	length[] = {
		{"3di", 0, 0, ft_get_string_di, 0},
		{"3bouxX", 0, 0, ft_get_string_bouxx, 0},
		//{"3fFgGaAeE", 0, , 0},
		{"4cs", 0, 0, 0, ft_get_chars_cs},
		//{"3n", 0, , 0},
		//{"3p", 0, , 0},
		{0, 0, 0, 0, 0}
	};
	int		i;

	i = 0;
	while (length[i].letter)
	{
		if ((*ind)->type && ft_strchr(length[i].letter, (*ind)->type))
		{
			if (length[i].letter[0] == '3')
				length[i].f3(ind, ap, str, 10);
			else if (length[i].letter[0] == '4')
				length[i].f4(ind, ap, str);
			return ;
		}
		i++;
	}
	*str = NULL;
}
