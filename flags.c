/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 10:59:09 by vkannema          #+#    #+#             */
/*   Updated: 2017/01/12 15:41:26 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_flag	*ft_lstnew(char c, int pos)
{
	t_flag		*new_elem;

	if (!(new_elem = malloc(sizeof(t_flag))))
		return (NULL);
	new_elem->value = c;
	new_elem->pos = pos;
	new_elem->next = NULL;
	return (new_elem);
}

void	add_flag(t_env *env, char value, int pos)
{
	t_flag	*new_flag;

	new_flag = ft_lstnew(value, pos);
	if (env->flags->first == NULL)
			env->flags->first = new_flag;
	else
	{
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
	flags = "#-+0 ";
	while (flags[i])
	{
		if (c == flags[i])
			return (1);
		i++;
	}
	return (0);
}
