/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 17:04:51 by vkannema          #+#    #+#             */
/*   Updated: 2017/01/04 11:42:47 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_o(va_list ap, t_env *env)
{
	int	ret;
	unsigned int nb;

	ret = 0;
	nb = va_arg(ap, unsigned int);
	if (hashtag_flag(env) == 1)
		ret += ft_putchar('0');
	ft_putoctal(nb);
	ret += ft_size_nbr(nb) + 1;
	env->size += ret;
	return (ret);
}
