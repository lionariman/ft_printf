/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keuclide <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:54:59 by keuclide          #+#    #+#             */
/*   Updated: 2020/12/06 15:38:02 by keuclide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_processor(char *s, va_list argptr, new_list *list)
{
	int j;

	j = 0;
	if (*s == 'c')
		j = ft_char_type(argptr, list);
	if (*s == 'd' || *s == 'i')
		j = ft_dec_type(argptr, list);
	if (*s == 'u')
		j = ft_dec_type(argptr, list);
/*
	if (s[i] == 's')
		i = ft_str_type(i, argptr, list);
*/
	return (j);
}