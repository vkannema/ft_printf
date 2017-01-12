/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preci_and_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 12:08:31 by vkannema          #+#    #+#             */
/*   Updated: 2017/01/12 18:21:47 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int			get_space(t_env *env, long long nb, int zero)
{
	int	space;

	space = 0;
	if (env->precision == 0 && nb == 0)
		space = env->width;
	else if (zero != 0 && nb >= 0)
		space = env->width - zero - ft_size_abs(nb);
	else if (zero != 0 && nb < 0)
		space = env->width - zero - ft_size_nbr(nb);
	else if (zero == 0 && nb >= 0)
		space = env->width - ft_size_abs(nb);
	else if (zero == 0 && nb < 0)
		space = env->width - ft_size_nbr(nb);
	if (space_flag(env) == 1 || (pos_flag(env) == 1 && nb >= 0))
		space--;
	return (space);

}

static void		ft_print(int space, int zero, long long nb, t_env *env)
{
	int	i;
	int	neg;

	i = 0;
	neg = 0;
	if (nb < 0)
		neg = 1;
	while (i < space)
	{
		env->size += ft_putchar(' ');
		i++;
	}
	i = 0;
	if (pos_flag(env) == 1 && neg == 0) // modifie
		env->size += ft_putchar('+');
	if (neg == 1)
		ft_putchar('-');
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
	size = ft_size_abs(nb);
	if (env->precision > size)
		zero = env->precision - size;
	space = get_space(env, nb, zero);
	ft_print(space, zero, nb, env);
	if (env->precision == 0 && nb == 0)
		return (0);
	env->size += ft_size_nbr(nb);
	if (nb < 0)
		nb = -nb;
	ft_putnbr(nb);
	return (0);
}



int	print_preciwidth_di(long long nb, t_env *env)
{
	int	i;
	int	size;
	int j;

	i = 0;
	j = 0;
	size = ft_size_nbr(nb);
	if (env->width > env->precision)
		print_width_precision(nb, env);
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
		env->size += ft_size_nbr(nb);
	}
	return (size);
}
