/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:20:34 by vkannema          #+#    #+#             */
/*   Updated: 2017/01/04 11:42:43 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"
#include <wchar.h>

int	main()
{
	int	a;
	int *b;

	a = 11442;
	b = &a;
	printf("%d\n\n", printf("%+d\n",-123456));
	printf("%d\n\n", printf("%d\n", -123456));
//	ft_printf("%d\n\n", ft_printf("%s\n", "coucou bryan"));
	return (0);
}
