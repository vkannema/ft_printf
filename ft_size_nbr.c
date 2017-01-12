/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 14:47:24 by vkannema          #+#    #+#             */
/*   Updated: 2017/01/12 12:08:58 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_size_oct(unsigned long long nb)
{
	{
		size_t	beg;
		size_t	end;
		int		i;

		end = nb % 8;
		beg = (nb - end) / 8;
		i = 1;
		while (beg)
		{
			end = beg % 8;
			beg = (beg - end) / 8;
			i++;
		}
		return (i);
	}
}

int	ft_size_nbr(long long n)
{
	long long	ind;
	int				size;

	size = 0;
	if (n >= 0 && n <= 9)
		return (1);
	if (n < 0)
	{
		ind = -n;
		size++;
	}
	else if (n == 0)
		return (1);
	else
		ind = n;
	while (ind > 0)
	{
		ind = ind / 10;
		size++;
	}
	return (size);
}

int		ft_size_abs(long long n)
{
	long long	ind;
	int				size;

	size = 0;
	if (n >= 0 && n <= 9)
		return (1);
	if (n < 0)
		n = -n;
	else if (n == 0)
		return (1);
	ind = n;
	while (ind > 0)
	{
		ind = ind / 10;
		size++;
	}
	return (size);
}

int	ft_size_hexa(unsigned long long nb)
{
	size_t	beg;
	size_t	end;
	int		i;

	i = 0;
	end = nb % 16;
	beg = (nb - end) / 16;
	i++;
	while (beg)
	{
		end = beg % 16;
		beg = (beg - end) / 16;
		i++;
	}
	return (i);
}

int	ft_size_unsigned(unsigned long long n)
{
	unsigned long long	ind;
	int					size;

	size = 0;
	if (n > 0 && n <= 9)
		return (1);
	else if (n == 0)
		return (1);
	else
		ind = n;
	while (ind > 0)
	{
		ind = ind / 10;
		size++;
	}
	return (size);
}
