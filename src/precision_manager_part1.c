/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_manager_part1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:49:33 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/15 15:38:56 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_del_str(t_indic **ind, char **str)
{
	if ((*ind)->flags && ft_strchr((*ind)->flags, '#') && (*ind)->type == 'o')
		return ;
	ft_strclr(*str);
	(*ind)->width > 0 ? str[0] = " " : str[0];
}

void	ft_precision_int(t_indic **ind, t_buff **buff, char **str)
{
	int		i;
	int		prec;
	int		len;

	i = 0;
	prec = (*ind)->precision - (*buff)->iszero;
	if ((*ind)->isprec == 1 && prec == 0 && (*ind)->nb == 0)
		ft_del_str(ind, str);
	else
	{
		if ((*ind)->nb <= 0 && *str[0] == '-')
		{
			ft_putcbuffer(buff, '-');
			(*buff)->sign_printed++;
			(*str)++;
		}
		len = ft_strchr("+-", *str[0]) ? ft_strlen(*str) - 1 : ft_strlen(*str);
		while (i++ < (prec - len))
			ft_putcbuffer(buff, '0');
	}
}

void	ft_precision_string(t_indic **ind, t_buff **buff, char **str)
{
	int 	i;
	int		len;

	i = 0;
	len = ft_strlen(*str);
	(*buff)->total += 0; 
	if ((*ind)->precision && (*ind)->precision < len)
	{
		while ((*str)[i])
			i++;
		while (i >= 0 && i >= (*ind)->precision)
		{
			(*str)[i] = '\0';
			i--;
		}
	}
}