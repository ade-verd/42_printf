/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_ft_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 17:42:53 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/21 15:46:40 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list		ap;
	int			ret;
	int			fd;
	t_buff		*buff;

	fd = 1;
	va_start(ap, str);
	ft_init_buffer(&buff, fd);
	ft_parse_str(ap, (char*)str, &buff);
	if (buff->err != -1)
		ft_print_buffer(&buff);
	ret = buff->err != -1 ? buff->total : -1;
	ft_free_buff(&buff);
	va_end(ap);
	return (ret);
}

int		ft_dprintf(int fd, const char *str, ...)
{
	va_list		ap;
	int			ret;
	t_buff		*buff;

	va_start(ap, str);
	ft_init_buffer(&buff, fd);
	ft_parse_str(ap, (char*)str, &buff);
	if (buff->err != -1)
		ft_print_buffer(&buff);
	ret = buff->err != -1 ? buff->total : -1;
	ft_free_buff(&buff);
	va_end(ap);
	return (ret);
}

int		ft_sprintf(char **str, const char *fmt, ...)
{
	va_list		ap;
	int			ret;
	int 		fd;
	t_buff		*buff;

	fd = PRINT_IN_STRING;
	va_start(ap, fmt);
	ft_init_buffer(&buff, fd);
	ft_parse_str(ap, (char*)fmt, &buff);
	if (buff->err != -1)
		*str = ft_print_buffer(&buff);
	ret = buff->err != -1 ? buff->total : -1;
	ft_free_buff(&buff);
	va_end(ap);
	return (ret);
}

int		ft_vsprintf(char **str, const char *fmt, va_list ap)
{
	int			ret;
	int 		fd;
	t_buff		*buff;

	fd = PRINT_IN_STRING;
	ft_init_buffer(&buff, fd);
	ft_parse_str(ap, (char*)fmt, &buff);
	if (buff->err != -1)
		*str = ft_print_buffer(&buff);
	ret = buff->err != -1 ? buff->total : -1;
	ft_free_buff(&buff);
	printf("str:|%s|\n", *str);
	return (ret);
}

int		ft_vprintf(const char *str, va_list ap)
{
	int			ret;
	int			fd;
	t_buff		*buff;

	fd = 1;
	ft_init_buffer(&buff, fd);
	ft_parse_str(ap, (char*)str, &buff);
	if (buff->err != -1)
		ft_print_buffer(&buff);
	ret = buff->err != -1 ? buff->total : -1;
	ft_free_buff(&buff);
	return (ret);
}

int		ft_vdprintf(int fd, const char *str, va_list ap)
{
	int			ret;
	t_buff		*buff;

	ft_init_buffer(&buff, fd);
	ft_parse_str(ap, (char*)str, &buff);
	if (buff->err != -1)
		ft_print_buffer(&buff);
	ret = buff->err != -1 ? buff->total : -1;
	ft_free_buff(&buff);
	return (ret);
}
