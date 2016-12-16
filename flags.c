/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 10:59:09 by vkannema          #+#    #+#             */
/*   Updated: 2016/12/16 11:05:53 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	add_flag(t_env *env, char value, int pos)
{

}

int		get_flag(char c)
{
	const char	*flag;
	int			i;

	i = 0;
	flag = "#0-+ ";
	while (flag[i])
	{
		if (c == flag[i])
			return(1);
		i++;
	}
	return (0);
}
