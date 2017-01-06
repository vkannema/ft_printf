/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 10:59:09 by vkannema          #+#    #+#             */
/*   Updated: 2017/01/06 12:51:02 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_flag	*ft_lstadd(t_flag **alst, t_flag *new)
{
	if (*alst)
	{
		new->next = *alst;
		*alst = new;
	}
	if (!(*alst))
		*alst = new;
	return (*alst);
}

void	add_flag(t_env *env, char value, int pos)
{
	t_flag	*new_flag;

	new_flag = (t_flag *)malloc(sizeof(t_flag));
	new_flag->value = value;
	new_flag->pos = pos;
	env->flags->first = ft_lstadd(&new_flag, new_flag);
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
