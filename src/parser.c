/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 13:07:08 by ade-verd          #+#    #+#             */
/*   Updated: 2018/01/10 15:00:01 by ade-verd         ###   ########.fr       */
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
	printf("Flags: |%s|\t", (*ind)->flags);
	ft_get_width(ind, ap, str, i);
	printf("Width: |%d|\t", (*ind)->width);
	ft_get_precision(ind, ap, str, i);
	printf("Precision: |%d|\t", (*ind)->precision);
	ft_get_size(ind, str, i);
	printf("Size: |%s|\t", (*ind)->size);
	//ft_get_type();
	printf("\n");
}

void	ft_parse_str(va_list ap, char *str, int *ret, int fd)
{
	int		i;
	t_buff	*buff;
	t_indic	*ind;

	i = 0;
	ft_init_buffer(&buff);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_init_indic(&ind);
			ft_get_all_indics(&ind, ap, str, &i);
			//To do here : find va_arg and convert
			ft_free_indic(&ind);
		}
		else
			ft_putbuffer(&buff, str[i], fd);
		i++;
	}
	*ret = buff->total;
	ft_free_buff(&buff);
}
