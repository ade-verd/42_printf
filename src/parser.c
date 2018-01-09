/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 13:07:08 by ade-verd          #+#    #+#             */
/*   Updated: 2018/01/09 12:00:23 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_indic(t_indic **ind)
{
	*ind = NULL;
	*ind = (t_indic*)malloc(sizeof(t_indic));
}

void	ft_free_buff(t_buff **ind)
{
	ft_strdel((*ind)->flags);
	(*ind)->width = 0;
	(*ind)->precision = 0;
	(*ind)->size = '\0';
	(*ind)->type = '\0';
	ft_memdel((void**)ind);
}

void	ft_get_all_indics(t_indic **ind, char *str, int **i)
{
	ft_get_flags(ind, str, i);
	//ft_get_width();
	//ft_get_precision();
	//ft_get_size();
	//ft_get_type();
}

void	ft_parse_str(va_list ap, char *str, int *ret, int fd)
{
	int		*i;
	t_buff	*buff;
	t_indic	*ind;

	i = 0;
	ft_init_buffer(&buff);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_init_indic(&ind);
			ft_get_all_indics(&indic, str, &i);
			//A faire : find va_arg and convert
			ft_free_ind(&ind);
		}
		else
			ft_putbuffer(&buff, str[i], fd);
		i++;
	}
	ret = (*buff->total);
	ft_free_buff(&buff);
}

