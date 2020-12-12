/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keuclide <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 17:46:58 by keuclide          #+#    #+#             */
/*   Updated: 2020/12/11 19:51:46 by keuclide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isflag(char *c)
{
	if (*c == '-' || *c == '0' || *c == '*' || *c == '.')
		return (1);
	return (0);
}

int		ft_istype(char *c)
{
	if (*c == 'c' || *c == 's' || *c == 'd' || *c == 'i' || *c == 'p' ||
		*c == 'u' || *c == 'x' || *c == 'X' || *c == '%')
		return (1);
	return (0);
}

char	*ft_parser(char *s, va_list argptr, new_list *list)
{
	while (*s)
	{
		if (!ft_istype(s) && !ft_isflag(s) && !ft_isdigit(*s))
			break ;
		if (*s == '-')
			s = ft_flag_minus(s, list);
		if (*s == '0')
			list->zero = 1;
		if (*s == '.')
			s = ft_flag_dot(s, argptr, list);
		if (*s == '*' && list->precison == 0 && list->dot == 0)
			list->width = va_arg(argptr, int);
		if (ft_isdigit(*s) && list->precison == 0 && list->dot == 0)
			s = ft_flag_num(s, list);
		if (ft_istype(s))
			break ;
		s++;
	}

	// printf("%d,", list->dot);
	// printf("%d,", list->width);
	// printf("%d,", list->precison);
	// printf("%d,", list->minus);
	// printf("%d\n", list->zero);

	return (s);
}
