/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_b_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 17:47:58 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/05 19:17:33 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

char	*ft_change_type(char *str, char origin, char to)
{
	int		i;
	int		j;
	char	*str2;

	i = 0;
	j = 0;
	str2 = ft_strdup(str);
	while (str2[i])
	{
		if (str2[i] == '%')
		{
			if ((j = ft_strchr_pos(str + i, origin)) >= 0)
				str2[i + j] = to;
		}
		i++;
	}
	return (str2);
}

int		ft_call_both_binary(char *str, ...)
{
	t_txt	*t;
	va_list	ap;
	va_list	ap2;
	char	*str2;
	int		ret;
	uintmax_t test;
	char *test2;

	va_start(ap, str);
	va_copy(ap2, ap);
	if (!(t = (t_txt*)malloc(sizeof(*t))))
		return (-1);
	if ((t->fd = ft_open(TMP_OUT, O_RDWR | O_CREAT |
					O_APPEND, S_IRUSR | S_IWUSR)) == -1)
		return (-1);
	t->my_ret = ft_vdprintf(t->fd, str, ap);
	if ((ft_read_fd(t->fd, &t->my_print, t->my_ret)) == -1)
		return (-1);
	t->off_print = ft_strnew(t->my_ret + 1000);
	str2 = ft_change_type(str, 'b', 's');
	test = va_arg(ap2, intmax_t);
	//printf("i:|%jd|\n",test);
	test2 = ft_uitoa_base(test, 2);
	t->off_ret = sprintf(t->off_print, str2, test2);
	//t->off_ret = sprintf(t->off_print, str2, ft_itoa_base(va_arg(ap2, intmax_t), 2));
	ret = ft_compare(t->my_ret, t->off_ret, t->my_print, t->off_print, str);
	if ((ft_close(t->fd)) == -1)
		return (-1);
	ft_memdel((void**)&t->my_print);
	ft_memdel((void**)&t->off_print);
	va_end(ap);
	if(ret == 0)
		ft_putstr_fd("*** execution stopped (check above) ***\n", 2);
	return (ret);
}

int		ft_flag_b_bonus(void)
{
	printf("*** Flag b ***\n");

	/*Classic tests*/
	STOPIF0(ft_call_both_binary("%b", 0));
	STOPIF0(ft_call_both_binary("Le nombre est %b !!!", 10));
//	STOPIF0(ft_call_both_binary("Les nombres sont %b et %b", 10, 20));

/*	uintmax_t		i = 2147482766;
	while (i <= UINTMAX_MAX)
	{
		printf("i = %ju\n", i);
		STOPIF0(ft_call_both_binary("%b", i));
		i += 1;
	}
*/
	/*Flag '+'*/
	STOPIF0(ft_call_both_binary("Number is %+b", 100));
	STOPIF0(ft_call_both_binary("Number is %+0b", 100));
	STOPIF0(ft_call_both_binary("Number is %0+10b", -100));
	STOPIF0(ft_call_both_binary("Number is %0+10b", +100));
	STOPIF0(ft_call_both_binary("Number is %0+10b", 0));
	STOPIF0(ft_call_both_binary("Number is %0+10b", -0));
	STOPIF0(ft_call_both_binary("Number is %0+10b", +0));
	STOPIF0(ft_call_both_binary("Number is %+1b", +100));
	STOPIF0(ft_call_both_binary("Number is %+3b", -100));
	STOPIF0(ft_call_both_binary("Number is %+10b", 100));
	STOPIF0(ft_call_both_binary("Number is %+10b", -100));
	STOPIF0(ft_call_both_binary("Number is %+50b", +100));
	STOPIF0(ft_call_both_binary("Number is %50b", -100));
	STOPIF0(ft_call_both_binary("Number is %+.50b", 100));
	STOPIF0(ft_call_both_binary("Number is %++10b", -100));
	STOPIF0(ft_call_both_binary("Number is %+-10b", +100));
	STOPIF0(ft_call_both_binary("Number is %+-+10b", -100));
	STOPIF0(ft_call_both_binary("Number is %+--10b", 100));
	STOPIF0(ft_call_both_binary("Number is %+++10b", 100));
	//STOPIF0(ft_call_both_binary("Number is %+10n", 100));

	/*Flag '-'*/
	STOPIF0(ft_call_both_binary("Number is %-b", 100));
	STOPIF0(ft_call_both_binary("Number is %-0b", 100));
	STOPIF0(ft_call_both_binary("Number is %0-10b", -100));
	STOPIF0(ft_call_both_binary("Number is %0-10b", +100));
	STOPIF0(ft_call_both_binary("Number is %0-10b", 0));
	STOPIF0(ft_call_both_binary("Number is %0-10b", -0));
	STOPIF0(ft_call_both_binary("Number is %0-10b", +0));
	STOPIF0(ft_call_both_binary("Number is %-1b", 100));
	STOPIF0(ft_call_both_binary("Number is %-3b", +100));
	STOPIF0(ft_call_both_binary("Number is %-10b", -100));
	STOPIF0(ft_call_both_binary("Number is %-10b", -100));
	STOPIF0(ft_call_both_binary("Number is %-50b", +100));
	STOPIF0(ft_call_both_binary("Number is %-.50b", 100));
	STOPIF0(ft_call_both_binary("Number is %--10b", 100));
	STOPIF0(ft_call_both_binary("Number is %-+10b", +100));
	STOPIF0(ft_call_both_binary("Number is %-+-10b", 100));
	STOPIF0(ft_call_both_binary("Number is %-++10b", -100));
	STOPIF0(ft_call_both_binary("Number is %---10b", 100));
	//STOPIF0(ft_call_both_binary("Number is %-10n", 100));

	/*Flag ' ' (whitespace)*/
	STOPIF0(ft_call_both_binary("Number is % b", 100));
	STOPIF0(ft_call_both_binary("Number is %+ b", 100));
	STOPIF0(ft_call_both_binary("Number is %- b", 100));
	STOPIF0(ft_call_both_binary("Number is % 10b", 100));
	STOPIF0(ft_call_both_binary("Number is %- 10b", 100));
	STOPIF0(ft_call_both_binary("Number is %+ 10b", 100));
	STOPIF0(ft_call_both_binary("Number is %+ 10b", 100));
	STOPIF0(ft_call_both_binary("Number is %0 b", 100));
	STOPIF0(ft_call_both_binary("Number is %0+ b", 100));
	STOPIF0(ft_call_both_binary("Number is %0- b", 100));
	STOPIF0(ft_call_both_binary("Number is %0+ 10b", 100));
	STOPIF0(ft_call_both_binary("Number is %0- 10b", 100));
	STOPIF0(ft_call_both_binary("Number is %0 10b", 100));
	STOPIF0(ft_call_both_binary("Number is %+     b", 100));
	STOPIF0(ft_call_both_binary("Number is %+      10b", 100));

	/*Flag '#' oxX*/
	STOPIF0(ft_call_both_binary("Number is %+      10b", 100));
	STOPIF0(ft_call_both_binary("The number is %b", 0));
	STOPIF0(ft_call_both_binary("The number is %#b", 0));
	STOPIF0(ft_call_both_binary("The number is %#b", -0));
	STOPIF0(ft_call_both_binary("The number is %#b", +0));
	STOPIF0(ft_call_both_binary("The number is %b", 100));
	STOPIF0(ft_call_both_binary("The number is %#b", 100));
	STOPIF0(ft_call_both_binary("The number is %#b", -100));
	STOPIF0(ft_call_both_binary("The number is %#b", +100));
/*	printf("The number is %x\n", 0);
	printf("The number is %#x\n", 0);
	printf("The number is %#x\n", -0);
	printf("The number is %#x\n", +0);
	printf("The number is %x\n", 100);
	printf("The number is %#x\n", 100);
	printf("The number is %#x\n", -100);
	printf("The number is %#x\n\n", +100);
	printf("The number is %X\n", 0);
	printf("The number is %#X\n", 0);
	printf("The number is %#X\n", -0);
	printf("The number is %#X\n", +0);
	printf("The number is %X\n", 100);
	printf("The number is %#X\n", 100);
	printf("The number is %#X\n", -100);
	printf("The number is %#X\n\n", +100);
	printf("The number is %g\n", -100.03);
	printf("The number is %G\n\n", +100.005933648646846);
	printf("The number is %G\n\n", +100.00);
	printf("\n\n");*/

	/*Flag '0'*/
	STOPIF0(ft_call_both_binary("Number is %010b", 100));
	STOPIF0(ft_call_both_binary("Number is %0+10b", 100));
	STOPIF0(ft_call_both_binary("Number is %0-10b", 100)); /* 0 Should be ignored*/
	STOPIF0(ft_call_both_binary("Number is %-010b", 100)); /* 0 Should be ignored*/
	STOPIF0(ft_call_both_binary("Number is %0.20b", 100)); /* 0 Should be ignored*/
//	STOPIF0(ft_call_both_binary("Number is %0.1x", 100)); /* 0 Should be ignored*/
//	STOPIF0(ft_call_both_binary("Number is %0.0X", 100)); /* 0 Should be ignored*/

	/*Width*/
	STOPIF0(ft_call_both_binary("Number is %3b", 0));
	STOPIF0(ft_call_both_binary("Now number is %3b", 123456789));
	STOPIF0(ft_call_both_binary("I changed the number : %3b", -10));
	STOPIF0(ft_call_both_binary("Again : %3b...", -123456789));

	STOPIF0(ft_call_both_binary("Le nombre est %#+-0 10.20b!", 1000));
/*	STOPIF0(ft_call_both_binary("Le nombre est %#+-0 *b!", 20, 0));
	STOPIF0(ft_call_both_binary("Le nombre est %#+-0 *.4b!", 20, -5));
	STOPIF0(ft_call_both_binary("Le nombre est %#+-0 *.4hb!", 20, +10));
	STOPIF0(ft_call_both_binary("Le nombre est %#+-0 *.4hhb!", 20, 15));
	STOPIF0(ft_call_both_binary("Le nombre est %#+-0 *.4lb !", 20, -20));
	STOPIF0(ft_call_both_binary("Le nombre est %#+-0 *.4llb!", 20, +25));
	STOPIF0(ft_call_both_binary("Le nombre est %#+-0 *.4jb!", 20, -30));
	STOPIF0(ft_call_both_binary("Le nombre est %#+-0 *.4zb!", 20, 35));*/

	/*Precision*/
	STOPIF0(ft_call_both_binary("Number is %.50b", 0));
	STOPIF0(ft_call_both_binary("Number is %.50b", +0));
	STOPIF0(ft_call_both_binary("Number is %.50b", -0));
	STOPIF0(ft_call_both_binary("Number is |%5.50b|", 0));
	STOPIF0(ft_call_both_binary("Number is |%5.50b|", 0));
	STOPIF0(ft_call_both_binary("Number is %0+10.52b", 100));
	STOPIF0(ft_call_both_binary("Number is %0+10.52b", +100));
	STOPIF0(ft_call_both_binary("Number is %0+10.52b", -100));
	STOPIF0(ft_call_both_binary("Number is %0+10.56b", 100));
	STOPIF0(ft_call_both_binary("Number is %0+10.56b", +100));
	STOPIF0(ft_call_both_binary("Number is %0+10.56b", -100));
	STOPIF0(ft_call_both_binary("Number is %+10.56b", 100));
	STOPIF0(ft_call_both_binary("Number is %+10.56b", +100));
	STOPIF0(ft_call_both_binary("Number is %+10.56b", -100));
	STOPIF0(ft_call_both_binary("Number is %0-10.52b", 100));
	STOPIF0(ft_call_both_binary("Number is %0-10.52b", +100));
	STOPIF0(ft_call_both_binary("Number is %0-10.52b", -100));
	STOPIF0(ft_call_both_binary("Number is %0-10.56b", 100));
	STOPIF0(ft_call_both_binary("Number is %0-10.56b", +100));
	STOPIF0(ft_call_both_binary("Number is %0-10.56b", -100));
	STOPIF0(ft_call_both_binary("Number is %-10.56b", 100));
	STOPIF0(ft_call_both_binary("Number is %-10.106b", +100));
	STOPIF0(ft_call_both_binary("Number is %-10.56b", -100));

	/*Size*/
	STOPIF0(ft_call_both_binary("Number is %-15.46Lb", 0));
	STOPIF0(ft_call_both_binary("Number is %-15.46Lb", -100));
	STOPIF0(ft_call_both_binary("Number is %-15.46Lb", 100));

	STOPIF0(ft_call_both_binary("Number is %-15.66hhb", 0));
	STOPIF0(ft_call_both_binary("Number is %-15.66hhb", -100));
	STOPIF0(ft_call_both_binary("Number is %-15.66hhb (SCHAR_MIN)", SCHAR_MIN));
	STOPIF0(ft_call_both_binary("Number is %-15.66hhb (SCHAR_MAX)", SCHAR_MAX));
	STOPIF0(ft_call_both_binary("Number is %-15.66hhb (SCHAR_MIN-1)", SCHAR_MIN - 1));
	STOPIF0(ft_call_both_binary("Number is %-15.66hhb (SCHAR_MAX+1)", SCHAR_MAX + 1));

	STOPIF0(ft_call_both_binary("Number is %-15.16hb", 0));
	STOPIF0(ft_call_both_binary("Number is %-15.16hb", -100));
	STOPIF0(ft_call_both_binary("Number is %-15.16hb (SHRT_MIN)", SHRT_MIN));
	STOPIF0(ft_call_both_binary("Number is %-15.16hb (SHRT_MAX)", SHRT_MAX));
	STOPIF0(ft_call_both_binary("Number is %-15.16hb (SHRT_MIN-1)", SHRT_MIN - 1));
	STOPIF0(ft_call_both_binary("Number is %-15.16hb (SHRT_MAX+1)", SHRT_MAX + 1));

	STOPIF0(ft_call_both_binary("Number is %-15.16tb", 0));
	STOPIF0(ft_call_both_binary("Number is %-15.16tb", -100));
	STOPIF0(ft_call_both_binary("Number is %-15.160tb (PTRDIFF_MIN)", PTRDIFF_MIN));
	STOPIF0(ft_call_both_binary("Number is %-15.160tb (PTRDIFF_MAX)", PTRDIFF_MAX));
	STOPIF0(ft_call_both_binary("Number is %-15.160tb (PTRDIFF_MIN-1)", PTRDIFF_MIN - 1));
	STOPIF0(ft_call_both_binary("Number is %-15.160tb (PTRDIFF_MAX+1)", PTRDIFF_MAX + 1));

	STOPIF0(ft_call_both_binary("Number is %-15.16lb", 0));
	STOPIF0(ft_call_both_binary("Number is %-15.16lb", -100));
	STOPIF0(ft_call_both_binary("Number is %-15.16lb", 100));
	STOPIF0(ft_call_both_binary("Number is %0+10lb", -100));
	STOPIF0(ft_call_both_binary("Number is %-15.160lb", +100));
	STOPIF0(ft_call_both_binary("Number is %-15.160lb (LONG_MIN+1)", LONG_MIN + 1));
	STOPIF0(ft_call_both_binary("Number is %-15.160lb (LONG_MAX-1)", LONG_MAX - 1));
	STOPIF0(ft_call_both_binary("Number is %-15.160lb (LONG_MIN)", LONG_MIN));
	STOPIF0(ft_call_both_binary("Number is %-15.160lb (LONG_MAX)", LONG_MAX));
	STOPIF0(ft_call_both_binary("Number is %-15.160lb (LONG_MIN-1)", LONG_MIN - 1));
	STOPIF0(ft_call_both_binary("Number is %-15.160lb (LONG_MAX+1)", LONG_MAX + 1));
	STOPIF0(ft_call_both_binary("Number is %-15.160llb", 0));
	STOPIF0(ft_call_both_binary("Number is %-15.160llb", -100));
	STOPIF0(ft_call_both_binary("Number is %-15.160llb (LLONG_MIN)", LLONG_MIN));
	STOPIF0(ft_call_both_binary("Number is %-15.160llb (LLONG_MAX)", LLONG_MAX));
	STOPIF0(ft_call_both_binary("Number is %-15.160llb (LLONG_MIN-1)", LLONG_MIN - 1));
	STOPIF0(ft_call_both_binary("Number is %-15.160llb (LLONG_MAX+1)", LLONG_MAX + 1));
	STOPIF0(ft_call_both_binary("Number is %-15.160jb", 0));
	STOPIF0(ft_call_both_binary("Number is %-15.160jb", -100));
	STOPIF0(ft_call_both_binary("Number is %-15.160jb (INTMAX_MIN)", INTMAX_MIN));
	STOPIF0(ft_call_both_binary("Number is %-15.160jb (INTMAX_MAX)", INTMAX_MAX));
	STOPIF0(ft_call_both_binary("Number is %-15.160jb (INTMAX_MIN-1)", INTMAX_MIN - 1));
	STOPIF0(ft_call_both_binary("Number is %-15.160jb (INTMAX_MAX+1)", INTMAX_MAX + 1));
	STOPIF0(ft_call_both_binary("Number is %-15.160zb", 0));
	STOPIF0(ft_call_both_binary("Number is %-15.160zb", -100));
	STOPIF0(ft_call_both_binary("Number is %-15.160zb (SIZE_MAX-1)", SIZE_MAX-1));
	STOPIF0(ft_call_both_binary("Number is %-15.160zb (SIZE_MAX)", SIZE_MAX));
	STOPIF0(ft_call_both_binary("Number is %-15.160zb (SIZE_MAX+1)", SIZE_MAX + 1));
	STOPIF0(ft_call_both_binary("Number is %-15.160zb (-SIZE_MAX)", -SIZE_MAX));
	STOPIF0(ft_call_both_binary("Number is %-15.160zb (-SIZE_MAX-1)", -SIZE_MAX - 1));
	STOPIF0(ft_call_both_binary("Number is %-15.160zb (-1)", -1));

	/*Some Moulitests*/
	STOPIF0(ft_call_both_binary("Basics tests: %#6b", 2500));
	STOPIF0(ft_call_both_binary("bmoulitest: %#.100b", 0));
	STOPIF0(ft_call_both_binary("bmoulitest: %#.100b", 0));

	printf("*** Flag b : all tests passed ***\n");
	return (1);
}
