/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 17:42:53 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/02 15:43:45 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list		ap;
	int			ret;
	int			fd;

	fd = 1;
	va_start(ap, str);
	ft_parse_str(ap, (char*)str, &ret, fd);
	va_end(ap);
	return (ret);
}

int		ft_dprintf(int fd, const char *str, ...)
{
	va_list		ap;
	int			ret;

	va_start(ap, str);
	ft_parse_str(ap, (char*)str, &ret, fd);
	va_end(ap);
	return (ret);
}

int		ft_vprintf(const char *str, va_list ap)
{
	int			ret;
	int			fd;

	fd = 1;
	ft_parse_str(ap, (char*)str, &ret, fd);
	return (ret);
}

int		ft_vdprintf(int fd, const char *str, va_list ap)
{
	int			ret;

	ft_parse_str(ap, (char*)str, &ret, fd);
	return (ret);
}
