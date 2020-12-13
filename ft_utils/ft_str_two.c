/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keuclide <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 16:35:36 by keuclide          #+#    #+#             */
/*   Updated: 2020/12/13 17:39:44 by keuclide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_str_1_0(int j, int save, char *str, t_list *list)
{
	if (list->precison != 0 && list->precison < (int)ft_strlen(str))
	{
		list->width -= list->precison;
		save = list->precison;
		j += ft_write_prec(j, str, list);
		j = ft_write_wid(j, list);
		return (j + save);
	}
	if (list->dot == 1 && list->precison == 0)
		return (ft_write_wid(j, list));
	list->width -= ft_strlen(str);
	ft_putstr_fd(str, 1);
	j = ft_write_wid(j, list);
	j += ft_strlen(str);
	return (j);
}

int		ft_str_1_1(int j, int save, char *str, t_list *list)
{
	if (list->dot == 1)
	{
		list->width -= list->precison;
		save = list->precison;
		j = ft_write_prec(j, str, list);
		j = ft_write_wid(j, list);
		return (j + save);
	}
	ft_putstr_fd(str, 1);
	j += ft_strlen(str);
	return (j);
}

int		ft_str_1_2(int j, int save, char *str, t_list *list)
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

int		ft_str_two(int j, int save, char *str, t_list *list)
{
	if (list->width > (int)ft_strlen(str))
		j = ft_str_1_0(j, save, str, list);
	else if (list->width > 0 && list->width <= (int)ft_strlen(str))
		j = ft_str_1_1(j, save, str, list);
	else
		j = ft_str_1_2(j, save, str, list);
	return (j);
}
