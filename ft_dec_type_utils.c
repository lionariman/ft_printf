/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_type_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keuclide <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 19:44:03 by keuclide          #+#    #+#             */
/*   Updated: 2020/12/10 14:57:33 by keuclide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_dec_0_1(int j, int len, new_list *list)
{
	if (list->width > len && list->precison > len)
	{
		if (list->width > list->precison)
		{
			list->width -= list->precison;
			if (list->type < 0)
			{
				list->width -= 1;
				j = ft_width(j, len, list);
				j = ft_dec_neg(j, len, list, list->precison);
			}
			else
			{
				j = ft_width(j, len, list);
				j = ft_prec(j, len, list);
			}
		}
		else
		{
			if (list->type < 0)
				j = ft_dec_neg(j, len, list, list->precison);
			else
				j = ft_prec(j, len, list);
		}
	}
	return (j);
}

int		ft_dec_0_0(int j, int len, new_list *list)
{
	if (list->width > len && list->precison > len)
		j = ft_dec_0_1(j, len, list);
	else if (list->width <= len && list->precison > len)
	{
		if (list->type < 0)
			j = ft_dec_neg(j, len, list, list->precison);
		else
			j = ft_prec(j, len, list);
	}
	else if (list->width > len && list->precison <= len)
	{
		list->width -= len;
		j = ft_width(j, len, list);
		j += len;
		ft_putnbr_fd(list->type, 1);
	}
	else
	{
		ft_putnbr_fd(list->type, 1);
		j += len;
	}
	return (j);
}

int		ft_dec_0_2(int j, int len, new_list *list)
{
	if (list->width > len)
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
			ft_putnbr_fd(list->type, 1);
			j += len;
		}
	}
	else
	{
		ft_putnbr_fd(list->type, 1);
		j += len;
	}
	return (j);
}

int		ft_dec_1_1(int j, int len, new_list *list)
{
	if (list->width > list->precison)
	{
		list->width -= list->precison;
		if (list->type < 0)
		{
			list->width -= 1;
			j = ft_dec_neg(j, len, list, list->precison);
			j = ft_width(j, len, list);
		}
		else
		{
			j = ft_prec(j, len, list);
			j = ft_width(j, len, list);
		}
	}
	else
	{
		if (list->type < 0)
			j = ft_dec_neg(j, len, list, list->precison);
		else
			j = ft_prec(j, len, list);
	}
	return (j);
}

int		ft_dec_1_0(int j, int len, new_list *list)
{
	if (list->width > len && list->precison > len)
		j = ft_dec_1_1(j, len, list);
	else if (list->width <= len && list->precison > len)
	{
		if (list->type < 0)
			j = ft_dec_neg(j, len, list, list->precison);
		else
			j = ft_prec(j, len, list);
	}
	else if (list->width > len && list->precison <= len)
	{
		list->width -= len;
		ft_putnbr_fd(list->type, 1);
		j += len;
		j = ft_width(j, len, list);
	}
	else
	{
		ft_putnbr_fd(list->type, 1);
		j += len;
	}
	return (j);
}

int		ft_dec_1_2(int j, int len, new_list *list)
{
	if (list->width > len)
	{
		if (list->type == 0 && list->dot == 1)
			return (j = ft_width(j, len, list));
		list->width -= len;
		ft_putnbr_fd(list->type, 1);
		j += len;
		j = ft_width(j, len, list);
	}
	else
	{
		ft_putnbr_fd(list->type, 1);
		j += len;
	}
	return (j);
}

int		ft_one(int j, int len, new_list *list)
{
	if (list->width != 0 && list->precison != 0)
		j = ft_dec_0_0(j, len, list);
	else if (list->width != 0 && list->precison == 0)
		j = ft_dec_0_2(j, len, list);
	else if (list->precison != 0 && list->width == 0)
	{
		if (list->precison > len && list->type >= 0)
			j = ft_prec(j, len, list);
		else if (list->precison > len && list->type < 0)
			j = ft_dec_neg(j, len, list, list->precison);
		else
		{
			ft_putnbr_fd(list->type, 1);
			j += len;
		}
	}
	else if (list->dot == 1 && list->precison == 0 && list->type == 0)
		return (j);
	else
	{
		ft_putnbr_fd(list->type, 1);
		j += len;
	}
	return (j);
}

int		ft_two(int j, int len, new_list *list)
{
	if (list->width != 0 && list->precison != 0)
		j = ft_dec_1_0(j, len, list);
	else if (list->width != 0 && list->precison == 0)
		j = ft_dec_1_2(j, len, list);
	else if (list->precison != 0 && list->width == 0)
	{
		if (list->precison > len && list->type >= 0)
			j = ft_prec(j, len, list);
		else if (list->precison > len && list->type < 0)
			j = ft_dec_neg(j, len, list, list->precison);
		else
		{
			ft_putnbr_fd(list->type, 1);
			j += len;
		}
	}
	else if (list->dot == 1 && list->precison == 0 && list->type == 0)
		return (j);
	else
	{
		ft_putnbr_fd(list->type, 1);
		j += len;
	}
	return (j);
}
