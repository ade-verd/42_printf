/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 13:07:08 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/16 18:33:59 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_get_all_indics(t_indic **ind, va_list ap, char *str, int *i)
{
	ft_get_flags(ind, str, i);
	ft_get_width(ind, ap, str, i);
	ft_get_precision(ind, ap, str, i);
	ft_get_size(ind, str, i);
	//printf("i:|%d|\n", *i);
	ft_get_type(ind, str, i);
/*	printf("Flags:|%s|\n", (*ind)->flags);
	printf("Width:|%d|\n", (*ind)->width);
	printf("Precision:|%d|\n", (*ind)->precision);
	printf("Size:|%s|\n", (*ind)->size);
	printf("Type:|%c|\t", (*ind)->type);
	printf("Type:|%d|\n", (*ind)->type);*/
}

void	ft_convert(t_indic **ind, va_list ap, t_buff **buff)
{
	const t_conv	g_tab[] = {
		{ "bpdDioOuUxX", ft_arg_int },
		{ "cC%", ft_arg_char },
		{ "sS", ft_arg_string },
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
	if (found == 0)
		ft_arg_novalid_conv(ind, buff);
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
			ft_convert(&ind, ap, &buff);
			ft_reset_struct(&ind, &buff);
		}
		else
			ft_putcbuffer(&buff, str[i]);
		i += str[i] ? 1 : 0;
	}
	if (buff->err != -1)
		ft_print_buffer(&buff);
	*ret = buff->err != -1 ? buff->total : -1;
	ft_free_buff(&buff);
}
