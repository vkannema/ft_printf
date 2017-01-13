/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 21:29:05 by vkannema          #+#    #+#             */
/*   Updated: 2017/01/13 11:44:53 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		ft_size_un(unsigned long int nb)
{
	int	i;

	i = 0;
	if (nb <= 9)
		return (1);
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

void			ft_putp(unsigned long int nb)
{
	size_t		beg;
	size_t		end;
	const char	*base;

	base = "0123456789abcdef";
	end = nb % 16;
	beg = (nb - end) / 16;
	if (beg)
		ft_putp(beg);
	ft_putchar(base[end]);
}

int				ft_print_p(va_list ap, t_env *env)
{
	int					ret;
	unsigned long int	nb;

	nb = va_arg(ap, unsigned long int);
	ft_putstr("0x");
	ft_putp(nb);
	ret = ft_size_un(nb);
	env->size += ret;
	return (ret);
}
