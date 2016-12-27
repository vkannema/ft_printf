/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 17:04:51 by vkannema          #+#    #+#             */
/*   Updated: 2016/12/27 15:00:42 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_o(va_list ap, t_env *env)
{
	int	ret;
	unsigned int nb;

	nb = va_arg(ap, unsigned int);
	ft_putoctal(nb);
	ret = ft_size_nbr(nb) + 1;
	env->size += ret;
	return (ret);
}
