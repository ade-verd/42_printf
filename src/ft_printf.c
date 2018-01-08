/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 17:42:53 by ade-verd          #+#    #+#             */
/*   Updated: 2018/01/08 14:06:28 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_conv	*ft_init_dataarray(void)
{
	static const t_conv tab_ft[] = {
		{ "bdiouxX", ft_int_arg }
/*		{ "DOU", ft_dou_arg },
		{ "Cc", ft_c_arg },
		{ "s", ft_s_arg },
		{ "S", ft_ws_arg },
		{ "p", ft_p_arg },
		{ "%", ft_pct_arg }
*/		};
	return (tab_ft);
}

int		

int		ft_printf(const char *str, ...)
{
	va_list		ap;
	t_conv		tab_ft;
	int			*ret;
	int			fd;

	fd = 1;
	tab_ft = ft_init_dataarray();
	va_start(ap, str);
	ft_parse_str(ap, str, ret, fd);
	va_end(ap);
	return (ret);
}
