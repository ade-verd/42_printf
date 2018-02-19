/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode_converter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:21:21 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/19 19:03:02 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void 	ft_convert_unicode(t_indic **ind, char **byte, int *i)
{
	int 	nb_bits;

	nb_bits = ft_bitlen((*ind)->c);
	if (nb_bits <= 7)
		(*byte)[(*i)++] = (*ind)->c;
	else if (nb_bits <= 11)
	{
		(*byte)[(*i)++] = MASK_BYTE01 | ((*ind)->c >> 6 & RMASK_BYTE01);
		(*byte)[(*i)++] = MASK_BYTE10 | ((*ind)->c & RMASK_BYTE10);
	}
	else if (nb_bits <= 16)
	{
		(*byte)[(*i)++] = MASK_BYTE02 | ((*ind)->c >> 12 & RMASK_BYTE02);
		(*byte)[(*i)++] = MASK_BYTE10 | ((*ind)->c >> 6 & RMASK_BYTE10);
		(*byte)[(*i)++] = MASK_BYTE10 | ((*ind)->c & RMASK_BYTE10);
	}
	else
	{
		(*byte)[(*i)++] = MASK_BYTE03 | ((*ind)->c >> 18 & RMASK_BYTE03);
		(*byte)[(*i)++] = MASK_BYTE10 | ((*ind)->c >> 12 & RMASK_BYTE10);
		(*byte)[(*i)++] = MASK_BYTE10 | ((*ind)->c >> 6 & RMASK_BYTE10);
		(*byte)[(*i)++] = MASK_BYTE10 | ((*ind)->c & RMASK_BYTE10);
	}
}

void 	ft_checkprecis_and_erase(t_indic** ind, char **str, int *i, int i_ref)
{
	if ((*ind)->type == 's' && (*ind)->isprec == 1 && *i > (*ind)->precision)
	{
		while ((*str)[i_ref])
		{
			(*str)[i_ref] = '\0';
			i_ref++;
		}
	}
}
void	ft_weard_behavior_on_mac(t_indic **ind, t_buff **buff, char **str)
{
	if ((*ind)->c >= 0xD800 && (*ind)->c <= 0xDFFF)
	{
		ft_error_manager(buff);
		*str[0] = '\0'; 
	}
}

void 	ft_unicode_to_str(t_indic **ind, t_buff **buff, char **str, int *i)
{
	int 	i_ref;

	i_ref = *i;
	if ((*ind)->size && ft_strcmp((*ind)->size, "l") == 0)
	{
		ft_convert_unicode(ind, str, i);
		ft_checkprecis_and_erase(ind, str, i, i_ref);
		ft_weard_behavior_on_mac(ind, buff, str);
	}
	else
		(*str)[(*i)++] = (*ind)->c;
}