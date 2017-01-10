/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 14:47:24 by vkannema          #+#    #+#             */
/*   Updated: 2017/01/10 10:54:44 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_size_oct(unsigned int nb, int i)
{
	{
		size_t	beg;
		size_t	end;

		end = nb % 8;
		beg = (nb - end) / 8;
		i++;
		while (beg)
		{
			end = beg % 8;
			beg = (beg - end) / 8;
			i++;
		}
		return (i);
	}
}

int	ft_size_nbr(int n)
{
	unsigned int	ind;
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

int		ft_size_abs(int n)
{
	unsigned int	ind;
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
