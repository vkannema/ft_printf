/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_width_di_minus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 14:45:41 by vkannema          #+#    #+#             */
/*   Updated: 2017/01/06 14:49:56 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	print_width(int nb, t_env *env)
{
	int	size;
	int width;
	int	i;

	size = ft_size_nbr(nb);
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

int	ft_print_di(va_list ap, t_env *env)
{
	int	ret;
	int	nb;

	ret = 0;
	nb = va_arg(ap, int);
	if (neg_flag(env) == 1)
		return (print_width_di_minus(nb, env));
	if (env->width != -1 && env->width > env->precision)
		ret = print_width(nb, env);
	if (env->precision == -1)
	{
		ft_putnbr(nb);
		ret = ft_size_nbr(nb);
		env->size += ret;
		return (ret);
	}
	env->size += print_precision_di(nb, env);
	return (ret);
}
