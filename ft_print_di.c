/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 18:01:21 by vkannema          #+#    #+#             */
/*   Updated: 2016/12/22 18:18:48 by vkannema         ###   ########.fr       */
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

int		ft_putnbr(int n, int i)
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
		return (10);
	}
	if (n > 9)
	{
		ft_putnbr(n / 10, i);
		ft_putnbr(n % 10, i);
		i++;
	}
	if (n <= 9 && n >= 0)
		ft_putchar(n + '0');
	return (i);
}

int	ft_print_di(va_list ap, t_env *env)
{
	int	ret;
	int	nb;
	(void) env;

	nb = va_arg(ap, int);
	ret = ft_putnbr(nb, 0);
	return (ret);
}
