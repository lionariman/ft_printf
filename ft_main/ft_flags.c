/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keuclide <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 06:29:17 by keuclide          #+#    #+#             */
/*   Updated: 2020/12/13 17:35:26 by keuclide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_flag_minus(char *s, t_list *list)
{
	list->minus = 1;
	list->zero = 0;
	return (s);
}

char	*ft_flag_dot(char *s, va_list argptr, t_list *list)
{
	s++;
	list->dot = 1;
	if (*s == '*')
		list->precison = va_arg(argptr, int);
	else if (ft_istype(s))
		s--;
	else
	{
		while (ft_isdigit(*s))
		{
			list->precison *= 10;
			list->precison += (*s - '0');
			s++;
		}
		s--;
	}
	return (s);
}

char	*ft_flag_num(char *s, t_list *list)
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

int		ft_width(int j, int len, t_list *list)
{
	if (list->zero == 1 && list->precison == 0 &&
	list->type >= 0 && list->dot == 0)
		while (list->width-- > 0)
			j += write(1, "0", 1);
	else if (list->zero == 1 && list->precison == 0 && list->type < 0)
		j = ft_dec_neg(j, len, list, list->width);
	else if (list->precison < 0 && list->zero == 1)
	{
		(list->type < 0) ? ((write(1, "-", 1)) && (list->type *= -1)) : 0;
		while (list->width-- > 0)
			j += write(1, "0", 1);
	}
	else
		while (list->width-- > 0)
			j += write(1, " ", 1);
	return (j);
}
