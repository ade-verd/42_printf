/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_both.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 09:49:55 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/15 13:12:56 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int		ft_call_both(char *str, ...)
{
	t_txt	*t;
	va_list	ap;
	va_list	ap2;
	int		ret;

	va_start(ap, str);
	va_copy(ap2, ap);
	if (!(t = (t_txt*)malloc(sizeof(*t))))
		return (-1);
	if ((t->fd = ft_open(TMP_OUT, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR)) == -1)
		return (-1);
	t->my_ret = ft_vdprintf(t->fd, str, ap);
	if ((ft_read_fd(t->fd, &t->my_print, ft_abs(t->my_ret))) == -1)
		return (-1);
	t->off_print = ft_strnew(ft_abs(t->my_ret) + 1000);
	t->off_ret = vsprintf(t->off_print, str, ap2);
	ret = ft_compare(t->my_ret, t->off_ret, t->my_print, t->off_print, str);
	if ((ft_close(t->fd)) == -1)
		return (-1);
	if ((ft_remove(TMP_OUT)) == -1)
		return (-1);
	ft_memdel((void**)&t->my_print);
	ft_memdel((void**)&t->off_print);
	va_end(ap);
	if(ret == 0)
		ft_putstr_fd("*** execution stopped (check above) ***\n", 2);
	return (ret);
}
