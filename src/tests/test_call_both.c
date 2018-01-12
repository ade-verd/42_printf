/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_indics.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:00:48 by ade-verd          #+#    #+#             */
/*   Updated: 2018/01/12 12:23:56 by ade-verd         ###   ########.fr       */
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
	if ((t->fd = ft_redirect_stdout()) == -1)
		return (-1);
	t->my_ret = ft_vprintf(str, ap);
	if ((ft_open_read_close(t->fd, &t->my_print, t->my_ret)) == -1)
		return (-1);
	t->off_print = ft_strnew(t->my_ret + 1000);
	t->off_ret = vsprintf(t->off_print, str, ap2);
	ret = ft_compare(t->my_ret, t->off_ret, t->my_print, t->off_print, str);
	ft_memdel((void**)&t->my_print);
	ft_memdel((void**)&t->off_print);
	va_end(ap);
	if(ret == 0)
		ft_putstr_fd("*** execution stopped (check above) ***\n", 2);
	return (ret);
}
