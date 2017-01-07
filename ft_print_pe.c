/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 12:41:38 by vkannema          #+#    #+#             */
/*   Updated: 2017/01/07 10:48:45 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	print_width(t_env *env)
{
	int	size;
	int width;
	int	i;

	size = 1;
	width = 0;
	i = 1;
	if (env->width > size && env->zero_width == 0)
	{
		width = env->width - size;
		while (width >= i)
		{
			env->size += ft_putchar(' ');
			i++;
		}
	}
	else if (env->width > size && env->zero_width == 1)
	{
		width = env->width - size;
		while (width >= i)
		{
			env->size += ft_putchar('0');
			i++;
		}
	}
	return (width);
}

int	ft_print_pe(va_list ap, t_env *env)
{
	(void) ap;

	if (env->precision == -1 && env->width == -1)
		env->size += ft_putchar('%');
	else if (neg_flag(env) != 1)
	{
		print_width(env);
		env->size += ft_putchar('%');
	}
	else
	{
		env->size += ft_putchar('%');
		print_width(env);
	}
	return (env->size);
}
