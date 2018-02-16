/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_manager_part1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 17:58:47 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/16 15:56:08 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_manage_plus_signed (and nothing)
** The converted value is to be right ajusted.
** In case of no flag and width > 0 : str is right ajusted by default according
** to width and str's length
** In case of '+' : '+' is displayed (always)
** In case of '-'&'+' (whatever order) : '+' is displayed str is left ajusted
** In case of '0'&'+'  : '+' is displayed, then zero, then str
*/

void	ft_manage_plus_signed(t_indic **ind, t_buff **buff, char **str)
{
	int		w;
	int		n;
	int		i;
	int		isminus_or_is0;

	n = ft_strchr("+-", *str[0]) ? ft_strlen(*str) - 1 : ft_strlen(*str);
	w = ((*ind)->precision - n <= 0) ? ((*ind)->width - (*buff)->sign_printed)
			: ((*ind)->width - (*buff)->sign_printed - ((*ind)->precision - n));
	n = ft_strlen(*str);
	i = 0;
	isminus_or_is0 = 0;
	if ((*ind)->flags && (ft_strchr((*ind)->flags, '-')
			|| (ft_strchr((*ind)->flags, '0') && (*ind)->isprec == 0)))
		isminus_or_is0 = 1;
	if ((*ind)->flags && ft_strchr((*ind)->flags, '+')
			&& (*ind)->nb > 0 && (*buff)->sign_printed == 0)
		n++;
	while (i++ < (w - n) && isminus_or_is0 != 1)
		ft_putcbuffer(buff, ' ');
	if ((*ind)->flags && ft_strchr((*ind)->flags, '+')
			&& (*ind)->nb >= 0 && (*buff)->sign_printed == 0)
	{
		ft_putcbuffer(buff, '+');
		(*buff)->sign_printed++;
	}
}

/*
** ft_manage_plus_unsigned (and nothing)
** The converted value is to be right ajusted.
** In case of no flag and width > 0 : str is right ajusted by default according
** to width and str's length
*/

void	ft_manage_plus_unsigned(t_indic **ind, t_buff **buff, char **str)
{
	int		w;
	int		n;
	int		i;
	int		isminus_or_is0;

	n = ft_strlen(*str);
	w = ((*ind)->precision - n <= 0) ? ((*ind)->width - (*buff)->sign_printed)
		: ((*ind)->width - (*buff)->sign_printed - ((*ind)->precision - n));
	if ((*ind)->type == 's')
	{
		n = ((*ind)->precision - n) <= 0 ? n - (*ind)->precision : n;
		w = (*ind)->width;
	}
	i = 0;
	isminus_or_is0 = 0;
	if ((*ind)->flags && (ft_strchr((*ind)->flags, '-')
			|| (ft_strchr((*ind)->flags, '0') && (*ind)->isprec == 0)))
		isminus_or_is0 = 1;
	while (i++ < (w - n) && isminus_or_is0 != 1)
		ft_putcbuffer(buff, ' ');
}

void	ft_manage_minus(t_indic **ind, t_buff **buff, char **str)
{
	int		w;
	int		n;
	int		i;

	if (!(*ind)->flags || !(*ind)->width || !ft_strchr((*ind)->flags, '-'))
		return ;
	w = (*ind)->width;
	n = ft_strlen(*str) + (*buff)->printed;
	i = 0;
	if ((*ind)->type == 'n')
	{
		while (i++ < (w - n))
			ft_putcbuffer(buff, ' ');
	}
	else
	{
		if (w > n)
		{
			(*buff)->suffix = ft_strnew(w - n);
			while (i < (w - n))
				(*buff)->suffix[i++] = ' ';
		}
	}
}

/*
** ft_print_sign_before
** Print sign '+' '-' before 0 or str
** Flag ' ' (whitespace) is managed here
*/

void	ft_print_sign_before(t_indic **ind, t_buff **buff, char **str)
{
	int		nb_ref;

	nb_ref = (*buff)->index;
	if ((*ind)->type && ft_strchr("di", (*ind)->type))
	{
		if ((*ind)->flags && ft_strchr((*ind)->flags, '0') 
				&& (*ind)->isprec == 0)
		{
			if ((*ind)->nb <= 0 && *str[0] == '-')
				ft_putcbuffer(buff, '-');
			if ((*ind)->nb >= 0 && *str[0] == '+')
				ft_putcbuffer(buff, '+');
		}
		if ((*ind)->flags && ft_strchr((*ind)->flags, ' ') && *str[0] != '+'
				&& !ft_strchr((*ind)->flags, '+') && *str[0] != '-')
		{
			ft_putcbuffer(buff, ' ');
			(*buff)->sign_printed++;
		}
	}
	if (nb_ref != (*buff)->index && ft_strchr_pos("+-", *str[0]) != -1)
	{
		(*str)++;
		(*buff)->sign_printed++;
	}
}