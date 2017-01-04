/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:20:34 by vkannema          #+#    #+#             */
/*   Updated: 2017/01/04 16:29:22 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"
#include <wchar.h>
#include <stdlib.h>
#include <ctype.h>

int	main()
{
	const char *format;
	int			a;
	int			*b;

	a = 10;
	b = &a;
	format = "cou.234 c 42";
	printf("%d\n\n", printf("%.42x\n", 42));
	printf("%d\n\n", printf("%o\n", 42));
//	ft_printf("%d\n\n", ft_printf("%.d\n", 12345));
	return (0);
}
