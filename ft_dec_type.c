/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keuclide <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:59:47 by keuclide          #+#    #+#             */
/*   Updated: 2020/12/05 20:02:32 by keuclide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_with_len(int j)
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

static int		ft_dec_neg(int j, int len, new_list *list)
{
	list->type = -list->type;
	list->precison -= len - 1;
	j += write(1, "-", 1);
	while (list->precison > 0)
	{
		j += write(1, "0", 1);
		list->precison -= 1;
	}
	ft_putnbr_fd(list->type, 1);
	j += len - 1;
	return (j);
}

static int		ft_prec(int j, int len, new_list *list)
{
	list->precison -= len;
	while (list->precison > 0)
	{
		j += write(1, "0", 1);
		list->precison -= 1;
	}
	ft_putnbr_fd(list->type, 1);
	j += len;
	return (j);
}

static int		ft_width(int j, new_list *list)
{
	if (list->zero == 1 && list->precison == 0)
	{
		while (list->width > 0)
		{
			j += write(1, "0", 1);
			list->width -= 1;
		}
	}
	else
	{
		while (list->width > 0)
		{
			j += write(1, " ", 1);
			list->width -= 1;
		}
	}
	return (j);
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
			if (list->width > len && list->precison > len)
			{
				if (list->width > list->precison)
				{
					list->width -= list->precison;
					if (list->type < 0)//check minus
					{
						list->width -= 1;
						j = ft_width(j, list);
						j = ft_dec_neg(j, len, list);
					}
					else
					{
						j = ft_width(j, list);
						j = ft_prec(j, len, list);
					}
				}
				else
				{
					if (list->type < 0)//check minus
						j = ft_dec_neg(j, len, list);
					else
						j = ft_prec(j, len, list);
				}
			}
			else if (list->width <= len && list->precison > len)
			{
				if (list->type < 0)//check minus
					j = ft_dec_neg(j, len, list);
				else
					j = ft_prec(j, len, list);	
			}
			else if (list->width > len && list->precison <= len)
			{
				list->width -= len;
				j = ft_width(j, list);
				ft_putnbr_fd(list->type, 1);
				j += len;
			}
			else
			{
				ft_putnbr_fd(list->type, 1);
				j += len;
			}
		}
		else if (list->width != 0 && list->precison == 0)//width
		{
			if (list->width > len)
			{
				list->width -= len;
				j = ft_width(j, list);
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
			if (list->precison > len && list->type >= 0)
				j = ft_prec(j, len, list);
			else if (list->precison > len && list->type < 0)//for negative numbers
				j = ft_dec_neg(j, len, list);//check minus
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
	}
	else if (list->minus == 1)//there is a minus in the structure
	{
		if (list->width != 0 && list->precison != 0)//width and precision
		{
			if (list->width > len && list->precison > len)
			{
				if (list->width > list->precison)
				{
					list->width -= list->precison;
					if (list->type < 0)//check minus
					{
						list->width -= 1;
						j = ft_dec_neg(j, len, list);
					}
					else
					{
						j = ft_prec(j, len, list);
						j = ft_width(j, list);
					}
				}
				else
				{
					if (list->type < 0)//check minus
						j = ft_dec_neg(j, len, list);
					else
						j = ft_prec(j, len, list);
				}
			}
			else if (list->width <= len && list->precison > len)
			{
				if (list->type < 0)//check minus
					j = ft_dec_neg(j, len, list);
				else
					j = ft_prec(j, len, list);
			}
			else if (list->width > len && list->precison <= len)
			{
				list->width -= len;
				ft_putnbr_fd(list->type, 1);
				j += len;
				j = ft_width(j, list);
			}
			else
			{
				ft_putnbr_fd(list->type, 1);
				j += len;
			}
		}
		else if (list->width != 0 && list->precison == 0)//width
		{
			if (list->width > len)
			{
				list->width -= len;
				ft_putnbr_fd(list->type, 1);
				j += len;
				j = ft_width(j, list);
			}
			else
			{
				ft_putnbr_fd(list->type, 1);
				j += len;
			}
		}
		else if (list->precison != 0 && list->width == 0)//precision
		{
			if (list->precison > len && list->type >= 0)
				j = ft_prec(j, len, list);
			else if (list->precison > len && list->type < 0)//for negative numbers
				j = ft_dec_neg(j, len, list);//check minus
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
	}
	return (j);
}