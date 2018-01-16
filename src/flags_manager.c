/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:44:23 by ade-verd          #+#    #+#             */
/*   Updated: 2018/01/16 16:38:33 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_manage_plus (and nothing)
** The converted value is to be right ajusted.
** In case of no flag and width > 0 : str is right ajusted by default according
** to width and str's length
** In case of '+' : '+' is displayed (always)
** In case of '-'&'+' (whatever order) : '+' is displayed str is left ajusted
** In case of '0'&'+'  : '+' is displayed, then zero, then str
*/

void	ft_manage_plus(t_indic **ind, t_buff **buff, char **str)
{
	int		width;
	int		len;
	int		i;
	int		isminus_or_is0;

	width = (*ind)->width - (*buff)->sign_printed;
	len = ft_strlen(*str);
	i = 0;
	isminus_or_is0 = 0;
	if ((*ind)->flags && (ft_strchr_pos((*ind)->flags, '-') != -1
			|| ft_strchr_pos((*ind)->flags, '0') != -1))
		isminus_or_is0 = 1;
	if ((*ind)->flags && ft_strchr_pos((*ind)->flags, '+') != -1
			&& ft_atoi(*str) > 0 && (*buff)->sign_printed == 0)
		len++;
	while (i++ < (width - len) && isminus_or_is0 != 1)
		ft_putcbuffer(buff, ' ');
	if ((*ind)->flags && ft_strchr_pos((*ind)->flags, '+') != -1
			&& ft_atoi(*str) >= 0 && (*buff)->sign_printed == 0)
	{
		ft_putcbuffer(buff, '+');
		(*buff)->sign_printed = 1;
	}
}

/*
** ft_manage_minus
** The converted value is to be left adjusted.
** Except for n conversions, the converted value is padded on the right
** with blanks.
** If the 0 and - flags both appear, the 0 flag is ignored.
*/

void	ft_manage_minus(t_indic **ind, t_buff **buff, char **str)
{
	int		width;
	int		len;
	int		i;

	if (!(*ind)->flags || !(*ind)->width
			|| ft_strchr_pos((*ind)->flags, '-') == -1)
		return ;
	width = (*ind)->width - (*buff)->sign_printed;
	len = ft_strlen(*str);
	i = 0;
	if ((*ind)->type == 'n')
	{
		while (i++ < (width - len))
			ft_putcbuffer(buff, ' ');
	}
	else
	{
		if (width > len)
		{
			(*buff)->suffix = ft_strnew(width - len);
			while (i < (width - len))
				(*buff)->suffix[i++] = ' ';
		}
	}
}

/*
** ft_print_sign_before
** Print sign before 0
** Types à compléter
*/

void	ft_print_sign_before(t_indic **ind, t_buff **buff, char **str)
{
	int		nb_ref;

	nb_ref = (*buff)->index;
	if ((*ind)->type && ft_strchr("diouxX", (*ind)->type))
	{
		if ((*ind)->flags && ft_strchr((*ind)->flags, '0'))
		{
			if (ft_atoi(*str) <= 0 && *str[0] == '-')
				ft_putcbuffer(buff, '-');
			if (ft_atoi(*str) >= 0 && *str[0] == '+')
				ft_putcbuffer(buff, '+');
		}
	}
	if (nb_ref < (*buff)->index && ft_strchr_pos("+-", *str[0]) != -1)
	{
		(*str)++;
		(*buff)->sign_printed = 1;
	}
}

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

	if (!(*ind)->flags || !(*ind)->width
			|| (ft_strchr_pos((*ind)->flags, '0') == -1)
			|| (ft_strchr_pos((*ind)->flags, '-') != -1))
		return ;
	if ((*ind)->precision && ft_strchr("diouxX", (*ind)->type))
		return ;
	width = (*ind)->width - (*buff)->sign_printed;
	len = ft_strlen(*str);
	i = 0;
	while (i < (width - len))
	{
		ft_putcbuffer(buff, '0');
		i++;
	}
}
