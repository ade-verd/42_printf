/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:09:01 by ade-verd          #+#    #+#             */
/*   Updated: 2018/01/15 14:48:07 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const t_ft	g_ft[] = {
	{'d', ft_int_type_d},
	{'i', ft_int_type_d},
	{ 0, 0}
	};

void	ft_int_type_d(void *to_convert, t_indic **ind, t_buff **buff)
{
	int		integer;
	char	*str;

	integer = *(int*)to_convert;
	str = ft_itoa(integer);
	ft_indicators_manager(ind, buff, str);
//	if ((*buff)->prefix)
//		ft_putsbuffer(buff, (*buff)->prefix);
	ft_putsbuffer(buff, str);
	if ((*buff)->suffix)
		ft_putsbuffer(buff, (*buff)->suffix);
}

void	ft_int_arg(va_list ap, t_indic **ind, t_buff **buff)
{
	int		i;
	int		to_convert;

	i = 0;
	to_convert = va_arg(ap, int);
	while (g_ft[i].letter)
	{
		if ((*ind)->type && (*ind)->type == g_ft[i].letter)
		{
			g_ft[i].f((void*)&to_convert, ind, buff);
			break ;
		}
		i++;
	}
}
