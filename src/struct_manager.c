/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 14:58:03 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/19 12:29:13 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_indic(t_indic **ind)
{
	*ind = NULL;
	*ind = (t_indic*)malloc(sizeof(t_indic));
	(*ind)->width = 0;
	(*ind)->isprec = 0;
	(*ind)->precision = 0;
}

void	ft_free_indic(t_indic **ind)
{
	if ((*ind)->flags)
		ft_strdel(&(*ind)->flags);
	if ((*ind)->size)
		ft_strdel(&(*ind)->size);
	if (*ind)
		ft_memdel((void**)ind);
}

void	ft_init_buffer(t_buff **buff, int fd)
{
	*buff = NULL;
	*buff = (t_buff*)malloc(sizeof(t_buff));
	(*buff)->str = ft_strnew(BUFF_MAX_SIZE);
	(*buff)->prefix = NULL;
	(*buff)->suffix = NULL;
	(*buff)->sign_printed = 0;
	(*buff)->iszero = 0;
	(*buff)->printed = 0;
	(*buff)->index = 0;
	(*buff)->total = 0;
	(*buff)->fd = fd;
	(*buff)->err = 0;
}

void	ft_free_buff(t_buff **buff)
{
	if (((*buff)->str))
		ft_strdel(&(*buff)->str);
	if (((*buff)->prefix))
		(*buff)->prefix = "\0\0";
	if (((*buff)->suffix))
		ft_strdel(&(*buff)->suffix);
	if (*buff)
		ft_memdel((void**)buff);
}

void	ft_reset_struct(t_indic **ind, t_buff **buff)
{
	ft_free_indic(ind);
	if (((*buff)->prefix))
		(*buff)->prefix = "\0\0";
	if (((*buff)->suffix))
		ft_strdel(&(*buff)->suffix);
	(*buff)->sign_printed = 0;
	(*buff)->iszero = 0;
	(*buff)->printed = 0;
}