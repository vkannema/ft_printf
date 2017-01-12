/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 17:04:51 by vkannema          #+#    #+#             */
/*   Updated: 2017/01/12 15:45:16 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	print_width_neg(unsigned long long nb, t_env *env)
{
	int	size;
	int	width;
	int	i;
	int	flag;

	i = 0;
	flag = hashtag_flag(env);
	size = ft_size_oct(nb);
	width = env->width - size;
	if (flag == 1)
		width--;
	if (env->zero_width == 0 || neg_flag(env) == 1)
	{
		while (width > i)
		{
			env->size += ft_putchar(' ');
			i++;
		}
	}
	if (env->zero_width == 1)
	{
		while (width > i)
		{
			env->size+= ft_putchar('0');
			i++;
		}
	}
	return (0);
}

static int	print_width(unsigned long long nb, t_env *env)
{
	int	size;
	int	width;
	int	i;
	int	flag;

	i = 0;
	flag = hashtag_flag(env);
	size = ft_size_hexa(nb);
	width = env->width - size;
	if (flag == 1)
		width -= 2;
	if (zero_flag(env) == 0)
	{
		while (width > i)
		{
			env->size += ft_putchar(' ');
			i++;
		}
		if (hashtag_flag(env) == 1 && nb != 0)
			env->size += ft_putchar('0');
	}
	if (zero_flag(env) == 1)
	{
		if (hashtag_flag(env) == 1 && nb != 0)
			env->size += ft_putchar('0');
		while (width > i)
		{
			env->size+= ft_putchar('0');
			i++;
		}
	}

	return (0);
}

static int			get_space(t_env *env, long long nb, int zero)
{
	int	space;

	space = 0;
	if (env->precision == 0 && nb == 0)
		space = env->width;
	else if (zero != 0 && nb >= 0)
		space = env->width - zero - ft_size_oct(nb);
	else if (zero == 0 && nb >= 0)
		space = env->width - ft_size_oct(nb);
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

static int	print_width_precision(int nb, t_env *env)
{
	int	space;
	int	zero;
	int	size;

	zero = 0;
	size = ft_size_oct(nb);
	if (env->precision > size)
		zero = env->precision - size;
	space = get_space(env, nb, zero);
	ft_print(space, zero, env);
	if (env->precision == 0 && nb == 0)
		return (0);
	env->size += ft_size_oct(nb);
	if (nb != 0)
		ft_putoctal(nb);
	return (0);
}



static int	print_preciwidth_o(unsigned long long nb, t_env *env)
{
	int	i;
	int	size;
	int j;

	i = 0;
	j = 0;
	size = ft_size_oct(nb);
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
			ft_putoctal(nb);
		env->size += ft_size_oct(nb);
	}
	return (size);
}

int	ft_print_o(va_list ap, t_env *env)
{
	int			ret;
	unsigned long long	nb;


	ret = 0;
	nb = convert_u(ap, env);
	if (neg_flag(env) == 1)
	{
		if (hashtag_flag(env) == 1)
			env->size += ft_putchar('0');
		env->size += print_precision_o(nb, env);
		print_width_neg(nb, env);
		return (ret);
	}
	if (hashtag_flag(env) == 1 && env->width == -1 && nb != 0)
		env->size += ft_putchar('0');
	if (env->width == -1 && env->precision == -1)
	{
		env->size+= ft_size_oct(nb);
		ft_putoctal(nb);
	}
	else if (env->precision == -1 && env->width != -1)
	{
		print_width(nb, env);
		ft_putoctal(nb);
		env->size += ft_size_oct(nb);
	}
	else if (env->width == -1 && env->precision != -1)
		env->size += print_precision_o(nb, env);
	else if (env->width != -1 && env->precision != -1)
		print_preciwidth_o(nb, env);
	return (ret);
}
