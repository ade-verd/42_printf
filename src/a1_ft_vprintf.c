/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a1_ft_vprintf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 17:42:53 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/23 18:45:45 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_vprintf(const char *str, va_list ap)
{
	int			ret;
	int			fd;
	t_buff		*buff;

	fd = 1;
	if ((ft_init_buffer(&buff, fd) == -1))
		return (-1);
	ft_parse_str(ap, (char*)str, &buff);
	if (buff->err != -1)
		write(fd, buff->str, buff->index);
	ret = buff->err != -1 ? buff->index : -1;
	ft_free_buff(&buff);
	return (ret);
}

int		ft_vdprintf(int fd, const char *str, va_list ap)
{
	int			ret;
	t_buff		*buff;

	if ((ft_init_buffer(&buff, fd) == -1))
		return (-1);
	ft_parse_str(ap, (char*)str, &buff);
	if (buff->err != -1)
		write(fd, buff->str, buff->index);
	ret = buff->err != -1 ? buff->index : -1;
	ft_free_buff(&buff);
	return (ret);
}

int		ft_vfprintf(FILE *file, const char *str, va_list ap)
{
	int			ret;
	t_buff		*buff;

	if ((ft_init_buffer(&buff, 1) == -1))
		return (-1);
	ft_parse_str(ap, (char*)str, &buff);
	if (buff->err != -1)
		fwrite(buff->str, 1, buff->index, file);
	ret = buff->err != -1 ? buff->index : -1;
	ft_free_buff(&buff);
	return (ret);
}

int		ft_vasprintf(char **str, const char *fmt, va_list ap)
{
	int			ret;
	int			fd;
	t_buff		*buff;

	fd = PRINT_IN_STRING;
	if ((ft_init_buffer(&buff, fd) == -1))
		return (-1);
	ft_parse_str(ap, (char*)fmt, &buff);
	*str = ft_putinstr_buffer(&buff);
	ret = buff->err != -1 ? buff->index : -1;
	ft_free_buff(&buff);
	return (ret);
}
