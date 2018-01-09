/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 17:42:53 by ade-verd          #+#    #+#             */
/*   Updated: 2018/01/09 14:37:32 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const t_conv g_tab[] = {
	{ "bdiouxX", ft_int_arg }
/*	{ "DOU", ft_dou_arg },
	{ "Cc", ft_c_arg },
	{ "s", ft_s_arg },
	{ "S", ft_ws_arg },
	{ "p", ft_p_arg },
	{ "%", ft_pct_arg }
*/	};

int		ft_printf(const char *str, ...)
{
	va_list		ap;
	int			*ret;
	int			fd;

	fd = 1;
	va_start(ap, str);
	ft_parse_str(ap, str, ret, fd);
	va_end(ap);
	return (ret);
}
