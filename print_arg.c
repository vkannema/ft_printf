/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 11:15:38 by vkannema          #+#    #+#             */
/*   Updated: 2016/12/16 11:29:33 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		ft_get_type(char c)
{
	const char	*types;
	int			i;

	i = 0;
	types = "sSpdDioOuUxXcC";
	while (types[i])
	{
		if (c == types[i])
			return (i);
		i++;
	}
	return (-1);
}

void	ft_init_func(int (**function_type)(va_list ap, t_env *env))
{
	function_type[0] = ft_printf_s;
	function_type[1] = ft_printf_c;
	function_type[2] = ft_printf_d;
	function_type[3] = ft_printf_o;
	function_type[4] = ft_printf_x;
	function_type[5] = ft_printf_p;
	function_type[6] = ft_printf_i;
}

void	change_arg(va_list ap, t_env *env, char type)
{
	int	(*function_type[7])(va_list ap, t_env *env);

	env->type = type;
	ft_init_func(function_type);
	env->size += funct_array[ft_get_type(env->type)](ap, env);
}
