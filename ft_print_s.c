/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 20:34:30 by vkannema          #+#    #+#             */
/*   Updated: 2017/01/05 12:16:46 by vkannema         ###   ########.fr       */
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

int	ft_print_s(va_list ap, t_env *env)
{
	int		ret;
	char	*str;

	str = va_arg(ap, char *);
	ret = 0;
	if (!(str))
	{
		ret += ft_putstr("null");
		return (ret);
	}
	if (env->width != -1)
		ret = print_width(str, env);
	if (env->precision == -1)
	{
		ret = ft_putstr(str);
		env->size += ret;
		return (ret);
	}
	env->size += print_precision_s(str, env);
	return (ret);
}
