/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 13:07:08 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/15 13:50:17 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_indic(t_indic **ind)
{
	*ind = NULL;
	*ind = (t_indic*)malloc(sizeof(t_indic));
	(*ind)->width = 0;
	(*ind)->isprec = 0;
	(*ind)->precision = 0;
}

void	ft_free_indic(t_indic **ind)
{
	if ((*ind)->flags)
		ft_strdel(&(*ind)->flags);
	if ((*ind)->size)
		ft_strdel(&(*ind)->size);
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
/*	printf("Flags:|%s|\n", (*ind)->flags);
	printf("Width:|%d|\n", (*ind)->width);
	printf("Precision:|%d|\n", (*ind)->precision);
	printf("Size:|%s|\n", (*ind)->size);
	printf("Type:|%c|\n", (*ind)->type);*/
}

void	ft_convert(t_indic **ind, va_list ap, t_buff **buff, int *index)
{
	const t_conv	g_tab[] = {
		{ "bdDioOuUxX", ft_arg_int },
		{ "cC", ft_arg_char },
		{ "sS", ft_arg_string },/*
		{ "S", ft_ws_arg },
		{ "p", ft_p_arg },
		{ "%", ft_pct_arg },*/
		{ 0, 0}
	};
	int		i;
	int		found;

	i = 0;
	found = 0;
	while (g_tab[i].letters && found == 0)
	{
		if ((*ind)->type && ft_strchr_pos(g_tab[i].letters, (*ind)->type) != -1)
		{
			found++;
			g_tab[i].f(ap, ind, buff);
		}
		i++;
	}
	(*index) = (found == 0) ? (*index)-- : (*index) + 0;
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
			buff->printed = 0;
			ft_init_indic(&ind);
			ft_get_all_indics(&ind, ap, str, &i);
			ft_convert(&ind, ap, &buff, &i);
			ft_free_indic(&ind);
		}
		else
			ft_putcbuffer(&buff, str[i]);
		i++;
	}
	if (buff->err != -1)
		ft_print_buffer(&buff);
	*ret = buff->err != -1 ? buff->total : -1;
	ft_free_buff(&buff);
}
