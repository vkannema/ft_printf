/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 12:41:38 by vkannema          #+#    #+#             */
/*   Updated: 2017/01/04 11:43:08 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_pe(va_list ap, t_env *env)
{
	int	ret;
	(void) ap;

	ret = ft_putchar('%');
	env->size += ret;
	return (ret);
}
