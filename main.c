/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:20:34 by vkannema          #+#    #+#             */
/*   Updated: 2017/01/11 12:21:58 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"
#include <wchar.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

int	main()
{
	setlocale(LC_ALL, "");
	long long c;
	int	size;

	c = 9223372036854775807;
	printf("%d\n\n", printf("%lld\n", c));
	ft_putnbr(c);
	size = ft_size_nbr(c);
	ft_putchar('\n');
	ft_putnbr(size);
//	ft_printf("%d\n\n", ft_printf("%lld\n", c));
//	printf("%d\n\n", printf("%d\n", 1));
	return (0);
}
