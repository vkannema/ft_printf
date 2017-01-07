/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 18:01:21 by vkannema          #+#    #+#             */
/*   Updated: 2017/01/07 10:14:26 by vkannema         ###   ########.fr       */
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
	{
		ft_putnbr(nb);
		print_width(nb, env);
		env->size += ft_size_nbr(nb);
		return (ret);
	}
	if (space_flag(env) == 1)
	{
		if (nb < 0)
			ft_putchar(' ');
		else
			ft_putchar ('-');
	}
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
