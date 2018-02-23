/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a0_ft_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 17:42:53 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/23 17:48:15 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list		ap;
	int			ret;

	va_start(ap, str);
	ret = ft_vprintf(str, ap);
	va_end(ap);
	return (ret);
}

int		ft_dprintf(int fd, const char *str, ...)
{
	va_list		ap;
	int			ret;

	va_start(ap, str);
	ret = ft_vdprintf(fd, str, ap);
	va_end(ap);
	return (ret);
}

int		ft_fprintf(FILE *file, const char *str, ...)
{
	va_list		ap;
	int			ret;

	va_start(ap, str);
	ret = ft_vfprintf(file, str, ap);
	va_end(ap);
	return (ret);
}

int		ft_asprintf(char **str, const char *fmt, ...)
{
	va_list		ap;
	int			ret;

	va_start(ap, fmt);
	ret = ft_vasprintf(str, fmt, ap);
	va_end(ap);
	return (ret);
}
