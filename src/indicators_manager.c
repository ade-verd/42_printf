/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indicators_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:58:47 by ade-verd          #+#    #+#             */
/*   Updated: 2018/01/26 12:16:04 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flags_manager(t_indic **ind, t_buff **buff, char **str)
{
	ft_print_sign_before(ind, buff, str);
	ft_manage_hashtag(ind, buff, str);
	ft_manage_plus(ind, buff, str);
	ft_manage_minus(ind, buff, str);
	ft_manage_zero(ind, buff, str);
}

void	ft_precision_manager(t_indic **ind, t_buff **buff, char **str)
{
	const t_ft	g_pres[] = {
	//	{"aA", NULL, ft_precision_, NULL},
		{"diouxX", NULL, ft_precision_int, NULL},
	//	{"eE", NULL, ft_precision_, NULL},
	//	{"fF", NULL, ft_precision_, NULL},
	//	{"gG", NULL, ft_precision_, NULL},
	//	{"sS", NULL, ft_precision_, NULL},
		{0, 0, 0, 0}
	};
	int		i;

	i = 0;
	if ((*ind)->isprec == 0)
		return ;
	while (g_pres[i].letter)
	{
		if ((*ind)->type && ft_strchr(g_pres[i].letter, (*ind)->type))
		{
			g_pres[i].f2(ind, buff, str);
			break ;
		}
		i++;
	}
}

void	ft_indicators_manager(t_indic **ind, t_buff **buff, char **str)
{
	ft_flags_manager(ind, buff, str);
	ft_precision_manager(ind, buff, str);
}
