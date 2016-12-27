/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 17:15:56 by vkannema          #+#    #+#             */
/*   Updated: 2016/12/27 14:55:41 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void	ft_puthexa(unsigned int nb)
{
	size_t beg;
	size_t end;
	const char	*base;

	base = "0123456789abcdef";
	end = nb % 16;
	beg = (nb - end) / 16;
	if (beg)
		ft_puthexa(beg);
	ft_putchar(base[end]);
}

int	ft_print_x(va_list ap, t_env *env)
{
	int			ret;
	unsigned int	nb;

	nb = va_arg(ap, unsigned int);
	ft_puthexa(nb);
	ret = ft_size_nbr(nb);
	env->size += ret;
	return (ret);

}
