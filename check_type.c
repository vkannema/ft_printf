/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 11:12:12 by vkannema          #+#    #+#             */
/*   Updated: 2016/12/16 11:13:54 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	check_type(char c)
{
	const char	*types;
	int			i;

	i = 0;
	types = "sSpdDioOuUxXcC";
	while (types[i])
	{
		if (c == types[i])
			return (1);
		i++;
	}
	return (0);
}
