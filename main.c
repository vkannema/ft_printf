/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:20:34 by vkannema          #+#    #+#             */
/*   Updated: 2017/01/03 16:02:01 by vkannema         ###   ########.fr       */
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
	printf("%d\n\n", printf("%s\n", "coucou bryan"));
	ft_printf("%d\n\n", ft_printf("%s\n", "coucou bryan"));
	return (0);
}
