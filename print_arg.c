/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 11:15:38 by vkannema          #+#    #+#             */
/*   Updated: 2016/12/21 22:46:26 by vkannema         ###   ########.fr       */
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
	function_type[0] = ft_print_s;
/*	function_type[1] = ft_print_S;
	function_type[2] = ft_print_p;
	function_type[3] = ft_print_di;
	function_type[4] = ft_print_di;
	function_type[5] = ft_print_di;
	function_type[6] = ft_print_o;
	function_type[7] = ft_print_o;
	function_type[8] = ft_print_u;
	function_type[9] = ft_print_u;
	function_type[10] = ft_print_x;
	function_type[11] = ft_print_X;
*/	function_type[12] = ft_print_c;
//	function_type[13] = ft_print_C;
//	function_type[14] = ft_print_pe;
}

void	print_arg(va_list ap, t_env *env, char type)
{
	int	(*function_type[15])(va_list ap, t_env *env);

	env->type = type;
	ft_init_func(function_type);
	env->size += function_type[ft_get_type(env->type)](ap, env);
}
