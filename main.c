/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:20:34 by vkannema          #+#    #+#             */
/*   Updated: 2017/01/17 18:33:07 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"
#include <wchar.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

int	main(void)
{
	int	i;

	setlocale(LC_ALL, "");
	i = 0;
	printf("%d\n\n", printf("%C\n", 945));
	ft_printf("%d\n\n", ft_printf("%C\n", 945));
	while (i < 42)
		;
	return (0);
}
