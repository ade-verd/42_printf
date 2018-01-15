/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indicators_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:58:47 by ade-verd          #+#    #+#             */
/*   Updated: 2018/01/15 18:36:36 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flags_manager(t_indic **ind, t_buff **buff, char *str)
{
	ft_manage_plus(ind, buff, str);
	ft_manage_minus(ind, buff, str);
	ft_manage_zero(ind, buff, str);
}

void	ft_indicators_manager(t_indic **ind, t_buff **buff, char *str)
{
	ft_flags_manager(ind, buff, str);
}
