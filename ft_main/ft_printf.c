/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keuclide <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 21:45:45 by keuclide          #+#    #+#             */
/*   Updated: 2020/12/13 20:42:24 by keuclide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

t_list		list_flag_type(void)
{
	t_list list;

	list.type = 0;
	list.dot = 0;
	list.width = 0;
	list.precison = 0;
	list.minus = 0;
	list.zero = 0;
	list.hex = 0;
	list.p = 1;
	return (list);
}

int			ft_printf(const char *s, ...)
{
	va_list		argptr;
	t_list		list;
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
