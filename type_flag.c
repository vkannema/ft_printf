/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 08:26:28 by vkannema          #+#    #+#             */
/*   Updated: 2017/01/04 10:21:31 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	hastag_flag(t_env *env)
{
	t_flag	*tmp;

	if (env->flags->nb == 0)
		return (0);
	tmp = env->flags->first;
	while (tmp)
	{
		if (tmp->value == '#')
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	neg_flag(t_env *env)
{
	t_flag *tmp;

	if (env->flags->nb == 0)
		return (0);
	tmp = env->flags->first;
	while (tmp)
	{
		if (tmp->value == '-')
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	pos_flag(t_env *env)
{
	t_flag *tmp;

	if (env->flags->nb == 0)
		return (0);
	tmp = env->flags->first;
	while (tmp)
	{
		if (tmp->value == '+')
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	space_flag(t_env *env)
{
	t_flag *tmp;

	if (env->flags->nb == 0)
		return (0);
	tmp = env->flags->first;
	while (tmp)
	{
		if (tmp->value == ' ')
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	zero_flag(t_env *env)
{
	t_flag *tmp;

	if (env->flags->nb == 0)
		return (0);
	tmp = env->flags->first;
	while (tmp)
	{
		if (tmp->value == '0')
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
