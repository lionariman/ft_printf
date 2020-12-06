/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keuclide <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 21:45:45 by keuclide          #+#    #+#             */
/*   Updated: 2020/12/06 17:14:25 by keuclide         ###   ########.fr       */
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

	return (flag);
}

int		ft_printf(const char *s, ...)
{
	va_list		argptr;
	new_list	list;
	int			i;

	i = 0;
	va_start(argptr, s);
	while (*s && (*s + 1) != '\0')
	{
		if (*s == '%')
		{
			list = list_flag_type();
			s = ft_parser((char *)s + 1, argptr, &list);
			i += ft_processor((char *)s, argptr, &list);
		}
		else
			i += write(1, s, 1);
		s++;
	}
	va_end(argptr);
	return (i);
}
/*
int		main(void)
{
	int number_one;
	int number_two;
	int i;
	char *s;

	number_one = 1;
	number_two = 2;
	s = "Excusez-moi\n";
	i = printf("---> %5d <---\n", 0);
	printf("%d\n", i);
	i = ft_printf("---> %5d <---\n", 0);
	printf("%d\n", i);
}
*/