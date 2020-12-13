/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_type_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keuclide <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:56:40 by keuclide          #+#    #+#             */
/*   Updated: 2020/12/13 04:34:18 by keuclide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_hex_0_1(int j, int len, new_list *list)
{
	if (list->width > list->precison)
	{
		list->width -= list->precison;
		if (list->type < 0)
		{
			list->width -= 1;
			j = ft_width(j, len, list);
			j = ft_dec_hex_neg(j, len, list, list->precison);
		}
		else
		{
			j = ft_width(j, len, list);
			j = ft_hex_prec(j, len, list);
		}
	}
	else
	{
		if (list->type < 0)
			j = ft_dec_hex_neg(j, len, list, list->precison);
		else
			j = ft_hex_prec(j, len, list);
	}
	return (j);
}

int		ft_hex_0_0(int j, int len, new_list *list)
{
	if (list->width > len && list->precison > len)
		j = ft_hex_0_1(j, len, list);
	else if (list->width <= len && list->precison > len)
	{
		if (list->type < 0)
			j = ft_dec_hex_neg(j, len, list, list->precison);
		else
			j = ft_hex_prec(j, len, list);
	}
	else if (list->width > len && list->precison <= len)
	{
		list->width -= len;
		j = ft_width(j, len, list);
		j = ft_xputnbr(list->type, list->hex, j);
	}
	else
		j += ft_xputnbr(list->type, list->hex, j);
	return (j);
}

int		ft_hex_0_2(int j, int len, new_list *list)
{
	if (list->width >= len)
	{
		if (list->zero == 1 && list->precison == 0 && list->type < 0)
		{
			list->width -= len - 2;
			j = ft_width(j, len, list);
		}
		else
		{
			if (list->type == 0 && list->dot == 1)
				return (j = ft_width(j, len, list));
			list->width -= len;
			j = ft_width(j, len, list);
			j = ft_xputnbr(list->type, list->hex, j);
		}
	}
	else
		j = ft_xputnbr(list->type, list->hex, j);
	return (j);
}

int		ft_hex_1_1(int j, int len, new_list *list)
{
	if (list->width > list->precison)
	{
		list->width -= list->precison;
		if (list->type < 0)
		{
			list->width -= 1;
			j = ft_dec_hex_neg(j, len, list, list->precison);
			j = ft_width(j, len, list);
		}
		else
		{
			j = ft_hex_prec(j, len, list);
			j = ft_width(j, len, list);
		}
	}
	else
	{
		if (list->type < 0)
			j = ft_dec_hex_neg(j, len, list, list->precison);
		else
			j = ft_hex_prec(j, len, list);
	}
	return (j);
}

int		ft_hex_1_0(int j, int len, new_list *list)
{
	if (list->width > len && list->precison > len)
		j = ft_hex_1_1(j, len, list);
	else if (list->width <= len && list->precison > len)
	{
		if (list->type < 0)
			j = ft_dec_hex_neg(j, len, list, list->precison);
		else
			j = ft_hex_prec(j, len, list);
	}
	else if (list->width > len && list->precison <= len)
	{
		list->width -= len;
		j = ft_xputnbr(list->type, list->hex, j);
		j = ft_width(j, len, list);
	}
	else
		j += ft_xputnbr(list->type, list->hex, j);
	return (j);
}

int		ft_hex_1_2(int j, int len, new_list *list)
{
	if (list->width >= len)
	{
		if (list->type == 0 && list->dot == 1)
			return (j = ft_width(j, len, list));
		list->width -= len;
		j = ft_xputnbr(list->type, list->hex, j);
		j = ft_width(j, len, list);
	}
	else
		j = ft_xputnbr(list->type, list->hex, j);
	return (j);
}

int		ft_hex_one(int j, int len, new_list *list)
{
	if (list->width != 0 && list->precison != 0)
		j = ft_hex_0_0(j, len, list);
	else if (list->width != 0 && list->precison == 0)
		j = ft_hex_0_2(j, len, list);
	else if (list->precison != 0 && list->width == 0)
	{
		if (list->precison > len && list->type >= 0)
			j = ft_hex_prec(j, len, list);
		else if (list->precison > len && list->type < 0)
			j = ft_dec_hex_neg(j, len, list, list->precison);
		else
			j = ft_xputnbr(list->type, list->hex, j);
	}
	else if (list->dot == 1 && list->precison == 0 && list->type == 0)
		return (j);
	else
		j = ft_xputnbr(list->type, list->hex, j);
	return (j);
}

int		ft_hex_two(int j, int len, new_list *list)
{
	if (list->width != 0 && list->precison != 0)
		j = ft_hex_1_0(j, len, list);
	else if (list->width != 0 && list->precison == 0)
		j = ft_hex_1_2(j, len, list);
	else if (list->precison != 0 && list->width == 0)
	{
		if (list->precison > len && list->type >= 0)
			j = ft_hex_prec(j, len, list);
		else if (list->precison > len && list->type < 0)
			j = ft_dec_hex_neg(j, len, list, list->precison);
		else
			j = ft_xputnbr(list->type, list->hex, j);
	}
	else if (list->dot == 1 && list->precison == 0 && list->type == 0)
		return (j);
	else
		j = ft_xputnbr(list->type, list->hex, j);
	return (j);
}