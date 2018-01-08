/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 13:06:41 by ade-verd          #+#    #+#             */
/*   Updated: 2018/01/08 17:58:20 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_buffer(t_buff **buff)
{
	*buff = NULL;
	*buff = (t_buff*)malloc(sizeof(t_buff));
	(*buff)->str = ft_strnew(BUFF_MAX_SIZE);
	(*buff)->index = 0;
	(*buff)->total = 0;
}

void	ft_free_buff(t_buff **buff)
{
	ft_strdel((*buff)->str);
	ft_memdel((void**)buff);
}

void	ft_print_buffer(t_buff **buff, int fd)
{
	ft_putstr_fd((*buff)->str, fd);
	ft_strclr((*buff)->str);
	(*buff)->total = (*buff)->total + (*buff)->index;
	(*buff)->index = 0;
}

void	ft_putbuffer(t_buff **buff, char c, int fd)
{
	(*buff)->str[(*buff)->index] = c;
	(*buff)->index = (*buff)->index + 1;
	(*buff)->str[(*buff)->index] = '\0';
	if ((*buff)->index == BUFF_MAX_SIZE)
		ft_print_buffer(buff, fd);
}
