/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c0_struct_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 14:58:03 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/23 18:42:13 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_init_indic(t_indic **ind)
{
	*ind = NULL;
	if (!((*ind) = (t_indic*)malloc(sizeof(t_indic))))
		return (-1);
	ft_bzero((*ind)->flags, 5 + 1);
	ft_bzero((*ind)->size, 2 + 1);
	(*ind)->width = 0;
	(*ind)->isprec = 0;
	(*ind)->precision = 0;
	return (1);
}

void	ft_free_indic(t_indic **ind)
{
	if (*ind)
		ft_memdel((void**)ind);
}

int		ft_init_buffer(t_buff **buff, int fd)
{
	*buff = NULL;
	if (!((*buff) = (t_buff*)malloc(sizeof(t_buff))))
		return (-1);
	(*buff)->size_max = 4096;
	if (!((*buff)->str = ft_strnew((*buff)->size_max)))
		return (-1);
	ft_bzero((*buff)->prefix, 3);
	(*buff)->suffix = NULL;
	(*buff)->sign_printed = 0;
	(*buff)->iszero = 0;
	(*buff)->printed = 0;
	(*buff)->index = 0;
	(*buff)->fd = fd;
	(*buff)->err = 0;
	return (1);
}

void	ft_free_buff(t_buff **buff)
{
	if (((*buff)->str))
		ft_strdel(&(*buff)->str);
	ft_strclr((*buff)->prefix);
	if (((*buff)->suffix))
		ft_strdel(&(*buff)->suffix);
	if (*buff)
		ft_memdel((void**)buff);
}

void	ft_reset_struct(t_indic **ind, t_buff **buff)
{
	ft_free_indic(ind);
	ft_strclr((*buff)->prefix);
	if (((*buff)->suffix))
		ft_strdel(&(*buff)->suffix);
	(*buff)->sign_printed = 0;
	(*buff)->iszero = 0;
	(*buff)->printed = 0;
}
