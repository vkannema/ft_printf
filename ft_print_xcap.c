/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xcap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 12:33:04 by vkannema          #+#    #+#             */
/*   Updated: 2017/01/04 11:42:45 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_puthexcap(unsigned int nb)
{
	size_t		beg;
	size_t		end;
	const char	*base;

	base = "0123456789ABCDEF";
	end = nb % 16;
	beg = (nb - end) / 16;
	if (beg)
		ft_puthexcap(beg);
	ft_putchar(base[end]);
}

int	ft_print_xcap(va_list ap, t_env *env)
{
	unsigned int	nb;
	int				ret;

	ret = 0;
	nb = va_arg(ap, unsigned int);
	if (hashtag_flag(env) == 1)
		ret += ft_putstr("0X");
	ft_puthexcap(nb);
	ret += ft_size_nbr(nb);
	env->size += ret;
	return (ret);
}
