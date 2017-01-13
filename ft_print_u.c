/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 11:57:14 by vkannema          #+#    #+#             */
/*   Updated: 2017/01/13 11:51:43 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		print_width(unsigned long long nb, t_env *env)
{
	int	size;
	int	width;
	int	i;

	i = 0;
	size = ft_size_unsigned(nb);
	width = env->width - size;
	if (zero_flag(env) == 0)
	{
		while (width > i)
		{
			env->size += ft_putchar(' ');
			i++;
		}
	}
	if (zero_flag(env) == 1)
	{
		while (width > i)
		{
			env->size += ft_putchar('0');
			i++;
		}
	}
	return (0);
}

static int		get_space(t_env *env, long long nb, int zero)
{
	int	space;

	space = 0;
	if (env->precision == 0 && nb == 0)
		space = env->width;
	else if (zero != 0 && nb >= 0)
		space = env->width - zero - ft_size_unsigned(nb);
	else if (zero == 0 && nb >= 0)
		space = env->width - ft_size_unsigned(nb);
	return (space);
}

static void		ft_print(int space, int zero, t_env *env)
{
	int	i;

	i = 0;
	while (i < space)
	{
		env->size += ft_putchar(' ');
		i++;
	}
	i = 0;
	while (i < zero)
	{
		env->size += ft_putchar('0');
		i++;
	}
}

static int		print_width_precision(int nb, t_env *env)
{
	int	space;
	int	zero;
	int	size;

	zero = 0;
	size = ft_size_unsigned(nb);
	if (env->precision > size)
		zero = env->precision - size;
	space = get_space(env, nb, zero);
	ft_print(space, zero, env);
	if (env->precision == 0 && nb == 0)
		return (0);
	env->size += ft_size_unsigned(nb);
	if (nb != 0)
		ft_putunsigned(nb);
	return (0);
}

static int		print_preciwidth_u(unsigned long long nb, t_env *env)
{
	int	i;
	int	size;
	int j;

	i = 0;
	j = 0;
	size = ft_size_hexa(nb);
	if (env->width > env->precision)
		print_width_precision(nb, env);
	else
	{
		if (size < env->precision)
		{
			i = env->precision - size;
			while (j < i)
			{
				env->size += ft_putchar('0');
				j++;
			}
		}
		if (nb != 0)
			ft_putunsigned(nb);
		env->size += ft_size_unsigned(nb);
	}
	return (size);
}

int				ft_print_u(va_list ap, t_env *env)
{
	int					ret;
	unsigned long long	nb;

	ret = 0;
	nb = convert_u(ap, env);
	if (neg_flag(env) == 1)
	{
		ft_putunsigned(nb);
		print_width(nb, env);
		env->size += ft_size_unsigned(nb);
		return (ret);
	}
	if (env->width == -1 && env->precision == -1)
	{
		ft_putunsigned(nb);
		env->size += ft_size_unsigned(nb);
	}
	else if (env->width != -1 && env->precision == -1)
	{
		ret = print_width(nb, env);
		env->size += ft_size_unsigned(nb);
		ft_putunsigned(nb);
	}
	else if (env->width == -1 && env->precision != -1)
		env->size += print_precision_u(nb, env);
	else if (env->width != -1 && env->precision != -1)
		print_preciwidth_u(nb, env);
	return (ret);
}
