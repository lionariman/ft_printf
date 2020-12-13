/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keuclide <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 13:44:30 by keuclide          #+#    #+#             */
/*   Updated: 2020/12/13 17:37:45 by keuclide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_write_wid(int j, t_list *list)
{
	if (list->zero == 1 && list->minus == 0)
	{
		while (list->width-- > 0)
			j += write(1, "0", 1);
		return (j);
	}
	while (list->width-- > 0)
		j += write(1, " ", 1);
	return (j);
}

int		ft_write_prec(int j, char *str, t_list *list)
{
	if (list->precison > (int)ft_strlen(str))
	{
		ft_putstr_fd(str, 1);
		return (ft_strlen(str) - list->precison);
	}
	while (list->precison > 0)
	{
		ft_putchar_fd(*str, 1);
		list->precison -= 1;
		str++;
	}
	if (list->precison < 0)
	{
		ft_putstr_fd(str, 1);
		if (list->width)
		{
			list->width -= (int)ft_strlen(str) + (list->precison *= -1);
			j += (int)ft_strlen(str) + list->precison;
		}
		else
			j += (int)ft_strlen(str) + (list->precison *= -1);
	}
	return (j);
}

int		ft_str_type(va_list argptr, t_list *list)
{
	char	*str;
	int		j;
	int		save;

	j = 0;
	save = 0;
	str = va_arg(argptr, char *);
	str == NULL ? (str = "(null)") : 0;
	if (list->width < 0)
	{
		list->width = -list->width;
		list->minus = 1;
	}
	if (list->minus == 0)
		j = ft_str_one(j, save, str, list);
	else if (list->minus == 1)
		j = ft_str_two(j, save, str, list);
	return (j);
}
