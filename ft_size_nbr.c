/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 14:47:24 by vkannema          #+#    #+#             */
/*   Updated: 2016/12/27 14:49:34 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_size_nbr(int n)
{
	unsigned int	ind;
	int				size;

	size = 0;
	if (n < 0)
		ind = -n;
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
