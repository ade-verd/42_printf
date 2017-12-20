/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_flag_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 13:09:43 by ade-verd          #+#    #+#             */
/*   Updated: 2017/12/20 15:22:07 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int		test_flag_d(int nb)
{
	t_txt	*t;
	char	*cyan;
	char	*none;

	none = "\033[0m";
	cyan = "\033[036m";
	if (!(t = (t_txt*)malloc(sizeof(*t))))
		return (-1);
	if ((t->fd = ft_redirect_stdout()) == -1)
		return (-1);
	t->my_ret = printf("Mine : %d\n", nb + 1); /*Adapter le flag et les args*/
	if ((ft_open_read_close(t->fd, &t->my_print, t->my_ret)) == -1)
		return (-1);
	t->off_ret = sprintf(t->trash, "Off  : %d\n", nb); /*Adapter le flag et les args*/
	t->off_print = ft_strnew(t->off_ret);
	sprintf(t->off_print, "Off  : %d\n", nb); /*Adapter le flag et les args*/
	printf("%s%s : %-10d%s", cyan, __func__, nb, none); /*Adapter le flag, la taille, et les args*/
	ft_compare(t->my_ret, t->off_ret, t->my_print + 6, t->off_print + 6);
	ft_memdel((void**)&t->my_print);
	ft_memdel((void**)&t->off_print);
	return (1);
}
