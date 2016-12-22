/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 17:15:56 by vkannema          #+#    #+#             */
/*   Updated: 2016/12/22 17:48:43 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

static int	ft_puthexa(unsigned int nb, int ret)
{
	size_t beg;
	size_t end;
	const char	*base;

	base = "0123456789abcdef";
	end = nb % 16;
	beg = (nb - end) / 16;
	if (beg)
		ft_puthexa(beg, ret++);
	ft_putchar(base[end]);
	return (ret);
}

int	ft_print_x(va_list ap, t_env *env)
{
	int			ret;
	unsigned int	nb;

	nb = va_arg(ap, unsigned int);
	ret = ft_puthexa(nb, 1);
	env->size = ret;
	return (ret);

}
