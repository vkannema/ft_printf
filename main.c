/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:20:34 by vkannema          #+#    #+#             */
/*   Updated: 2016/12/21 22:43:10 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

int	main()
{
	printf("base %c\n", 'c');

//	ft_printf("Mine : %d, % d, %d, %s, %s, %c\n", 50 , 20 , 30, "ok", "oklm", 'c');
	ft_printf("coucou %s %c %s %c %s", "coucou", 'c', "lol", 'o', "ok");
	return (0);
}
