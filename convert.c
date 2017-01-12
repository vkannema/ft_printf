/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 10:14:10 by vkannema          #+#    #+#             */
/*   Updated: 2017/01/12 09:54:58 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

intmax_t	convert(va_list ap, t_env *env)
{
	intmax_t	nb;

	nb = va_arg(ap, intmax_t);
	if (env->modif == 'h' && env->dual == 1)
		nb = (char)nb;
	else if (env->modif == 'l' && env->dual == 1)
		nb = (long long)nb;
	else if (env->modif == 'h' && env->dual == 0)
		nb = (short)nb;
	else if (env->modif == 'l' && env->dual == 0)
		nb = (long)nb;
	else if (env->modif == 'j')
		nb = (intmax_t)nb;
	else if (env->modif == 'z')
		nb = (size_t)nb;
	else
		nb = (int)nb;
	return (nb);
}

uintmax_t	convert_u(va_list ap, t_env *env)
{
	uintmax_t	nb;

	nb = va_arg(ap, intmax_t);
	if (env->modif == 'h' && env->dual == 1)
		nb = (unsigned char)nb;
	else if (env->modif == 'l' && env->dual == 1)
		nb = (unsigned long long)nb;
	else if (env->modif == 'h' && env->dual == 0)
		nb = (unsigned short)nb;
	else if (env->modif == 'l' && env->dual == 0)
		nb = (unsigned long)nb;
	else if (env->modif == 'j')
		nb = (uintmax_t)nb;
	else if (env->modif == 'z')
		nb = (unsigned long)nb;
	else
		nb = (unsigned int)nb;
	return (nb);
}
