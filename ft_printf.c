/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keuclide <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 21:45:45 by keuclide          #+#    #+#             */
/*   Updated: 2020/12/12 22:27:42 by keuclide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <limits.h>

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
			i += write(1, s++, 1);
	}
	va_end(argptr);
	return (i);
}

int		main(void)
{
	// char *line;

	// line = "hello";
    // int     a = -4;
    // int     b = 0;
    // char    c = 'a';
    // int     d = 2147483647;
    // int     e = -2147483648;
    // int     f = 42;
    // int     g = 25;
    // int     h = 4200;
    // int     i = 8;
    // int     j = -12;
    // int     k = 123456789;
    // int     l = 0;
    // int     m = -12345678;
    // char    *n = "abcdefghijklmnop";
    // char    *o = "-a";
    // char    *p = "-12";
    // char    *q = "0";
    // char    *r = "%%";
    // char    *s = "-2147483648";
    // char    *t = "0x12345678";
    // char    *u = "-0";
	// while (a < 5)
	// {
	// 	b = -2;
	// 	while (b < 5)
	// 	{
	// 		printf("z---> %d\n", printf("srnd---> %-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
	// 		printf("x---> %d\n", ft_printf("mine---> %-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
	// 		b++;
	// 	}
	// 	a++;
	// }

	// printf("z---> %d\n", printf("z---> {%%20.*s}|* = 0|*|{%020.*s}\n", -5, "42"));
	// printf("x---> %d\n", ft_printf("x---> {%%20.*s}|* = 0|*|{%020.*s}\n", -5, "42"));
	// while (a < 5)
	// {
		printf("z---> %d\n", printf("z---> %*.*x <---\n", -1, 0, 0));
		printf("x---> %d\n\n", ft_printf("x---> %*.*x <---\n", -1, 0, 0));
	// 	a++;
	// }
}

//com ft_dec_type.c ft_dec_type_utils.c ft_flags.c ft_parser.c ft_printff.c ft_processor.c ft_str_type.c ft_type_char.c ft_hex_type.c ft_hex_type_utils.c libft/libft.a && ./a.out | cat -e

// int	main(void)
// {
// 	int	*tab = (int*)malloc(sizeof(int) * 10);
// 	int	*tab2 = (int*)malloc(0);
// 	char	*str;
// 	str = "hello";
// 	char	*line;
// 	line = "\0";

// 	printf("*|%.10s|\n", "hello");
// 	ft_printf("*|%.10s|\n", "hello");
// 	printf("|%020p|\n", &str);
// 	ft_printf("*|%020p|\n", &str);
// 	printf("|%010p|\n", line);
// 	ft_printf("*|%010p|\n", line);
// 	ft_printf("01) my       PRINTF : |%-0.5d|\n", -234);
// 	printf("02) standart PRINTF : |%-0.5d|\n", -234);
// 	printf("%x\n", INT_MIN - 10);
// 	ft_printf("%x\n", INT_MIN - 10);
// 	printf("%d", printf("this %d number", 17));
// 	printf("\n");
// 	ft_printf("%d", ft_printf("this %d number", 17));
// 	printf("\n");
// 	printf("%014d\n", INT_MIN);
// 	ft_printf("%014d\n", INT_MIN);
// 	printf("\n");
// 	printf("%ZZZFFFFF\n", "help");
// 	ft_printf("%ZZZFFFFF\n", "help");
// 	printf("\n");
// 	ft_printf("%%05.*d|* = 0|                           *|{%05.*d}\n", 0, 42);
// 	printf("%%05.*d|* = 0|                            |{%05.*d}\n", 0, 42);
// 	ft_printf("{%%20.*s}|* = 0|                         *|{%020.*s}\n", 0, "42");
// 	printf("{%%20.*s}|* = 0|                          |{%020.*s}\n", 0, "42");
// 	ft_printf("p: Hello wo|%----4c| |%1c| rld | %10c| |%-c| ??\n", '\0', '\n\n', (char)777, 0);
// 	printf("p: Hello wo|%----4c| |%1c| rld | %10c| |%-c| ??\n", '\0', '\n\n', (char)777, 0);
// 	ft_printf("%15p %*.7d MIXED %*.*s TEST! %%%05%%% I %10.7u H%dPE %c%c %.3sSH %10.6x%-7.5X YOUR PRINTF!%%\n", &str, 8, -42, -5, 3, "woop", 15975, 0, 'I', 'T', "CRASH", 15, 15013);
// 	printf("%15p %*.7d MIXED %*.*s TEST! %%%05%%% I %10.7u H%dPE %c%c %.3sSH %10.6x%-7.5X YOUR PRINTF!%%\n", &str, 8, -42, -5, 3, "woop", 15975, 0, 'I', 'T', "CRASH", 15, 15013);
// 	printf("\n");
// 	ft_printf("%10.6x%-7.5X\n", 15, 15013);
// 	printf("%10.6x%-7.5X\n", 15, 15013);
// 	ft_printf("%03.5%--|\n");
// 	printf("%03.5%--|\n");
// 	ft_printf("%%05.*d|* = -15|                           *|{%05.*d}\n", -15, 42);
// 	printf("%%05.*d|* = -15|                            |{%05.*d}\n", -15, 42);
// 	ft_printf("{%%20.*s}|* = -5|                         *|{%020.*s}\n", -5, "42");
// 	printf("{%%20.*s}|* = -5|                          |{%020.*s}\n", -5, "42");
// 	ft_printf("|%%x|%%15x|%%-15x|%%015x|                |%x|%15x|%-15x|%015x|\n", -2147483648, -2147483648, -2147483648, -2147483648);
// 	printf("|%%x|%%15x|%%-15x|%%015x|                |%x|%15x|%-15x|%015x|\n", -2147483648, -2147483648, -2147483648, -2147483648);
// 	ft_printf("|%%x|%%15x|%%-15x|%%015x|                |%x|%15x|%-15x|%015x|\n", -2147483649, -2147483649, -2147483649, -2147483649);
// 	printf("|%%x|%%15x|%%-15x|%%015x|                |%x|%15x|%-15x|%015x|\n", -2147483649, -2147483649, -2147483649, -2147483649);
// 	ft_printf("|%%x|%%15x|%%-15x|%%015x|                |%x|%15x|%-15x|%015x|\n", -2147483650, -2147483650, -2147483650, -2147483650);
// 	printf("|%%x|%%15x|%%-15x|%%015x|                |%x|%15x|%-15x|%015x|\n", -2147483650, -2147483650, -2147483650, -2147483650);
	
	


// 	ft_printf("--------------------%%c--------------------\n");
// 	printf("01) standart PRINTF : |%c|\n", 'a');
// 	ft_printf("01) my       PRINTF : |%c|\n", 'a');
// 	printf("02) standart PRINTF : |%-c|\n", 'z');
// 	ft_printf("02) my       PRINTF : |%-c|\n", 'z');
// 	printf("03) standart PRINTF : |%-----c|\n", '!');
// 	ft_printf("03) my       PRINTF : |%-----c|\n", '!');
// 	printf("04) standart PRINTF : |%5c|\n", 'R');
// 	ft_printf("04) my       PRINTF : |%5c|\n", 'R');
// 	printf("05) standart PRINTF : |%-5c|\n", 'R');
// 	ft_printf("05) my       PRINTF : |%-5c|\n", 'R');
// 	printf("06) standart PRINTF : |%1c|\n", '3');
// 	ft_printf("06) my       PRINTF : |%1c|\n", '3');
// 	printf("07) standart PRINTF : |%c|\n", '\0');
// 	ft_printf("07) my       PRINTF : |%c|\n", '\0');
// 	printf("08) standart PRINTF : |%5c|\n", '\0');
// 	ft_printf("08) my       PRINTF : |%5c|\n", '\0');
// 	printf("09) standart PRINTF : |%-5c|\n", '\0');
// 	ft_printf("09) my       PRINTF : |%-5c|\n", '\0');
// 	printf("10) standart PRINTF : |%1c|\n", '\0');
// 	ft_printf("10} my       PRINTF : |%1c|\n", '\0');
// 	ft_printf("--------------------%%s--------------------\n");
// 	printf("01) standart PRINTF : |%s|\n", "salut");
// 	ft_printf("01) my       PRINTF : |%s|\n", "salut");
// 	printf("02) standart PRINTF : |%-s|\n", "test");
// 	ft_printf("02) my       PRINTF : |%-s|\n", "test");
// 	printf("03) standart PRINTF : |%---------s|\n", "test2");
// 	ft_printf("03) my       PRINTF : |%----------s|\n", "test2");
// 	printf("04) standart PRINTF : |%10s|\n", "42");
// 	ft_printf("04) my       PRINTF : |%10s|\n", "42");
// 	printf("05) standart PRINTF : |%-10s|\n", "42");
// 	ft_printf("05) my       PRINTF : |%-10s|\n", "42");
// 	printf("06) standart PRINTF : |%2s|\n", "string");
// 	ft_printf("06) my       PRINTF : |%2s|\n", "string");
// 	printf("07) standart PRINTF : |%-2s|\n", "string");
// 	ft_printf("07) my       PRINTF : |%-2s|\n", "string");
// 	printf("08) standart PRINTF : |%.15s|\n", "precision");
// 	ft_printf("08) my       PRINTF : |%.15s|\n", "precision");
// 	printf("09) standart PRINTF : |%.4s|\n", "precision");
// 	ft_printf("09) my       PRINTF : |%.4s|\n", "precision");
// 	printf("10) standart PRINTF : |%.0s|\n", "precision");
// 	ft_printf("10) my       PRINTF : |%.0s|\n", "precision");
// 	printf("11) standart PRINTF : |%s|\n", "\0\0\0\0\0");
// 	ft_printf("11) my       PRINTF : |%s|\n", "\0\0\0\0\0");
// 	printf("12) standart PRINTF : |%10s|\n", "\0\0\0\0\0");
// 	ft_printf("12) my       PRINTF : |%10s|\n", "\0\0\0\0\0");
// 	printf("13) standart PRINTF : |%s|\n", "");
// 	ft_printf("13) my       PRINTF : |%s|\n", "");
// 	printf("14) standart PRINTF : |%-.2s|\n", "boom");
// 	ft_printf("14) my       PRINTF : |%-.2s|\n", "boom");
// 	printf("15) standart PRINTF : |%10.8s|\n", "google");
// 	ft_printf("15) my       PRINTF : |%10.8s|\n", "google");
// 	printf("16) standart PRINTF : |%10.2s|\n", "twitter");
// 	ft_printf("16) my       PRINTF : |%10.2s|\n", "twitter");
// 	printf("17) standart PRINTF : |%2.10s|\n", "samsung");
// 	ft_printf("17) my       PRINTF : |%2.10s|\n", "samsung");
// 	printf("18) standart PRINTF : |%2.5s|\n", "printf");
// 	ft_printf("18) my       PRINTF : |%2.5s|\n", "printf");
// 	printf("19) standart PRINTF : |%-10.2s|\n", "424242424242");
// 	ft_printf("19) my       PRINTF : |%-10.2s|\n", "424242424242");
// 	printf("20) standart PRINTF : |%1.0s|\n", "123456789");
// 	ft_printf("20) my       PRINTF : |%1.0s|\n", "123456789");
// 	printf("20) standart PRINTF : |%-1.0s|\n", "123456789");
// 	ft_printf("20) my       PRINTF : |%-1.0s|\n", "123456789");
// 	printf("21) standart PRINTF : |%s|\n", NULL);
// 	ft_printf("21) my       PRINTF : |%s|\n", NULL);
// 	printf("22) standart PRINTF : |%10s|\n", NULL);
// 	ft_printf("22) my       PRINTF : |%10s|\n", NULL);
// 	printf("23) standart PRINTF : |%-10s|\n", NULL);
// 	ft_printf("23) my       PRINTF : |%-10s|\n", NULL);
// 	printf("24) standart PRINTF : |%.1s|\n", "covid-19");
// 	ft_printf("24) my       PRINTF : |%.1s|\n", "covid-19");
// 	printf("25) standart PRINTF : |%10.8s|\n", NULL);
// 	ft_printf("25) my       PRINTF : |%10.8s|\n", NULL);
// 	printf("26) standart PRINTF : |%10.2s|\n", "covid-19");
// 	ft_printf("26) my       PRINTF : |%10.2s|\n", "covid-19");
// 	printf("27) standart PRINTF : |%2.10s|\n", NULL);
// 	ft_printf("27) my       PRINTF : |%2.10s|\n", NULL);
// 	printf("28) standart PRINTF : |%2.5s|\n", "covid-19");
// 	ft_printf("28) my       PRINTF : |%2.5s|\n", "covid-19");
// 	printf("29) standart PRINTF : |%-10.2s|\n", "covid-19");
// 	ft_printf("29) my       PRINTF : |%-10.2s|\n", "covid-19");
// 	printf("30) standart PRINTF : |%1.0s|\n", NULL);
// 	ft_printf("30) my       PRINTF : |%1.0s|\n", NULL);
// 	printf("31) standart PRINTF : |%-1.s|\n", NULL);
// 	ft_printf("31) my       PRINTF : |%-1.s|\n", NULL);
// 	ft_printf("--------------------%%p--------------------\n");
// 	printf("%4.2s %-1.s\n" , "coco", NULL);
// 	ft_printf("%4.2s %-1.s\n" , "coco", NULL);
// 	ft_printf("--------------------%%p--------------------\n");
// 	printf("Coucou %.0s\n%s%---12s\n", "hi", "coco", NULL);
// 	ft_printf("Coucou %.0s\n%s%---12s\n", "hi", "coco", NULL);
// 	ft_printf("--------------------%%p--------------------\n");
// 	printf("|%1.4s| et |%-6.8s| et |%4.2s|\n", "tuuu", "12345", "hu");
// 	ft_printf("|%1.4s| et |%-6.8s| et |%4.2s|\n", "tuuu", "12345", "hu");
// 	ft_printf("--------------------%%p--------------------\n");
// 	printf("hello ca%----4c %1c va %10c%-c ??\n", '\0', '\n', (char)564, 0);
// 	ft_printf("hello ca%----4c %1c va %10c%-c ??\n", '\0', '\n', (char)564, 0);
// 	ft_printf("--------------------%%p--------------------\n");
// 	printf("01) standart PRINTF : |%p|\n", "salut");
// 	ft_printf("01) my       PRINTF : |%p|\n", "salut");
// 	printf("02) standart PRINTF : |%-p|\n", tab2);
// 	ft_printf("02) my       PRINTF : |%-p|\n", tab2);
// 	printf("03) standart PRINTF : |%---------p|\n", "test2");
// 	ft_printf("03) my       PRINTF : |%----------p|\n", "test2");
// 	printf("04) standart PRINTF : |%10p|\n", "42");
// 	ft_printf("04) my       PRINTF : |%10p|\n", "42");
// 	printf("05) standart PRINTF : |%-10p|\n", "42");
// 	ft_printf("05) my       PRINTF : |%-10p|\n", "42");
// 	printf("06) standart PRINTF : |%2p|\n", tab);
// 	ft_printf("06) my       PRINTF : |%2p|\n", tab);
// 	printf("07) standart PRINTF : |%-2p|\n", tab);
// 	ft_printf("07) my       PRINTF : |%-2p|\n", tab);
// 	printf("08) standart PRINTF : |%p|\n", "\0\0\0\0\0");
// 	ft_printf("08) my       PRINTF : |%p|\n", "\0\0\0\0\0");
// 	printf("09) standart PRINTF : |%20p|\n", "\0\0\0\0\0");
// 	ft_printf("09) my       PRINTF : |%20p|\n", "\0\0\0\0\0");
// 	printf("10) standart PRINTF : |%p|\n", "");
// 	ft_printf("10) my       PRINTF : |%p|\n", "");
// 	printf("11) standart PRINTF : |%p|\n", NULL);
// 	ft_printf("11) my       PRINTF : |%p|\n", NULL);
// 	printf("12) standart PRINTF : |%10p|\n", NULL);
// 	ft_printf("12) my       PRINTF : |%10p|\n", NULL);
// 	printf("13) standart PRINTF : |%-10p|\n", NULL);
// 	ft_printf("13) my       PRINTF : |%-10p|\n", NULL);
	
	
// 	printf("14) standart PRINTF : |%.1p|\n", NULL);
// 	ft_printf("14) my       PRINTF : |%.1p|\n", NULL);
// 	printf("15) standart PRINTF : |%10.2p|\n", NULL);
// 	ft_printf("15) my       PRINTF : |%10.2p|\n", NULL);
// 	printf("16) standart PRINTF : |%2.5p|\n", NULL);
// 	ft_printf("16) my       PRINTF : |%2.5p|\n", NULL);
// 	printf("17) standart PRINTF : |%-10.2p|\n", NULL);
// 	ft_printf("17) my       PRINTF : |%-10.2p|\n", NULL);
// 	free(tab);
// 	free(tab2);
// 	ft_printf("----------------%%d-%%i--------------------\n");
// 	printf("01) standart PRINTF : |%d|\n", 42);
// 	ft_printf("01) my       PRINTF : |%d|\n", 42);
// 	printf("02) standart PRINTF : |%i|\n", 42);
// 	ft_printf("02) my       PRINTF : |%i|\n", 42);
// 	printf("03) standart PRINTF : |%-d|\n", 42);
// 	ft_printf("03) my       PRINTF : |%-d|\n", 42);
// 	printf("04) standart PRINTF : |%10d|\n", 100);
// 	ft_printf("04) my       PRINTF : |%10d|\n", 100);
// 	printf("05) standart PRINTF : |%-10d|\n", 64);
// 	ft_printf("05) my       PRINTF : |%-10d|\n", 64);
// 	printf("06) standart PRINTF : |%.10d|\n", 100);
// 	ft_printf("06) my       PRINTF : |%.10d|\n", 100);
// 	printf("07) standart PRINTF : |%10.5d|\n", 100);
// 	ft_printf("07) my       PRINTF : |%10.5d|\n", 100);
// 	printf("08) standart PRINTF : |%5.10d|\n", 64);
// 	ft_printf("08) my       PRINTF : |%5.10d|\n", 64);
// 	printf("09) standart PRINTF : |%1.1d|\n", 16);
// 	ft_printf("09) my       PRINTF : |%1.1d|\n", 16);
// 	printf("10) standart PRINTF : |%d|\n", -42);
// 	ft_printf("10) my       PRINTF : |%d|\n", -42);
// 	printf("11) standart PRINTF : |%10d|\n", -42);
// 	ft_printf("11) my       PRINTF : |%10d|\n", -42);
// 	printf("12) standart PRINTF : |%.10d|\n", -42);
// 	ft_printf("12) my       PRINTF : |%.10d|\n", -42);
// 	printf("13) standart PRINTF : |%10.5d|\n", -16);
// 	ft_printf("13) my       PRINTF : |%10.5d|\n", -16);
// 	printf("14) standart PRINTF : |%5.10d|\n", -16);
// 	ft_printf("14) my       PRINTF : |%5.10d|\n", -16);
// 	printf("15) standart PRINTF : |%1.1d|\n", -20);
// 	ft_printf("15) my       PRINTF : |%1.1d|\n", -20);
// 	printf("16) standart PRINTF : |%-10d|\n", -50);
// 	ft_printf("16) my       PRINTF : |%-10d|\n", -50);
// 	printf("17) standart PRINTF : |%2d|\n", -20);
// 	ft_printf("17) my       PRINTF : |%2d|\n", -20);
// 	printf("18) standart PRINTF : |%.2d|\n", -20);
// 	ft_printf("18) my       PRINTF : |%.2d|\n", -20);
// 	printf("19) standart PRINTF : |%2d|\n", -1);
// 	ft_printf("19) my       PRINTF : |%2d|\n", -1);
// 	printf("20) standart PRINTF : |%.2d|\n", -1);
// 	ft_printf("20) my       PRINTF : |%.2d|\n", -1);
// 	printf("21) standart PRINTF : |%-10d|\n", -80);
// 	ft_printf("21) my       PRINTF : |%-10d|\n", -80);
// 	printf("22) standart PRINTF : |%-.10d|\n", -80);
// 	ft_printf("22) my       PRINTF : |%-.10d|\n", -80);
// 	printf("23) standart PRINTF : |%06d|\n", 35);
// 	ft_printf("23) my       PRINTF : |%06d|\n", 35);
// 	printf("24) standart PRINTF : |%06d|\n", -35);
// 	ft_printf("24) my       PRINTF : |%06d|\n", -35);
// 	printf("25) standart PRINTF : |%05.3d|\n", 5);
// 	ft_printf("25) my       PRINTF : |%05.3d|\n", 5);
// 	printf("26) standart PRINTF : |%03.5d|\n", 5);
// 	ft_printf("26) my       PRINTF : |%03.5d|\n", 5);
// 	printf("27) standart PRINTF : |%05.3d|\n", -5);
// 	ft_printf("27) my       PRINTF : |%05.3d|\n", -5);
// 	printf("28) standart PRINTF : |%03.5d|\n", -5);
// 	ft_printf("28) my       PRINTF : |%03.5d|\n", -5);
// 	printf("29) standart PRINTF : |%d| |%d|\n", INT_MAX, INT_MIN);
// 	ft_printf("29) my       PRINTF : |%d| |%d|\n", INT_MAX, INT_MIN);
// 	printf("30) standart PRINTF : |%d| |%d|\n", INT_MAX + 1, INT_MIN - 1);
// 	ft_printf("30) my       PRINTF : |%d| |%d|\n", INT_MAX + 1, INT_MIN - 1);
// 	printf("31) standart PRINTF : |%.d|\n", 0);
// 	ft_printf("31) my       PRINTF : |%.d|\n", 0);
// 	printf("32) standart PRINTF : |%.d|\n", 100);
// 	ft_printf("32) my       PRINTF : |%.d|\n", 100);
// 	ft_printf("--------------------%%x--------------------\n");
// 	printf("01) standart PRINTF : |%x|\n", 34);
// 	ft_printf("01) my       PRINTF : |%x|\n", 34);
// 	printf("02) standart PRINTF : |%x|\n", -34);
// 	ft_printf("02) my       PRINTF : |%x|\n", -34);
// 	printf("03) standart PRINTF : |%-x|\n", 50);
// 	ft_printf("03) my       PRINTF : |%-x|\n", 50);
// 	printf("04) standart PRINTF : |%10x|\n", 90);
// 	ft_printf("04) my       PRINTF : |%10x|\n", 90);
// 	printf("05) standart PRINTF : |%.10x|\n", 90);
// 	ft_printf("05) my       PRINTF : |%.10x|\n", 90);
// 	printf("06) standart PRINTF : |%15x|\n", -100);
// 	ft_printf("06) my       PRINTF : |%15x|\n", -100);
// 	printf("07) standart PRINTF : |%.15x|\n", -100);
// 	ft_printf("07) my       PRINTF : |%.15x|\n", -100);
// 	printf("08) standart PRINTF : |%10.5x|\n", 52);
// 	ft_printf("08) my       PRINTF : |%10.5x|\n", 52);
// 	printf("09) standart PRINTF : |%5.10x|\n", 52);
// 	ft_printf("09) my       PRINTF : |%5.10x|\n", 52);
// 	printf("10) standart PRINTF : |%20.15x|\n", -100000);
// 	ft_printf("10) my       PRINTF : |%20.15x|\n", -100000);
// 	printf("11) standart PRINTF : |%15.20x|\n", -100000);
// 	ft_printf("11) my       PRINTF : |%15.20x|\n", -100000);
// 	printf("12) standart PRINTF : |%-10x|\n", 144);
// 	ft_printf("12) my       PRINTF : |%-10x|\n", 144);
// 	printf("13) standart PRINTF : |%-.10x|\n", 144);
// 	ft_printf("13) my       PRINTF : |%-.10x|\n", 144);
// 	printf("14) standart PRINTF : |%-20x|\n", -20000000);
// 	ft_printf("14) my       PRINTF : |%-20x|\n", -20000000);
// 	printf("15) standart PRINTF : |%08x|\n", 64);
// 	ft_printf("15) my       PRINTF : |%08x|\n", 64);
// 	printf("16) standart PRINTF : |%03.4x|\n", 10);
// 	ft_printf("16) my       PRINTF : |%03.4x|\n", 10);
// 	printf("17) standart PRINTF : |%.x|\n", 0);
// 	ft_printf("17) my       PRINTF : |%.x|\n", 0);
// 	printf("18) standart PRINTF : |%.x|\n", 88);
// 	ft_printf("18) my       PRINTF : |%.x|\n", 88);
// 	printf("19) standart PRINTF : |%x|\n", UINT_MAX);
// 	ft_printf("19) my       PRINTF : |%x|\n", UINT_MAX);
// 	printf("20) standart PRINTF : |%x| |%x|\n", (unsigned int)-1, UINT_MAX + 1);
// 	ft_printf("20) my       PRINTF : |%x| |%x|\n", (unsigned int)-1, UINT_MAX + 1);
// 	ft_printf("--------------------%%X--------------------\n");
// 	printf("01) standart PRINTF : |%X|\n", 34);
// 	ft_printf("01) my       PRINTF : |%X|\n", 34);
// 	printf("02) standart PRINTF : |%X|\n", -34);
// 	ft_printf("02) my       PRINTF : |%X|\n", -34);
// 	printf("03) standart PRINTF : |%-X|\n", 50);
// 	ft_printf("03) my       PRINTF : |%-X|\n", 50);
// 	printf("04) standart PRINTF : |%10X|\n", 90);
// 	ft_printf("04) my       PRINTF : |%10X|\n", 90);
// 	printf("05) standart PRINTF : |%.10X|\n", 90);
// 	ft_printf("05) my       PRINTF : |%.10X|\n", 90);
// 	printf("06) standart PRINTF : |%15X|\n", -100);
// 	ft_printf("06) my       PRINTF : |%15X|\n", -100);
// 	printf("07) standart PRINTF : |%.15X|\n", -100);
// 	ft_printf("07) my       PRINTF : |%.15X|\n", -100);
// 	printf("08) standart PRINTF : |%10.5X|\n", 52);
// 	ft_printf("08) my       PRINTF : |%10.5X|\n", 52);
// 	printf("09) standart PRINTF : |%5.10X|\n", 52);
// 	ft_printf("09) my       PRINTF : |%5.10X|\n", 52);
// 	printf("10) standart PRINTF : |%20.15X|\n", -100000);
// 	ft_printf("10) my       PRINTF : |%20.15X|\n", -100000);
// 	printf("11) standart PRINTF : |%15.20X|\n", -100000);
// 	ft_printf("11) my       PRINTF : |%15.20X|\n", -100000);
// 	printf("12) standart PRINTF : |%-10X|\n", 144);
// 	ft_printf("12) my       PRINTF : |%-10X|\n", 144);
// 	printf("13) standart PRINTF : |%-.10X|\n", 144);
// 	ft_printf("13) my       PRINTF : |%-.10X|\n", 144);
// 	printf("14) standart PRINTF : |%-20X|\n", -20000000);
// 	ft_printf("14) my       PRINTF : |%-20X|\n", -20000000);
// 	printf("15) standart PRINTF : |%08X|\n", 64);
// 	ft_printf("15) my       PRINTF : |%08X|\n", 64);
// 	printf("16) standart PRINTF : |%03.4X|\n", 10);
// 	ft_printf("16) my       PRINTF : |%03.4X|\n", 10);
// 	printf("17) standart PRINTF : |%.X|\n", 0);
// 	ft_printf("17) my       PRINTF : |%.X|\n", 0);
// 	printf("18) standart PRINTF : |%.X|\n", 88);
// 	ft_printf("18) my       PRINTF : |%.X|\n", 88);
// 	printf("19) standart PRINTF : |%X|\n", UINT_MAX);
// 	ft_printf("19) my       PRINTF : |%X|\n", UINT_MAX);
// 	ft_printf("--------------------%%u--------------------\n");
// 	printf("01) standart PRINTF : |%u|\n", 34);
// 	ft_printf("01) my       PRINTF : |%u|\n", 34);
// 	printf("02) standart PRINTF : |%u|\n", -34);
// 	ft_printf("02) my       PRINTF : |%u|\n", -34);
// 	printf("03) standart PRINTF : |%-u|\n", 50);
// 	ft_printf("03) my       PRINTF : |%-u|\n", 50);
// 	printf("04) standart PRINTF : |%10u|\n", 90);
// 	ft_printf("04) my       PRINTF : |%10u|\n", 90);
// 	printf("05) standart PRINTF : |%.10u|\n", 90);
// 	ft_printf("05) my       PRINTF : |%.10u|\n", 90);
// 	printf("06) standart PRINTF : |%15u|\n", -100);
// 	ft_printf("06) my       PRINTF : |%15u|\n", -100);
// 	printf("07) standart PRINTF : |%.15u|\n", -100);
// 	ft_printf("07) my       PRINTF : |%.15u|\n", -100);
// 	printf("08) standart PRINTF : |%10.5u|\n", 52);
// 	ft_printf("08) my       PRINTF : |%10.5u|\n", 52);
// 	printf("09) standart PRINTF : |%5.10u|\n", 52);
// 	ft_printf("09) my       PRINTF : |%5.10u|\n", 52);
// 	printf("10) standart PRINTF : |%20.15u|\n", -100000);
// 	ft_printf("10) my       PRINTF : |%20.15u|\n", -100000);
// 	printf("11) standart PRINTF : |%15.20u|\n", -100000);
// 	ft_printf("11) my       PRINTF : |%15.20u|\n", -100000);
// 	printf("12) standart PRINTF : |%-10u|\n", 144);
// 	ft_printf("12) my       PRINTF : |%-10u|\n", 144);
// 	printf("13) standart PRINTF : |%-.10u|\n", 144);
// 	ft_printf("13) my       PRINTF : |%-.10u|\n", 144);
// 	printf("14) standart PRINTF : |%-20u|\n", -20000000);
// 	ft_printf("14) my       PRINTF : |%-20u|\n", -20000000);
// 	printf("15) standart PRINTF : |%08u|\n", 64);
// 	ft_printf("15) my       PRINTF : |%08u|\n", 64);
// 	printf("16) standart PRINTF : |%03.4u|\n", 10);
// 	ft_printf("16) my       PRINTF : |%03.4u|\n", 10);
// 	printf("17) standart PRINTF : |%u|\n", 0);
// 	ft_printf("17) my       PRINTF : |%u|\n", 0);
// 	printf("18) standart PRINTF : |%.u|\n", 0);
// 	ft_printf("18) my       PRINTF : |%.u|\n", 0);
// 	printf("19) standart PRINTF : |%10u|\n", 0);
// 	ft_printf("19) my       PRINTF : |%10u|\n", 0);
// 	printf("20) standart PRINTF : |%.u|\n", 88);
// 	ft_printf("20) my       PRINTF : |%.u|\n", 88);
// 	printf("21) standart PRINTF : |%u|\n", UINT_MAX);
// 	ft_printf("21) my       PRINTF : |%u|\n", UINT_MAX);
// 	printf("22) standart PRINTF : |%u| |%u|\n", (unsigned int)-1, UINT_MAX + 1);
// 	ft_printf("22) my       PRINTF : |%u| |%u|\n", (unsigned int)-1, UINT_MAX + 1);
// 	ft_printf("--------------------%%---------------------\n");
// 	printf("01) standart PRINTF : |%5%|\n");
// 	ft_printf("01) my       PRINTF : |%5%|\n");
// 	printf("02) standart PRINTF : |%-5%|\n");
// 	ft_printf("02) my       PRINTF : |%-5%|\n");
// 	printf("03) standart PRINTF : |%.0%|\n");
// 	ft_printf("03) my       PRINTF : |%.0%|\n");
// 	printf("04) standart PRINTF : |");
// 	printf("kekw %Z");
// 	printf("|\n");
// 	ft_printf("04) my       PRINTF : |");
// 	ft_printf("kekw %Z");
// 	ft_printf("|\n");
// 	printf("05) standart PRINTF : |");
// 	int a = printf("%%");
// 	printf("|\n");
// 	ft_printf("05) my       PRINTF : |");
// 	int b = ft_printf("%%");
// 	ft_printf("|\n");
// 	printf("06) standart PRINTF : |");
// 	printf("%%%");
// 	printf("|\n");
// 	ft_printf("06) my       PRINTF : |");
// 	ft_printf("%%%");
// 	ft_printf("|\n\n");
// 	ft_printf("return for st PRINTF : %d\nreturn for my PRINTF : %d\n\n", printf("%%"), ft_printf("%%"));
// 	ft_printf("return for st PRINTF : %d\nreturn for my PRINTF : %d\n\n", printf("%5%"), ft_printf("%5%"));
// 	ft_printf("return for st PRINTF : %d\nreturn for my PRINTF : %d\n\n", printf("%.*s|\n", 5, "kekwait"), ft_printf("%.*s|\n", 5, "kekwait"));
// 	printf("%d\n", printf("%d, ", printf("kekw, ")));
// 	ft_printf("%d\n", ft_printf("%d, ", ft_printf("kekw, ")));
// 	ft_printf("--------------------%%kek------------------\n");
// 	printf("01) standart PRINTF : |%.*s|\n", 5, "kekwait");
// 	ft_printf("01) my       PRINTF : |%.*s|\n", 5, "kekwait");
// 	printf("02) standart PRINTF : |%.*d|\n", 5, 5);
// 	ft_printf("02) my       PRINTF : |%.*d|\n", 5, 5);

// 	printf("03) standart PRINTF : |%.*d|\n", 5, 0);
// 	ft_printf("03) my       PRINTF : |%.*d|\n", 5, 0);
// 	printf("04) standart PRINTF : |%0.3s|\n", "42");
// 	ft_printf("04) my       PRINTF : |%0.3s|\n\n", "42");

// 	printf("01) standart PRINTF : |%.3X|\n", 17);
// 	ft_printf("01) my       PRINTF : |%.3X|\n", 17);

// 	 printf("01) standart PRINTF : |%5.p|\n", NULL);
//     ft_printf("01) my       PRINTF : |%5.p|\n", NULL);

// 	printf("01) standart PRINTF : |%0d|\n", -2147483648);
//     ft_printf("01) my       PRINTF : |%0d|\n", -2147483648);

// 	printf("01) standart PRINTF : |%0*.*d|\n", -2, -2, 2147483648);
//     ft_printf("01) my       PRINTF : |%0*.*d|\n", -2, -2, 2147483648);

// }
