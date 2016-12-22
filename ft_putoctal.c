/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putoctal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 21:19:26 by vkannema          #+#    #+#             */
/*   Updated: 2016/12/22 17:10:31 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putoctal(unsigned int nb, int ret)
{
	size_t	beg;
	size_t	end;
	const char	*base;


	base = "01234567";
	end = nb % 8;
	beg = (nb - end) / 8;
	if (beg)
		ft_putoctal(beg, ret++);
	ft_putchar(base[end]);
	return (ret);
}
