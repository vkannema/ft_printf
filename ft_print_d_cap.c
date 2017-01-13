/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_cap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 11:15:59 by vkannema          #+#    #+#             */
/*   Updated: 2017/01/13 12:18:57 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		print_width(long long nb, t_env *env)
{
	int	size;
	int width;
	int	i;

	size = ft_size_nbr(nb) + space_flag(env);
	width = 0;
	i = 1;
	if (zero_flag(env) == 0 || (zero_flag(env) == 1 && neg_flag(env) == 1))
	{
		width = env->width - size;
		while (width >= i)
		{
			env->size += ft_putchar(' ');
			i++;
		}
		if (neg_flag(env) != 1)
			ft_putnbr(nb);
	}
	else if (zero_flag(env) == 1 && nb < 0 && neg_flag(env) != 1)
	{
		env->size += ft_putchar('-');
		width = env->width - size;
		while (width >= i)
		{
			env->size += ft_putchar('0');
			i++;
		}
		nb = -nb;
		ft_putnbr(nb);
		env->size--;
	}
	else if (zero_flag(env) == 1 && neg_flag(env) != 1)
	{
		width = env->width - size - pos_flag(env);
		while (width >= i)
		{
			env->size += ft_putchar('0');
			i++;
		}
		ft_putnbr(nb);
	}
	return (width);
}

int				ft_print_d_cap(va_list ap, t_env *env)
{
	int			ret;
	long long	nb;

	ret = 0;
	nb = va_arg(ap, long);
	if (neg_flag(env) == 1)
	{
		env->size += print_precision_di(nb, env);
		print_width(nb, env);
		return (ret);
	}
	if (pos_flag(env) == 1 && nb >= 0 && env->precision == -1)
		env->size += ft_putchar('+');
	if (space_flag(env) == 1)
	{
		if (nb >= 0 && pos_flag(env) == 0)
			env->size += ft_putchar(' ');
		if (nb < 0)
			env->size += ft_putchar('-');
	}
	if (nb < 0 && space_flag(env) == 1)
		nb = -nb;
	if (env->width == -1 && env->precision == -1)
	{
		ft_putnbr(nb);
		env->size += ft_size_nbr(nb);
	}
	else if (env->width != -1 && env->precision == -1)
	{
		ret = print_width(nb, env);
		env->size += ft_size_nbr(nb);
	}
	else if (env->width == -1 && env->precision != -1)
		env->size += print_precision_di(nb, env);
	else if (env->width != -1 && env->precision != -1)
		print_preciwidth_di(nb, env);
	return (ret);
}
