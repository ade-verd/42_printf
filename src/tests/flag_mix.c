/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_mix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 11:42:45 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/19 13:14:08 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int		ft_flag_mix(void)
{
	ft_init_counters();
	printf("*** Mix Flags ***\n");

	STOPIF0(ft_call_both("s: %s, p: %p, d:%d", "a string", &__FUNCTION__, 42));
	STOPIF0(ft_call_both("%s%p%d%d%p%s%p |%p| %s",
	 "a", &free, 1, 2, &malloc, "b", &free, &malloc, "c"));

	printf("\n*** Mix Flags [%d/%d] ***\n", g_counter_ok, g_counter_ok + g_counter_ko);
	return (1);
}