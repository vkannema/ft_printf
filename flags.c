/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 10:59:09 by vkannema          #+#    #+#             */
/*   Updated: 2017/01/04 10:21:18 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	add_flag(t_env *env, char value, int pos)
{
	t_flag	*new_flag;

	new_flag = (t_flag *)malloc(sizeof(t_flag));
	new_flag->value = value;
	new_flag->pos = pos;
	if (env->flags->last == NULL)
	{
		new_flag->next = NULL;
		env->flags->last = new_flag;
		env->flags->first = new_flag;
	}
	else
	{
		env->flags->first->prev = new_flag;
		new_flag->next = env->flags->first;
		env->flags->first = new_flag;
	}
	env->flags->nb++;
}

int		check_flag(char c)
{
	const char	*flags;
	int			i;

	i = 0;
	flags = "#0-+ ";
	while (flags[i])
	{
		if (c == flags[i])
			return (1);
		i++;
	}
	return (0);
}
