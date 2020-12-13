/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_one.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keuclide <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 16:30:21 by keuclide          #+#    #+#             */
/*   Updated: 2020/12/13 16:36:17 by keuclide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_str_0_0(int j, int save, char *str, new_list *list)
{
	if (list->precison > 0 && list->precison < (int)ft_strlen(str))
	{
		list->width -= list->precison;
		j += ft_write_wid(j, list);
		save = list->precison;
		j = ft_write_prec(j, str, list);
		return (j + save);
	}
	if (list->dot == 1 && list->precison == 0)
		return (ft_write_wid(j, list));
	list->width -= ft_strlen(str);
	j = ft_write_wid(j, list);
	ft_putstr_fd(str, 1);
	j += ft_strlen(str);
	return (j);
}

int		ft_str_0_1(int j, int save, char *str, new_list *list)
{
	if (list->dot == 1 && list->precison >= 0)
	{
		list->width -= list->precison;
		j = ft_write_wid(j, list);
		save = list->precison;
		j = ft_write_prec(j, str, list);
		return (j + save);
	}
	ft_putstr_fd(str, 1);
	j += ft_strlen(str);
	return (j);
}

int		ft_str_0_2(int j, int save, char *str, new_list *list)
{
	if (list->dot == 1 && list->precison < (int)ft_strlen(str))
	{
		save = list->precison;
		j += ft_write_prec(j, str, list);
		return (j + save);
	}
	ft_putstr_fd(str, 1);
	j += ft_strlen(str);
	return (j);
}

int		ft_str_one(int j, int save, char *str, new_list *list)
{
	if (list->width > (int)ft_strlen(str))
		j = ft_str_0_0(j, save, str, list);
	else if (list->width > 0 && list->width <= (int)ft_strlen(str))
		j = ft_str_0_1(j, save, str, list);
	else
		j = ft_str_0_2(j, save, str, list);
	return (j);
}
