/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 14:10:14 by vkannema          #+#    #+#             */
/*   Updated: 2017/01/04 16:28:32 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_precision_x()
{
	
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
	if (size > precision)
	{
		while (i != precision)
		{
			ret += ft_putchar(str[i]);
			i++;
		}
		return (i);
	}
	else
	{
		ft_putstr(str);
		return(size);
	}
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
	while (size < precision)
	{
		ft_putchar('0');
		size++;
		ret++;
	}
	ft_putnbr(nb);
	return (ret);
}
