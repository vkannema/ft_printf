/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_X.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 17:49:39 by vkannema          #+#    #+#             */
/*   Updated: 2016/12/22 17:50:30 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

static int	ft_puthexa(unsigned int nb, int ret)
{
	size_t beg;
	size_t end;
	const char	*base;

	base = "0123456789ABCDEF";
	end = nb % 16;
	beg = (nb - end) / 16;
	if (beg)
		ft_puthexa(beg, ret++);
	ft_putchar(base[end]);
	return (ret);
}

int	ft_print_X(va_list ap, t_env *env)
{
	int			ret;
	unsigned int	nb;

	nb = va_arg(ap, unsigned int);
	ret = ft_puthexa(nb, 1);
	env->size = ret;
	return (ret);

}
