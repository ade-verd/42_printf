/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 17:42:53 by ade-verd          #+#    #+#             */
/*   Updated: 2017/12/20 18:27:24 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**ft_init_dataarray(void)
{
	static const char tab_ft[] = {
		{ "bdiouxX", int_arg },
		{ "DOU", dou_arg },
		{ "Cc", c_arg },
		{ "s", s_arg },
		{ "S", ws_arg },
		{ "p", p_arg },
		{ "%", pct_arg }
		};
	return (tab_ft);
}


int		ft_printf(const char *format, ...)
{
	
}
