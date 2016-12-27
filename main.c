/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:20:34 by vkannema          #+#    #+#             */
/*   Updated: 2016/12/27 22:26:39 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"
#include <wchar.h>

int	main()
{
	int	a;

	a = 10;
	printf("%d\n\n", printf("4octal 1 %-12o octal 2 %-12o\n\n", 42, -42));
	printf("%d\n\n", printf("4octal 1 %12o octal 2 %12o\n\n", 42, -42));
//	ft_printf("%d\n\n", ft_printf("%p\n", &a));
	return (0);
}
