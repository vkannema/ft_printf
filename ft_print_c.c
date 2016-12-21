/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 20:58:53 by vkannema          #+#    #+#             */
/*   Updated: 2016/12/21 21:32:10 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_c(va_list ap, t_env *env)
{
	int		ret;
	char	c;

	c = va_arg(ap, int);
	ret = ft_putchar(c);
	env->size += ret;
	return (ret);
}
