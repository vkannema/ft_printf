/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:20:34 by vkannema          #+#    #+#             */
/*   Updated: 2016/12/16 09:06:31 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

int	main()
{
	printf("%d\n", printf("printf octal : %x\n", 42));
	ft_putoctal(42);
//	ft_printf("Mine : %d, % d, %d, %s, %s, %c\n", 50 , 20 , 30, "ok", "oklm", 'c');
//	printf("test %d", ft_printf("test"));
	return (0);
}
