/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 08:24:21 by vkannema          #+#    #+#             */
/*   Updated: 2016/12/16 11:30:44 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include <stdarg.h>

typedef	struct	s_env
{
	int			i;
	int			size;
	int			flag;
	char		type;
}				t_env;

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
void	ft_putoctal(unsigned int nb);
int		ft_putstr(const char *s);
int		check_type(char c);
void	change_arg(va_list ap, t_env *env, char type);
#endif
