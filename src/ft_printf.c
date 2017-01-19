/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 15:44:55 by vkannema          #+#    #+#             */
/*   Updated: 2017/01/19 13:38:22 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_env	*init_env(void)
{
	t_env	*env;

	if (!(env = malloc(sizeof(t_env))))
		return (NULL);
	env->i = 0;
	env->size = 0;
	env->flag = 0;
	env->type = 0;
	env->conv = 0;
	env->precision = -1;
	env->width = -1;
	env->zero_width = 0;
	env->modif = 0;
	env->dual = 0;
	env->flags.zero = 0;
	env->flags.pos = 0;
	env->flags.neg = 0;
	env->flags.space = 0;
	env->flags.hashtag = 0;
	return (env);
}

void	parsing(const char *format, t_env *env, va_list ap)
{
	if (ft_isdigit(format[env->i]) && env->conv == 1)
		env->i = get_width(format, env->i, env);
	else if (format[env->i] == '.' && env->conv == 1
		&& format[env->i + 1] != '*')
		env->i = get_precision(format, env->i + 1, env);
	else if (format[env->i] == '.' && env->conv == 1
		&& format[env->i + 1] == '*')
		env->i = get_precision_star(env, ap);
	else if (ft_check_modif(format[env->i]) == 1 && env->conv == 1)
		env->i += get_modif(format, env->i, env);
	return ;
}

int		ft_printf(const char *format, ...)
{
	t_env		*env;
	va_list		ap;
	int			ret;

	va_start(ap, format);
	env = init_env();
	while (format[env->i])
	{
		if (format[env->i] == '%' && env->conv == 0)
			env->conv = 1;
		else if (env->conv == 1 && check_flag(format[env->i]) != 0)
			add_flag(env, format[env->i]);
		else if (env->conv == 1 && ((ft_check_modif(format[env->i]) == 1)
		|| (format[env->i] == '.' || (ft_isdigit(format[env->i])))))
			parsing(format, env, ap);
		else if (env->conv == 1 && check_type(format[env->i], env) != 0)
			print_arg(ap, env, format[env->i]);
		else
			env->size += ft_putchar(format[env->i]);
		env->i++;
	}
	va_end(ap);
	ret = env->size;
	ft_memdel((void *)&env);
	return (ret);
}
