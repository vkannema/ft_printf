/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 11:32:12 by vkannema          #+#    #+#             */
/*   Updated: 2017/01/05 11:20:52 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	get_width(const char *format, int i, t_env *env)
{
	int	width;

	if (format[i] == '0')
		env->zero_width = 1;
	width = ft_atoi(&format[i]);
	while (ft_isdigit(format[i]))
		i++;
	i--;
	env->width = width;
	return (i);
}
