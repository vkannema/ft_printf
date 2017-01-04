/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 11:12:12 by vkannema          #+#    #+#             */
/*   Updated: 2017/01/04 10:21:28 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	check_type(char c, t_env *env)
{
	const char	*types;
	int			i;

	i = 0;
	types = "sSpdDioOuUxXcC%";
	while (types[i])
	{
		if (c == types[i])
		{
			env->conv = types[i];
			return (1);
		}
		i++;
	}
	return (0);
}
