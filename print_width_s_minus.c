/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_width_s_minus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 13:56:03 by vkannema          #+#    #+#             */
/*   Updated: 2017/01/06 14:49:53 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	print_width(char *str, t_env *env)
{
	int	size;
	int width;
	int	i;

	if (env->precision != -1)
		size = env->precision;
	else
		size = ft_strlen(str);
	width = 0;
	i = 0;
	if (env->width > size && env->zero_width == 0)
	{
		width = env->width - size;
		while (width > i)
		{
			env->size += ft_putchar(' ');
			i++;
		}
	}
	else if (env->width > size && env->zero_width == 1)
	{
		width = env->width - size;
		while (width > i)
		{
			env->size += ft_putchar('0');
			i++;
		}
	}
	return (width);
}

int	print_width_s_minus(char *str, t_env *env)
{
	int	ret;

	ret = 0;
	if (!(str))
	{
		ret += ft_putstr("(null)");
		ret += print_width("(null)", env);
		return (ret);
	}
	if (env->precision == -1)
	{
		ret = ft_putstr(str);
		env->size += ret;
		return (ret);
	}
	if (env->width != -1)
		ret += print_width(str, env);
	env->size += print_precision_s(str, env);
	return (ret);
}
