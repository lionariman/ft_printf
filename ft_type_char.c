/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keuclide <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 12:30:39 by keuclide          #+#    #+#             */
/*   Updated: 2020/12/06 20:57:35 by keuclide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_char_type(va_list argptr, new_list *list)
{
	int x;
	int j;

	x = list->width;
	j = 0;
	if (x != 0 && list->minus == 0)
	{
		while (x - 1 > 0)
		{
			j += write(1, " ", 1);
			x--;
		}
	}
	ft_putchar_fd(va_arg(argptr, int), 1);
	j++;
	if (x != 0 && list->minus == 1)
	{
		while (x - 1 > 0)
		{
			j += write(1, " ", 1);
			x--;
		}
	}
	return (j);
}
