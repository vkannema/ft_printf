/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 18:01:21 by vkannema          #+#    #+#             */
/*   Updated: 2016/12/27 14:49:43 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_max_value(void)
{
	const char	*str;
	int			i;

	str = "2147483648";
	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void		ft_putnbr(int n)
{
	if (n < 0 && n > -2147483648)
	{
		n = -n;
		ft_putchar('-');
	}
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_max_value();
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	if (n <= 9 && n >= 0)
		ft_putchar(n + '0');
//	printf("i %d\n", i);
}

int	ft_print_di(va_list ap, t_env *env)
{
	int	ret;
	int	nb;

	nb = va_arg(ap, int);
	ft_putnbr(nb);
	ret = ft_size_nbr(nb);
	env->size += ret;
	return (ret);
}
