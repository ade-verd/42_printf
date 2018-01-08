/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 13:07:08 by ade-verd          #+#    #+#             */
/*   Updated: 2018/01/08 17:58:21 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_str(va_list ap, char *str, int *ret, int fd)
{
	int		i;
	t_buff	*buff;
	t_conv	*conv;

	i = 0;
	ft_init_buffer(&buff);
	while (str[i])
	{
		if (str[i] == '%')
			ft_get_flags(str + i);
			//ft_get_width();
			//ft_get_precision();
			//ft_get_size();
			//ft_get_type();
		else
			ft_putbuffer(&buff, str[i], fd);
		i++;
	}
	ret = (*buff->total);
	ft_free_buff(&buff);
}

