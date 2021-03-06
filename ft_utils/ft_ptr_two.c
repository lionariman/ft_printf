/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keuclide <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 16:27:24 by keuclide          #+#    #+#             */
/*   Updated: 2020/12/13 17:39:19 by keuclide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_ptr_1_1(int j, int len, t_list *list)
{
	if (list->width > list->precison)
	{
		list->width -= list->precison;
		if (list->type < 0)
		{
			list->width -= 1;
			j = ft_dec_ptr_neg(j, len, list, list->precison);
			j = ft_width(j, len, list);
		}
		else
		{
			j = ft_ptr_prec(j, len, list);
			j = ft_width(j, len, list);
		}
	}
	else
	{
		if (list->type < 0)
			j = ft_dec_ptr_neg(j, len, list, list->precison);
		else
			j = ft_ptr_prec(j, len, list);
	}
	return (j);
}

int		ft_ptr_1_0(int j, int len, t_list *list)
{
	if (list->width > len && list->precison > len)
		j = ft_ptr_1_1(j, len, list);
	else if (list->width <= len && list->precison > len)
	{
		if (list->type < 0)
			j = ft_dec_ptr_neg(j, len, list, list->precison);
		else
			j = ft_ptr_prec(j, len, list);
	}
	else if (list->width > len && list->precison <= len)
	{
		list->width -= len;
		j = ft_pputnbr(list->type, list->hex, j, list);
		j = ft_width(j, len, list);
	}
	else
		j += ft_pputnbr(list->type, list->hex, j, list);
	return (j);
}

int		ft_ptr_1_2(int j, int len, t_list *list)
{
	if (list->width > len)
	{
		list->width -= len;
		(list->type == 0 && list->dot == 1) ? (list->width += 1) : 0;
		(list->zero) ? (j = write(1, "0x", 2)) : 0;
		j = ft_pputnbr(list->type, list->hex, j, list);
		j = ft_width(j, len, list);
	}
	else
	{
		(list->zero) ? (j = write(1, "0x", 2)) : 0;
		j = ft_pputnbr(list->type, list->hex, j, list);
	}
	return (j);
}

int		ft_ptr_two(int j, int len, t_list *list)
{
	if (list->width != 0 && list->precison != 0)
		j = ft_ptr_1_0(j, len, list);
	else if (list->width != 0 && list->precison == 0)
		j = ft_ptr_1_2(j, len, list);
	else if (list->dot != 0 && list->width == 0)
	{
		if (list->precison > len && list->type >= 0)
			j = ft_ptr_prec(j, len, list);
		else if (list->precison > len && list->type < 0)
			j = ft_dec_ptr_neg(j, len, list, list->precison);
		else
		{
			j = ft_ptr_prec(j, len, list);
			j = ft_pputnbr(list->type, list->hex, j, list);
		}
	}
	else if (list->dot == 1 && list->precison == 0 && list->type == 0)
		return (j);
	else
		j = ft_pputnbr(list->type, list->hex, j, list);
	return (j);
}
