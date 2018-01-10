/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:09:01 by ade-verd          #+#    #+#             */
/*   Updated: 2018/01/10 18:57:33 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const t_ft	g_ft[] = {
	{'d', ft_int_type_d}
	};

void	ft_int_type_d(int *to_convert, t_indic **ind, t_buff **buff)
{
	printf("int:%d\n", to_convert);
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
			g_ft[i].f((int*)&to_convert, ind, buff);
			break ;
		}
		i++;
	}
}
