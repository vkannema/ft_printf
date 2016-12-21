/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 08:24:21 by vkannema          #+#    #+#             */
/*   Updated: 2016/12/21 21:42:41 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

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
void	print_arg(va_list ap, t_env *env, char type);
int		ft_print_c(va_list ap, t_env *env);
int		ft_print_s(va_list ap, t_env *env);
int		ft_strlen(char *str);
#endif
