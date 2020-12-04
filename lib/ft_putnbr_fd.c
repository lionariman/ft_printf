/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keuclide <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 14:35:50 by keuclide          #+#    #+#             */
/*   Updated: 2020/11/11 22:42:11 by keuclide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	pow(int e)
{
	long z;

	z = 1;
	while (e--)
		z *= 10;
	return (z);
}

static void	ptnbr(long n, long z, int i, int fd)
{
	char m;

	while (i != 0)
	{
		m = (n / (10 * z)) % 10 + '0';
		ft_putchar_fd(m, fd);
		z /= 10;
		i--;
		if (i == 0)
		{
			i = 2;
			z = 10;
			while (i != 0)
			{
				m = (n / (1 * z)) % 10 + '0';
				ft_putchar_fd(m, fd);
				z /= 10;
				i--;
			}
		}
	}
}

static int	size(long v)
{
	int i;

	i = 0;
	while (v / 10 != 0)
	{
		v /= 10;
		i++;
	}
	i -= 1;
	return (i);
}

static void	two(long n, int fd)
{
	char	m;
	int		z;
	int		i;

	i = 2;
	z = 10;
	while (i != 0)
	{
		m = (n / (1 * z)) % 10 + '0';
		ft_putchar_fd(m, fd);
		z /= 10;
		i--;
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	long	v;
	int		i;
	long	z;

	v = n;
	if (v < 0)
	{
		v *= -1;
		ft_putchar_fd('-', fd);
	}
	if (v > 99)
	{
		i = size(v);
		z = pow(i);
		ptnbr(v, z, i, fd);
	}
	if (v < 100 && v > 9)
		two(v, fd);
	if (v < 10 && v >= 0)
		ft_putchar_fd((v + '0'), fd);
}
