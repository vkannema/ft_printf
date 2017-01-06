/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:20:34 by vkannema          #+#    #+#             */
/*   Updated: 2017/01/06 12:31:34 by vkannema         ###   ########.fr       */
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
	const char *format;
	int			a;
	int			*b;

	a = 10;
	b = &a;
	format = "cou.234 c 42";
	printf("%d\n\n", printf("%#x %x\n", 42, 42));
	printf("%d\n\n", printf("%#x %x\n", 42, 42));
//	ft_printf("%d\n\n", ft_printf("%08.2d\n", 0));
	return (0);
}
