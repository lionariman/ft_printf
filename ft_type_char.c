/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keuclide <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 12:30:39 by keuclide          #+#    #+#             */
/*   Updated: 2020/12/13 04:50:48 by keuclide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_char_type(va_list argptr, new_list *list)
{
	int j;

	j = 0;
	(list->width < 0) ? ((list->width *= -1) && (list->minus = 1)) : 0;
	list->width -= 1;
	if (list->width != 0 && list->minus == 0)
		while (list->width-- > 0)
			j += write(1, " ", 1);
	ft_putchar_fd(va_arg(argptr, int), 1);
	j++;
	if (list->width != 0 && list->minus == 1)
		while (list->width-- > 0)
			j += write(1, " ", 1);
	return (j);
}
