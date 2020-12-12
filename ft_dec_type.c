/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keuclide <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:59:47 by keuclide          #+#    #+#             */
/*   Updated: 2020/12/12 17:00:09 by keuclide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_with_len(long long int j)
{
	int i;

	i = 0;
	if (j == 0)
		return (1);
	else if (j < 0)
	{
		j = -j;
		i++;
	}
	while (j > 0)
	{
		j /= 10;
		i++;
	}
	return (i);
}

int		ft_dec_neg(int j, int len, new_list *list, int elem)
{
	list->type = -list->type;
	if (list->zero == 1 && list->precison == 0 && list->dot != 0)
	{
		elem -= len;
		while (elem-- > 0)
			j += write(1, " ", 1);
		j += write(1, "-", 1);
		ft_putnbr_fd(list->type, 1);
	}
	else
	{
		(list->zero == 1 && list->type <= 0) ?
		(elem -= len) : (elem -= len - 1);
		j += write(1, "-", 1);
		while (elem-- > 0)
			j += write(1, "0", 1);
		ft_putnbr_fd(list->type, 1);
	}
	j += len - 1;
	return (j);
}

int		ft_prec(int j, int len, new_list *list)
{
	list->precison -= len;
	while (list->precison-- > 0)
		j += write(1, "0", 1);
	ft_putnbr_fd(list->type, 1);
	j += len;
	return (j);
}

int		ft_width(int j, int len, new_list *list)
{
	if (list->zero == 1 && list->precison == 0 &&
	list->type >= 0 && list->dot == 0)
	{
		while (list->width-- > 0)
			j += write(1, "0", 1);
	}
	else if (list->zero == 1 && list->precison == 0 && list->type < 0)
		j = ft_dec_neg(j, len, list, list->width);
	else
	{
		while (list->width-- > 0)
			j += write(1, " ", 1);
	}
	return (j);
}

int		ft_dec_type(va_list argptr, new_list *list, char *s)
{
	int j;
	int len;

	j = 0;
	if (list->width < 0)
	{
		list->width = -list->width;
		list->minus = 1;
		list->zero = 0;
	}
	if (*s == 'u')
		list->type = va_arg(argptr, unsigned int);
	else
		list->type = va_arg(argptr, int);
	len = ft_with_len(list->type);
	if (list->minus == 0)
		j = ft_one(j, len, list);
	else if (list->minus == 1)
		j = ft_two(j, len, list);
	return (j);
}
