/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keuclide <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 21:45:45 by keuclide          #+#    #+#             */
/*   Updated: 2020/12/12 15:18:39 by keuclide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

new_list	list_flag_type(void)
{
	new_list flag;

	flag.type = 0;
	flag.dot = 0;
	flag.width = 0;
	flag.precison = 0;
	flag.minus = 0;
	flag.zero = 0;
	flag.hex = 0;
	flag.p = 1;

	return (flag);
}

int		ft_printf(const char *s, ...)
{
	va_list		argptr;
	new_list	list;
	int			i;

	i = 0;
	va_start(argptr, s);
	while (*s)
	{
		if (*s == '%' && *(s + 1) != '\0')
		{
			list = list_flag_type();
			s = ft_parser((char *)s + 1, argptr, &list);
			i += ft_processor((char *)s, argptr, &list);
			(ft_istype((char *)s)) ? (s++) : 0;
		}
		else
		{
			i += write(1, s, 1);
			s++;
		}
	}
	va_end(argptr);
	return (i);
}

int		main(void)
{
	int		x = 0;
    int     a = -4;
    // int     b = 0;
    char    c = 'a';
    int     d = 2147483647;
    int     e = -2147483648;
    // int     f = 42;
    // int     g = 25;
    // int     h = 4200;
    int     i = 8;
    int     j = -12;
    int     k = 123456789;
    int     l = 0;
    int     m = -12345678;
    // char    *n = "abcdefghijklmnop";
    // char    *o = "-a";
    // char    *p = "-12";
    // char    *q = "0";
    // char    *r = "%%";
    // char    *s = "-2147483648";
    // char    *t = "0x12345678";
    // char    *u = "-0";
	// printf("z---> %d\n", printf("z---> %*i, %*d, %*d, %*d, %*d, %*d, %*d, %*d\n", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
	// printf("x---> %d\n", ft_printf("x---> %*i, %*d, %*d, %*d, %*d, %*d, %*d, %*d\n", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
	// printf("z---> %d\n", printf("z---> %0*i, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d\n", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
	// printf("x---> %d\n", ft_printf("x---> %0*i, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d\n", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
	// printf("z---> %d\n", printf("z---> %-*i, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d\n", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
	// printf("x---> %d\n", ft_printf("x---> %-*i, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d\n", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
	// printf("z---> %d\n", printf("z---> %.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d\n", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
	// printf("x---> %d\n", ft_printf("x---> %.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d\n", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
	while (x < 5)
	{
	//	printf("z---> %d\n", printf("z---> %.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d\n", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
		printf("x---> %d\n", ft_printf("x---> %.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d\n", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
		x++;
	}
}

//com ft_dec_type.c ft_dec_type_utils.c ft_flags.c ft_parser.c ft_printff.c ft_processor.c ft_str_type.c ft_type_char.c ft_hex_type.c ft_hex_type_utils.c libft/libft.a && ./a.out | cat -e

