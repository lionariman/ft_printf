/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keuclide <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 06:29:17 by keuclide          #+#    #+#             */
/*   Updated: 2020/12/05 20:16:46 by keuclide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_flag_minus(char *s, new_list *list)
{
	list->minus = 1;
	list->zero = 0;
	return (s);
}

char	*ft_flag_dot(char *s, va_list argptr, new_list *list)
{
	s++;
	if (*s == '*')
		list->precison = va_arg(argptr, int);
	else if (ft_istype(s))
	{
		list->dot = 1;
		s--;
	}
	else
	{
		while (ft_isdigit(*s))
		{
			list->precison *= 10;
			list->precison += (*s - '0');
			s++;
		}
		(list->precison == 0) ? (list->dot = 2) : (list->dot = 0);
		s--;
	}
	return (s);
}

char	*ft_flag_num(char *s, new_list *list)
{
	while (ft_isdigit(*s))
	{
		list->width *= 10;
		list->width += (*s - '0');
		s++;
	}
	s--;
	return (s);
}