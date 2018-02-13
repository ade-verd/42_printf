/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 13:06:41 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/13 11:58:03 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
}

void	ft_free_buff(t_buff **buff)
{
	if (((*buff)->str))
		ft_strdel(&(*buff)->str);
	if (((*buff)->suffix))
		ft_strdel(&(*buff)->suffix);
	if (*buff)
		ft_memdel((void**)buff);
}

void	ft_print_buffer(t_buff **buff)
{
	write((*buff)->fd, (*buff)->str, (*buff)->index);
	ft_strclr((*buff)->str);
	(*buff)->total = (*buff)->total + (*buff)->index;
	(*buff)->index = 0;
}

void	ft_putcbuffer(t_buff **buff, char c)
{
	(*buff)->str[(*buff)->index] = c;
	(*buff)->index++;
	(*buff)->str[(*buff)->index] = '\0';
	(*buff)->printed++;
	if ((*buff)->index == BUFF_MAX_SIZE)
		ft_print_buffer(buff);
}

void	ft_putsbuffer(t_buff **buff, char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_putcbuffer(buff, str[i]);
		i++;
	}
}
