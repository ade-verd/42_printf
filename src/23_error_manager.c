/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   23_error_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:18:01 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/21 13:42:45 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_error_manager(t_buff **buff)
{
	(*buff)->err = -1;
	ft_strclr((*buff)->str);
}