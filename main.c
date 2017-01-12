/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:20:34 by vkannema          #+#    #+#             */
/*   Updated: 2017/01/12 18:35:12 by vkannema         ###   ########.fr       */
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

	printf("%d\n\n", printf("p  | %lld\n", -9223372036854775807));
	ft_printf("%d\n\n", ft_printf("ft | %lld\n", -9223372036854775807));
//	printf("%d\n\n", printf("%d\n", 1));
	return (0);
}
