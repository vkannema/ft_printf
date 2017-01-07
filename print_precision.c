/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 14:10:14 by vkannema          #+#    #+#             */
/*   Updated: 2017/01/07 12:29:31 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_precision_o(unsigned int nb, t_env *env)
{
	int	size;
	int	precision;
	int	ret;

	ret = 0;
	precision = env->precision;
	size = ft_size_oct(nb, 0);
	ret += size;
	while (size < precision)
	{
		ft_putchar('0');
		size++;
		ret++;
	}
	ft_putoctal(nb);
	return (ret);
}

int	print_precision_x(unsigned int nb, t_env *env)
{
	int	size;
	int	precision;
	int	ret;

	ret = 0;
	size = ft_get_size_hexa(nb, 0);
	precision = env->precision;
	while (size <= precision)
	{
		ft_putchar('0');
		size++;
		ret++;
	}
	ft_puthexa(nb);
	ret += ft_get_size_hexa(nb, 0);
	return (ret);
}

int	print_precision_s(char *str, t_env *env)
{
	int	precision;
	int	ret;
	int	i;
	int	size;

	ret = 0;
	i = 0;
	size = ft_strlen(str);
	precision = env->precision;
	ret += size;
	if (str[0] == '\0' && env->width != -1)
	{
		while (i < env->width)
		{
			ft_putchar(' ');
			i++;
		}
		return (env->width);
	}
	if (env->width != -1 && neg_flag(env) == 0)
		print_width_str(str, env);
	if (size > precision)
	{
		while (i != precision)
		{
			ret += ft_putchar(str[i]);
			i++;
		}
	}
	else
	{
		ft_putstr(str);
		return(size);
	}
	if (neg_flag(env) == 1)
		print_width_str(str, env);
	return (i);
}

int	print_precision_di(int nb, t_env *env)
{
	int	size;
	int	precision;
	int ret;

	ret = 0;
	precision = env->precision;
	size = ft_size_nbr(nb);
	ret += size;
	if (nb < 0)
	{
			ft_putchar('-');
			nb = -nb;
			precision++;
	}
	while (size < precision)
	{
		ft_putchar('0');
		size++;
		ret++;
	}
	ft_putnbr(nb);
	return (ret);
}
