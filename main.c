/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:20:34 by vkannema          #+#    #+#             */
/*   Updated: 2016/12/22 18:19:17 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

int	main()
{
	printf("%d\n\n", printf("%d\n", 42));

//	ft_printf("Mine : %d, % d, %d, %s, %s, %c\n", 50 , 20 , 30, "ok", "oklm", 'c');
	ft_printf("mine %d\n\n", ft_printf("%d\n", 42));
	return (0);
}
