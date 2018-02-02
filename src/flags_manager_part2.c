/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_manager_part2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 11:01:17 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/02 13:29:19 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_hashtag_oxX
** When type is o, x or X, and the value is not 0, 
** the converted value is prefixed respectively by 0 (o), "0x" (x) or "0X" (X)
*/

void	ft_hashtag_oxx(t_indic **ind, t_buff **buff, char **str)
{
	int		base;

	base = (*ind)->type == 'o' ? 10 : 16;
	if (ft_uatoi_base(*str, base) == 0)
		return ;
	if ((*ind)->type == 'o')
	{
		(*buff)->prefix = "0";
		(*buff)->iszero++;
		(*buff)->sign_printed++;
	}
	if ((*ind)->type == 'x' || (*ind)->type == 'X')
	{
		(*buff)->prefix = (*ind)->type == 'x' ? "0x" : "0X";
		(*buff)->sign_printed += 2;
	}
}

/*
void	ft_hashtag_eeffaa(t_indic **ind, t_buff **buff, char **str)
{
}
*/

/*
void	ft_hashtag_gg(t_indic **ind, t_buff **buff, char **str)
{
}
*/

/*
** ft_manage_hashtag
*/

static const t_ft	g_ft[] = {
		{"oxX", NULL, ft_hashtag_oxx, NULL},
	//	{"eEfFaA", NULL, ft_hashtag_eeffaa, NULL},
	//	{"gG", NULL, ft_hashtag_gg, NULL},
	{0, 0, 0, 0}
};

void	ft_manage_hashtag(t_indic **ind, t_buff **buff, char **str)
{
	int		i;

	i = 0;
	if ((*ind)->flags && ft_strchr((*ind)->flags, '#'))
	{
		while (g_ft[i].letter)
		{
			if ((*ind)->type && ft_strchr(g_ft[i].letter, (*ind)->type))
			{
				g_ft[i].f2(ind, buff, str);
				break ;
			}
			i++;
		}
	}
}
