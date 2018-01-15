/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:44:23 by ade-verd          #+#    #+#             */
/*   Updated: 2018/01/15 17:54:55 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_manage_plus
*/

void	ft_manage_plus(t_indic **ind, t_buff **buff, char *str)
{
	int		width;
	int		len;
	int		i;
	int		isminus_or_iszero;

	width = (*ind)->width;
	len = ft_strlen(str);
	i = 0;
	isminus_or_iszero = 0;
	if ((*ind)->flags && (ft_strchr_pos((*ind)->flags, '-') != -1
			|| ft_strchr_pos((*ind)->flags, '0') != -1))
		isminus_or_iszero = 1;
	if ((*ind)->flags && ft_strchr_pos((*ind)->flags, '+') != -1)
		len++;
	while (i++ < (width - len) && isminus_or_iszero != 1)
		ft_putcbuffer(buff, ' ');
	if ((*ind)->flags && ft_strchr_pos((*ind)->flags, '+') != -1)
		ft_putcbuffer(buff, '+');
}

/*
** ft_manage_minus
** The converted value is to be left adjusted. 
** Except for n conversions, the converted value is padded on the right 
** with blanks.
** If the 0 and - flags both appear, the 0 flag is ignored.
*/

void	ft_manage_minus(t_indic **ind, t_buff **buff, char *str)
{
	int		len;
	int		i;

	if (!(*ind)->flags || !(*ind)->width
			|| ft_strchr_pos((*ind)->flags, '-') == -1)
		return ;
	len = ft_strlen(str);
	i = 0;
	if ((*ind)->flags && ft_strchr_pos((*ind)->flags, '+') != -1)
		len++;
	if ((*ind)->type == 'n')
	{
		while (i++ < ((*ind)->width - len))
			ft_putcbuffer(buff, ' ');
	}
	else
	{
		if ((*ind)->width > len)
		{
			(*buff)->suffix = ft_strnew((*ind)->width - len);
			while (i < ((*ind)->width - len))
				(*buff)->suffix[i++] = ' ';
		}
	}
}

/*
** ft_manage_zero
** The converted value is padded on the left with zeros.
** If the 0 and - flags both appear, the 0 flag is ignored.
** If a precision is given with a numeric conversion (d, i, o, u, x, and X),
** the 0 flag is ignored. For other conversions, the behavior is undefined.
*/

void	ft_manage_zero(t_indic **ind, t_buff **buff, char *str)
{
	int		width;
	int		len;
	int		i;

	if (!(*ind)->flags || !(*ind)->width
			|| (ft_strchr_pos((*ind)->flags, '0') == -1)
			|| (ft_strchr_pos((*ind)->flags, '-') != -1))
		return ;
	if ((*ind)->precision && ft_strchr("diouxX", (*ind)->type))
		return ;
	width = (*ind)->width;
	len = ft_strlen(str);
	i = 0;
	if ((*ind)->flags && ft_strchr_pos((*ind)->flags, '+') != -1)
		len++;
	while (i < (width - len))
	{
		ft_putcbuffer(buff, '0');
		i++;
	}
}
