/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keuclide <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 13:44:30 by keuclide          #+#    #+#             */
/*   Updated: 2020/12/13 04:23:08 by keuclide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_write_wid(int j, new_list *list)
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

static int		ft_write_prec(int j, char *str, new_list *list)
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

int		ft_str_1_0(int j, int save, char *str, new_list *list)
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

int		ft_str_1_1(int j, int save, char *str, new_list *list)
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

int		ft_str_1_2(int j, int save, char *str, new_list *list)
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

int		ft_str_type(va_list argptr, new_list *list)
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
	{
		if (list->width > (int)ft_strlen(str))
			j = ft_str_0_0(j, save, str, list);
		else if (list->width > 0 && list->width <= (int)ft_strlen(str))
			j = ft_str_0_1(j, save, str, list);
		else
			j = ft_str_0_2(j, save, str, list);
	}
	else if (list->minus == 1)
	{
		if (list->width > (int)ft_strlen(str))
			j = ft_str_1_0(j, save, str, list);
		else if (list->width > 0 && list->width <= (int)ft_strlen(str))
			j = ft_str_1_1(j, save, str, list);		
		else
			j = ft_str_1_2(j, save, str, list);		
	}
	return (j);
}