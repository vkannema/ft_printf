/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 20:34:30 by vkannema          #+#    #+#             */
/*   Updated: 2016/12/21 21:28:35 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_s(va_list ap, t_env *env)
{
	int	ret;
	char *str;

	str = va_arg(ap, char *);
	ret = 0;
	if(!(str))
	{
		ret += ft_putstr("null");
		return (ret);
	}
	ret = ft_strlen(str);
	env->size += ret;
	return (ret);
}
