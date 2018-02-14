/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 14:12:59 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/14 14:49:55 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_iscapital_s(t_indic **ind)
{
	if ((*ind)->type == 'S')
    {
        (*ind)->type = 's';
		if ((*ind)->size)
		{
			(*ind)->size[0] = 'l';
			(*ind)->size[1] = '\0';
		}
		else
		{
			(*ind)->size = ft_strnew(1);
			(*ind)->size[0] = 'l';
        }
    }
}

int 	ft_wslen_bytes(t_indic **ind)
{
	int 	i;
	int 	bytes;
	int		nb_bits;

	i = 0;
	bytes = 0;
	while ((*ind)->ws[i])
	{
		nb_bits = ft_bitlen((*ind)->ws[i]);
		if (nb_bits <= 7)
			bytes += 1;
		else if (nb_bits <= 11)
			bytes += 2;
		else if (nb_bits <= 16)
			bytes += 3;
		else
			bytes += 4;
		if ((*ind)->precision && (*ind)->precision <= bytes)
			return (bytes);
		i++;
	}
	return (bytes);
}

void	ft_arg_string_ws(t_indic **ind, t_buff **buff)
{
	char 	*str;
	int 	i;
	int 	index;
	int 	bytes;

	bytes = ft_wslen_bytes(ind);
	i = 0;
	index = 0;
	if (!(str = ft_strnew(bytes)))
		exit (0);
	ft_bzero(str, bytes);
	while ((*ind)->ws[i])
	{
		ft_unicode_to_str(ind, &str, (*ind)->ws[i], &index);
		i++;
	}
	ft_indicators_manager(ind, buff, &str);
	if (str)
		ft_putsbuffer(buff, str);
	else
		ft_putsbuffer(buff, "(null)");
	if ((*buff)->suffix)
		ft_putsbuffer(buff, (*buff)->suffix);
}

void	ft_arg_string(va_list ap, t_indic **ind, t_buff **buff)
{
	char 	*str;

    ft_iscapital_s(ind);
	ft_get_string(ind, ap, &str);
	if ((*ind)->size && ft_strcmp((*ind)->size, "l") == 0)
		ft_arg_string_ws(ind, buff);
	else
	{
		ft_indicators_manager(ind, buff, &str);
		if (str)
			ft_putsbuffer(buff, str);
		else
			ft_putsbuffer(buff, "(null)");
		if ((*buff)->suffix)
			ft_putsbuffer(buff, (*buff)->suffix);
	}
}