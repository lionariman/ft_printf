/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prc_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keuclide <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:54:24 by keuclide          #+#    #+#             */
/*   Updated: 2020/12/13 20:57:28 by keuclide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_prc_type(t_list *list)
{
	int j;

	j = 0;
	list->width -= 1;
	(list->minus) ? (list->zero = 0) : 0;
	(list->minus) ? (j += write(1, "%", 1)) : 0;
	if (list->zero == 1)
		while (list->width-- > 0)
			j += write(1, "0", 1);
	if (list->zero == 0)
		while (list->width-- > 0)
			j += write(1, " ", 1);
	(!list->minus) ? (j += write(1, "%", 1)) : 0;
	return (j);
}
