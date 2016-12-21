/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:20:34 by vkannema          #+#    #+#             */
/*   Updated: 2016/12/21 21:46:45 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

int	main()
{
	printf("base %s\n", "coucou cest moi");

//	ft_printf("Mine : %d, % d, %d, %s, %s, %c\n", 50 , 20 , 30, "ok", "oklm", 'c');
	ft_printf("test %s", "coucou cest moi");
	return (0);
}
