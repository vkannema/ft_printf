/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 18:01:21 by vkannema          #+#    #+#             */
/*   Updated: 2017/01/04 16:19:31 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"



int	ft_print_di(va_list ap, t_env *env)
{
	int	ret;
	int	nb;

	ret = 0;
	nb = va_arg(ap, int);
	if (env->precision == -1)
	{
		ft_putnbr(nb);
		ret = ft_size_nbr(nb);
		env->size += ret;
		return (ret);
	}
	ret += print_precision_di(nb, env);
	env->size += ret;
	return (ret);
}
