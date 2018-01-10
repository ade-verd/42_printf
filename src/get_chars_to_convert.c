/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_chars_to_convert.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 10:42:04 by ade-verd          #+#    #+#             */
/*   Updated: 2018/01/10 14:54:17 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_get_flags(t_indic **ind, char *str, int *i)
{
	int		j;
	int		k;

	j = 0;
	k = 0;
	while (str[*i + j] && ft_strchr_pos("#0+- ", str[*i + j]) != -1)
		j++;
	if (j > 0)
		(*ind)->flags = ft_strnew(j);
	else
		(*ind)->flags = NULL;
	while (j--)
		(*ind)->flags[k++] = str[(*i)++];
}

/* voir comment gerer avec *1$ (n$ reordering output), lorsqu'un argument n est imposé  */
/* voir comment gerer le ? point d'interrogation */
void	ft_get_width(t_indic **ind, va_list ap, char *str, int *i)
{
	if (str[*i] == '*')
	{
		(*ind)->width = va_arg(ap, int);
			(*i)++;
	}
	else
	{
		(*ind)->width = ft_atoi(str + *i);
		while (str[*i] && ft_isdigit(str[*i]) == 1)
			(*i)++;
	}
}

/* voir comment gerer avec *1$ (n$ reordering output), lorsqu'un argument n est imposé  */
void	ft_get_precision(t_indic **ind, va_list ap, char *str, int *i)
{
	if (str[*i] && str[*i] == '.')
	{
		(*i)++;
		if (str[*i] && str[*i] == '*')
		{
			(*ind)->precision = va_arg(ap, int);
			(*i)++;
		}
		else
		{
			(*ind)->precision = ft_atoi(str + *i);
			while (str[*i] && ft_isdigit(str[*i]) == 1)
				(*i)++;
		}
	}
}

void	ft_get_size(t_indic **ind, char *str, int *i)
{
	int		j;
	int		k;

	j = 0;
	k = 0;
	if (str[*i] && ft_strchr_pos("hljzL", str[*i]) != -1)
	{
		j++;
		if ((str[*i] == 'h' || str[*i] == 'l') && (str[*i] == str[*i + 1]))
			j++;
		(*ind)->size = ft_strnew(j);
	}
	else
		(*ind)->size = NULL;
	while (j--)
		(*ind)->size[k++] = str[(*i)++];
}
