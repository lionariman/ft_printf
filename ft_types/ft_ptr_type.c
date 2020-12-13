/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keuclide <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:54:09 by keuclide          #+#    #+#             */
/*   Updated: 2020/12/12 19:44:12 by keuclide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_with_ptr_len(long long int j)
{
	int i;

	i = 2;
	if (j == 0)
		return (i + 1);
	else if (j < 0)
		j = -j;
	while (j > 0)
	{
		j /= 16;
		i++;
	}
	return (i);
}

int		ft_dec_ptr_neg(int j, int len, new_list *list, int elem)
{
	list->type = -list->type;
	if (list->zero == 1 && list->precison == 0 && list->dot != 0)
	{
		elem -= len;
		while (elem-- > 0)
			j += write(1, " ", 1);
		j = ft_pputnbr(list->type, list->hex, j, list);
	}
	else
	{
		(list->zero == 1 && list->type <= 0) ?
		(elem -= len) : (elem -= len - 1);
		j += write(1, "-", 1);
		while (elem-- > 0)
			j += write(1, "0", 1);
		j = ft_pputnbr(list->type, list->hex, j, list);
	}
	j += len - 1;
	return (j);
}

int		ft_ptr_prec(int j, int len, new_list *list)
{
	list->precison -= len;
	if (list->type >= 0)
	{
		list->p = 0;
		(list->width == 0) ? (list->precison += 1) : 0;
		list->precison += 2;
		j += write(1, "0x", 2);
	}
	while (list->precison-- > 0)
		j += write(1, "0", 1);
	j = ft_pputnbr(list->type, list->hex, j, list);
	return (j);
}

int		ft_pputnbr(long long int xx, int f, int j, new_list *list)
{
	long long int	x;
	char			c;
	char			str[30];
	int				i;

	i = 0;
	x = xx;
	(list->p && !list->zero) ? (j += write(1, "0x", 2)) : 0;
	while (x)
	{
		if ((x % 16 >= 10) && f == 0)
			c = (x % 16) - 10 + 'a';
		else if ((x % 16 >= 10) && f == 1)
			c = (x % 16) - 10 + 'A';
		else
			c = (x % 16) + '0';
		str[i] = c;
		x /= 16;
		i++;
	}
	while (i > 0)
		j += write(1, &str[--i], 1);
	(xx == 0 && !list->dot) ? (j += write(1, "0", 1)) : 0;
	return (j);
}

int		ft_ptr_type(va_list argptr, new_list *list)
{
	int j;
	int len;

	j = 0;
	len = 2;
	list->type = va_arg(argptr, long long int);
	len = ft_with_ptr_len(list->type);
	if (list->width < 0)
	{
		list->width = -list->width;
		list->minus = 1;
	}
	if (list->minus == 0)
		j = ft_ptr_one(j, len, list);
	else if (list->minus == 1)
		j = ft_ptr_two(j, len, list);
	return (j);
}