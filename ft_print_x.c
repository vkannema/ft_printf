/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 17:15:56 by vkannema          #+#    #+#             */
/*   Updated: 2017/01/06 14:43:52 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_get_size_hexa(unsigned int nb, int i)
{
	size_t	beg;
	size_t	end;

	end = nb % 16;
	beg = (nb - end) / 16;
	i++;
	while (beg)
	{
		end = beg % 16;
		beg = (beg - end) / 16;
		i++;
	}
	return (i);
}

void	ft_puthexa(unsigned int nb)
{
	size_t beg;
	size_t end;
	const char	*base;

	base = "0123456789abcdef";
	end = nb % 16;
	beg = (nb - end) / 16;
	if (beg)
		ft_puthexa(beg);
	ft_putchar(base[end]);
}

int	ft_print_x(va_list ap, t_env *env)
{
	int			ret;
	unsigned int	nb;


	ret = 0;
	nb = va_arg(ap, unsigned int);
/*	if (neg_flag(env) == 1)
		return (print_width_x_minus(nb, env));
*/	if (hashtag_flag(env) == 1)
		ret += ft_putstr("0x");
	if (env->precision == -1)
	{
		ret += ft_get_size_hexa(nb, 0);
		ft_puthexa(nb);
		env->size += ret;
		return (ret);
	}
	ret += print_precision_x(nb, env);
	env->size += ret;
	return (ret);
}
