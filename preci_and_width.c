/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preci_and_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 12:08:31 by vkannema          #+#    #+#             */
/*   Updated: 2017/01/09 16:32:00 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	print_width_precision(int nb, t_env *env)
{
	int	i;
	int	white;
	int	size;
	int check;

	check = 0;
	size = ft_size_nbr(nb);
	if (env->precision < size)
		white = env->width - size;
	else
		white = env->width - env->precision;
	i = 0;
	if (nb < 0)
	{
		i++;
		white++;
	}
	while (i < white)
	{
		env->size += ft_putchar(' ');
		i++;
	}
	if (nb < 0)
	{
		env->size += ft_putchar('-');
		check = 1;
	}
	if (size < env->precision)
	{
		i = env->precision - size + check;
		while (i <= env->precision)
		{
			env->size += ft_putchar('0');
			i++;
		}
	}
	return (i);
}



int	print_preciwidth_di(int nb, t_env *env)
{
	int	i;
	int	size;
	int j;

	i = 0;
	j = 0;
	size = ft_size_nbr(nb);
	if (env->width > env->precision)
	{
		print_width_precision(nb, env);
		if (nb < 0)
			nb = -nb;
		ft_putnbr(nb);
	}
	else
	{
		if (nb < 0)
		{
			env->size += ft_putchar('-');
			size--;
		}
		if (size < env->precision)
		{
			i = env->precision - size;
			while (j < i)
			{
				env->size += ft_putchar('0');
				j++;
			}
		}
		if (nb < 0)
			nb = -nb;
		ft_putnbr(nb);
	}
	env->size += ft_size_nbr(nb);
	return (size);
}
