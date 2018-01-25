/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:09:01 by ade-verd          #+#    #+#             */
/*   Updated: 2018/01/25 18:41:33 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_int_type_d(va_list ap, t_indic **ind, t_buff **buff)
{
	char	*str;

	str = ft_get_string(ind, ap);
	ft_indicators_manager(ind, buff, &str);
	ft_putsbuffer(buff, str);
	if ((*buff)->suffix)
		ft_putsbuffer(buff, (*buff)->suffix);
}

void	ft_int_arg(va_list ap, t_indic **ind, t_buff **buff)
{
	const t_ft	g_ft[] = {
		{"di", ft_int_type_d, NULL, NULL},
		{0, 0, 0, 0}
	};
	int			i;

	i = 0;
	while (g_ft[i].letter)
	{
		if ((*ind)->type && ft_strchr(g_ft[i].letter, (*ind)->type))
		{
			g_ft[i].f1(ap, ind, buff);
			break ;
		}
		i++;
	}
}
