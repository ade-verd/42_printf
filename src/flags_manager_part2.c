/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_manager_part2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 11:01:17 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/19 12:28:21 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_manage_zero
** The converted value is padded on the left with zeros.
** If the 0 and - flags both appear, the 0 flag is ignored.
** If a precision is given with a numeric conversion (d, i, o, u, x, and X),
** the 0 flag is ignored. For other conversions, the behavior is undefined.
*/

void	ft_manage_zero(t_indic **ind, t_buff **buff, char **str)
{
	int		width;
	int		len;
	int		i;

	if (!(*ind)->flags || !(*ind)->width || !ft_strchr((*ind)->flags, '0')
			|| ft_strchr((*ind)->flags, '-'))
		return ;
	if ((*ind)->isprec == 1 && ft_strchr("bpdiouxX", (*ind)->type))
		return ;
	width = (*ind)->width - (*buff)->sign_printed;
	len = ft_strlen(*str);
	i = 0;
	while (i < (width - len))
	{
		ft_putcbuffer(buff, '0');
		(*buff)->iszero++;
		(*buff)->sign_printed++;
		i++;
	}
}

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
		(*buff)->prefix = "0\0";
		(*buff)->iszero++;
		(*buff)->sign_printed++;
	}
	else
	{
		(*buff)->prefix = (*ind)->type == 'X' ? "0X" : "0x";
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


void	ft_manage_hashtag(t_indic **ind, t_buff **buff, char **str)
{
	const t_ft	g_ft[] = {
		{"oxX", NULL, ft_hashtag_oxx, NULL, NULL},
	//	{"eEfFaA", NULL, ft_hashtag_eeffaa, NULL, NULL},
	//	{"gG", NULL, ft_hashtag_gg, NULL, NULL},
		{0, 0, 0, 0, 0}
	};
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
