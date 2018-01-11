/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 13:07:08 by ade-verd          #+#    #+#             */
/*   Updated: 2018/01/11 17:46:04 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_indic(t_indic **ind)
{
	*ind = NULL;
	*ind = (t_indic*)malloc(sizeof(t_indic));
}

void	ft_free_indic(t_indic **ind)
{
		if ((*ind)->flags)
			ft_strdel(&(*ind)->flags);
		if ((*ind)->width)
			(*ind)->width = 0;
		if ((*ind)->precision)
			(*ind)->precision = 0;
		if ((*ind)->size)
			ft_strdel(&(*ind)->size);
		if ((*ind)->type)
			(*ind)->type = '\0';
		if (*ind)
			ft_memdel((void**)ind);
}

void	ft_get_all_indics(t_indic **ind, va_list ap, char *str, int *i)
{
	ft_get_flags(ind, str, i);
	ft_get_width(ind, ap, str, i);
	ft_get_precision(ind, ap, str, i);
	ft_get_size(ind, str, i);
	ft_get_type(ind, str, i);
/*
	printf("\tFlags: |%s|\n", (*ind)->flags);
	printf("\tWidth: |%d|\n", (*ind)->width);
	printf("\tPrecision: |%d|\n", (*ind)->precision);
	printf("\tSize: |%s|\n", (*ind)->size);
	printf("\tType: |%c|\n", (*ind)->type);
*/
}

void	ft_convert(t_indic **ind, va_list ap, t_buff **buff)
{
	int		i;

	i = 0;
	while (g_tab[i].letters)
	{
		if ((*ind)->type && ft_strchr_pos(g_tab[i].letters, (*ind)->type) != -1)
		{
			g_tab[i].f(ap, ind, buff);
			break ;
		}
		i++;
	}
}

void	ft_parse_str(va_list ap, char *str, int *ret, int fd)
{
	int		i;
	t_buff	*buff;
	t_indic	*ind;

	i = 0;
	ft_init_buffer(&buff, fd);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_init_indic(&ind);
			ft_get_all_indics(&ind, ap, str, &i);
			ft_convert(&ind, ap, &buff);
			ft_free_indic(&ind);
		}
		else
			ft_putcbuffer(&buff, str[i]);
		i++;
	}
	ft_print_buffer(&buff);
	*ret = buff->total;
	ft_free_buff(&buff);
}
