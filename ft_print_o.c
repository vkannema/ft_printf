/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 17:04:51 by vkannema          #+#    #+#             */
/*   Updated: 2016/12/22 17:11:40 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_o(va_list ap, t_env *env)
{
	int	ret;
	unsigned int nb;

	nb = va_arg(ap, unsigned int);
	ret = ft_putoctal(nb, 0);
	env->size += ret;
	return (ret);
}
