/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 15:44:55 by vkannema          #+#    #+#             */
/*   Updated: 2016/12/21 22:47:21 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

t_env	*init_env(void)
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env));
	env->i = 0;
	env->size = 0;
	env->flag = 0;
	env->type = 0;
	return (env);
}

void	init_flag(t_env *env)
{
	env->flag = 1;
}

int	ft_printf(const char *format, ...)
{
	t_env		*env;
	va_list		ap;

	va_start(ap, format);
	env = init_env();
	while (format[env->i])
	{
		if (format[env->i] == '%')
			init_flag(env);
/*		if (env->flag == 1 && check_flag(format[env->i]) != 0)
			add_flag(env, )
*/
		else if (env->flag == 1 && check_type(format[env->i], env) != 0)
			print_arg(ap, env, format[env->i]);
		else
			env->size += ft_putchar(format[env->i]);
		env->i++;
	}
	va_end(ap);
	return (env->size);
}
