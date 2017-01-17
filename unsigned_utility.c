/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_utility.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 12:35:48 by vkannema          #+#    #+#             */
/*   Updated: 2017/01/13 12:37:37 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_print_un(int space, int zero, t_env *env)
{
	int	i;

	i = 0;
	while (i < space)
	{
		env->size += ft_putchar(' ');
		i++;
	}
	i = 0;
	while (i < zero)
	{
		env->size += ft_putchar('0');
		i++;
	}
}
