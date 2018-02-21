/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 13:07:08 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/21 15:21:40 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_get_all_indics(t_indic **ind, va_list ap, char *str, int *i)
{
	ft_get_flags(ind, str, i);
	ft_get_width(ind, ap, str, i);
	ft_get_precision(ind, ap, str, i);
	ft_get_size(ind, str, i);
	ft_get_type(ind, str, i);
}

void	ft_convert(t_indic **ind, va_list ap, t_buff **buff)
{
	int				i;
	int				found;
	const t_conv	tab[] = { { "bpdDioOuUxX", ft_arg_int },
		{ "cC%", ft_arg_char },
		{ "sS", ft_arg_string },
		{ 0, 0}
	};

	i = 0;
	found = 0;
	while (tab[i].letters && found == 0)
	{
		if ((*ind)->type && ft_strchr_pos(tab[i].letters, (*ind)->type) != -1)
		{
			found++;
			tab[i].f(ap, ind, buff);
		}
		i++;
	}
	if (found == 0)
		ft_arg_novalid_conv(ind, buff);
}

void	ft_parse_str(va_list ap, char *str, t_buff **buff)
{
	int		i;
	t_indic	*ind;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			(*buff)->printed = 0;
			ft_init_indic(&ind);
			ft_get_all_indics(&ind, ap, str, &i);
			ft_convert(&ind, ap, buff);
			ft_reset_struct(&ind, buff);
		}
		else
			ft_putcbuffer(buff, str[i]);
		i += str[i] ? 1 : 0;
	}
}
