/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:20:34 by vkannema          #+#    #+#             */
/*   Updated: 2016/12/14 14:23:25 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"
int	main()
{
	printf("Base : %d, %d, %d, %s, %s, %s\n", 50, 20 , 30, "ok", "oklm", "Salut Gérard !");
//	ft_printf("Mine : %d, % d, %d, %s, %s, %c\n", 50 , 20 , 30, "ok", "oklm", 'c');
//	printf("test %d", ft_printf("test"));
	return (0);
}
