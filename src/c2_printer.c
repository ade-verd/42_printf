/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c2_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 13:06:41 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/23 18:40:28 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_putinstr_buffer(t_buff **buff)
{
	char	*str;
	int		size;

	size = (*buff)->index < 0 ? 1 : (*buff)->index;
	if (!(str = ft_strnew(size)))
	{
		(*buff)->err = -1;
		return (NULL);
	}
	return (ft_strncpy(str, (*buff)->str, size + 1));
}

void	ft_double_buffsize(t_buff **buff)
{
	char	tmp[(*buff)->size_max];

	ft_strcpy(tmp, (*buff)->str);
	ft_strdel(&(*buff)->str);
	(*buff)->size_max *= 2;
	if (!((*buff)->str = ft_strnew((*buff)->size_max)))
	{
		ft_error_manager(buff);
		return ;
	}
	ft_strcpy((*buff)->str, tmp);
}

void	ft_putcbuffer(t_buff **buff, char c)
{
	(*buff)->str[(*buff)->index] = c;
	(*buff)->index++;
	(*buff)->str[(*buff)->index] = '\0';
	(*buff)->printed++;
	if ((*buff)->index == (*buff)->size_max)
		ft_double_buffsize(buff);
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
