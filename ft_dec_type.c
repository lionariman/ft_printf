/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keuclide <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:59:47 by keuclide          #+#    #+#             */
/*   Updated: 2020/12/04 21:54:26 by keuclide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_with_len(int j)
{
	int i;

	i = 0;
	while (j > 0)
	{
		j /= 10;
		i++;
	}
	return (i);
}

int		ft_dec_type(va_list argptr, new_list *list)
{
	int j;
	int len;

	j = 0;
	list->type = va_arg(argptr, int);
	len = ft_with_len(list->type);
	if (list->minus == 0)//there isn't a minus in the structure
	{
		if (list->width != 0 && list->precison != 0)//with and precision
		{
			if (list->width <= len && list->precison > len)
			{
				list->precison -= len;
				while (list->precison > 0)
				{
					j += write(1, "0", 1);
					list->precison -= 1;
				}
				ft_putnbr_fd(list->type, 1);
				j += len;
			}
			if (list->width > len && list->precison <= len)
			{
				list->width -= len;
				while (list->width > 0)
				{
					j += write(1, " ", 1);
					list->width -= 1;
				}
				ft_putnbr_fd(list->type, 1);
				j += len;
			}
		}
		else if (list->width != 0 && list->precison == 0)//width
		{
			if (list->width > len)
			{
				list->width -= len;
				while (list->width > 0)
				{
					j += write(1, " ", 1);
					list->width -= 1;
				}
				ft_putnbr_fd(list->type, 1);
				j += len;
			}
			else
			{
				ft_putnbr_fd(list->type, 1);
				j += len;
			}
		}
		else if (list->precison != 0 && list->width == 0)//precision
		{
			if (list->precison > len)
			{
				list->precison -= len;
				while (list->precison > 0)
				{
					j += write(1, "0", 1);
					list->precison -= 1;
				}
				ft_putnbr_fd(list->type, 1);
				j += len;
			}
			else
			{
				ft_putnbr_fd(list->type, 1);
				j += len;
			}
		}
		else
		{
			ft_putnbr_fd(list->type, 1);
			j += len;
		}
	}
	else if (list->minus == 1)//there is a minus in the structure
	{
		if (list->width != 0 && list->precison != 0)//width and precision
		{
			if (list->width <= len && list->precison > len)
			{
				list->precison -= len;
				ft_putnbr_fd(list->type, 1);
				j += len;
				while (list->precison > 0)
				{
					j += write(1, "0", 1);
					list->precison -= 1;
				}
			}
			if (list->width > len && list->precison <= len)
			{
				list->width -= len;
				ft_putnbr_fd(list->type, 1);
				j += len;
				while (list->width > 0)
				{
					j += write(1, " ", 1);
					list->width -= 1;
				}
			}
		}
		else if (list->width != 0 && list->precison == 0)//width
		{
			if (list->width > len)
			{
				list->width -= len;
				ft_putnbr_fd(list->type, 1);
				j += len;
				while (list->width > 0)
				{
					j += write(1, " ", 1);
					list->width -= 1;
				}
			}
			else
			{
				ft_putnbr_fd(list->type, 1);
				j += len;
			}
		}
		else if (list->precison != 0 && list->width == 0)//precision
		{
			if (list->precison > len)
			{
				list->precison -= len;
				while (list->precison > 0)
				{
					j += write(1, "0", 1);
					list->precison -= 1;
				}
				ft_putnbr_fd(list->type, 1);
				j += len;
			}
			else
			{
				ft_putnbr_fd(list->type, 1);
				j += len;
			}
		}
		else
		{
			ft_putnbr_fd(list->type, 1);
			j += len;
		}
	}
	return (j);
}