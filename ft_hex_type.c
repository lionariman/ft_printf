/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keuclide <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:01:15 by keuclide          #+#    #+#             */
/*   Updated: 2020/12/08 22:15:20 by keuclide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_with_hex_len(int j)
{
	int i;

	i = 0;
	if (j == 0)
		return (1);
	else if (j < 0)
		j = -j;
	while (j > 0)
	{
		j /= 16;
		i++;
	}
	return (i);
}

int		ft_dec_hex_neg(int j, int len, new_list *list, int elem)
{
	list->type = -list->type;
	if (list->zero == 1 && list->precison == 0 && list->dot != 0)
	{
		elem -= len;
		while (elem > 0)
		{
			j += write(1, " ", 1);
			elem -= 1;
		}
		j = ft_xputnbr(list->type, 0, j);
	}
	else
	{
		(list->zero == 1 && list->type <= 0) ?
		(elem -= len) : (elem -= len - 1);
		j += write(1, "-", 1);
		while (elem > 0)
		{
			j += write(1, "0", 1);
			elem -= 1;
		}
		j = ft_xputnbr(list->type, 0, j);
	}
	j += len - 1;
	return (j);
}

int		ft_hex_prec(int j, int len, new_list *list)
{
	list->precison -= len;
	while (list->precison > 0)
	{
		j += write(1, "0", 1);
		list->precison -= 1;
	}
	j = ft_xputnbr(list->type, 0, j);
	return (j);
}

int		ft_xputnbr(int xx, int f, int j)
{
	unsigned int	x = xx;
	char			c;
	char			str[30];
	int				i;

	i = 0;
	(x == 0) ? (j += write(1, "0", 1)) : 0;
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
	return (j);
}

int		ft_hex_type(va_list argptr, new_list *list)
{
	int j;
	int len;

	j = 0;
	list->type = va_arg(argptr, int);
	len = ft_with_hex_len(list->type);
	if (list->minus == 0)
		j = ft_hex_one(j, len, list);
	else if (list->minus == 1)
		j = ft_hex_two(j, len, list);
	return (j);
}