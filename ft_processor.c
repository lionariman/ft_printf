/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keuclide <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:54:59 by keuclide          #+#    #+#             */
/*   Updated: 2020/12/10 15:04:31 by keuclide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_processor(char *s, va_list argptr, new_list *list)
{
	int j;

	j = 0;
	if (*s == 'c')
		j = ft_char_type(argptr, list);
	if (*s == 'd' || *s == 'i' || *s == 'u')
		j = ft_dec_type(argptr, list, s);
	if (*s == 's')
		j = ft_str_type(argptr, list);
	if (*s == 'x' || *s == 'X')
		j = ft_hex_type(argptr, list, s);
	if (*s == 'p')
	 	j = ft_ptr_type(argptr, list);
	// if (*s == '%')
	//  	j = ft_prc_type(argptr, list, s);
	return (j);
}
