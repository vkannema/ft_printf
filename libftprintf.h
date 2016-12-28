/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 08:24:21 by vkannema          #+#    #+#             */
/*   Updated: 2016/12/28 12:45:15 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

typedef	struct	s_env
{
	int			i;
	int			size;
	int			flag;
	char		type;
}				t_env;

int				ft_printf(const char *format, ...);
int				ft_putchar(char c);
void			ft_putoctal(unsigned int nb);
int				ft_putstr(const char *s);
int				check_type(char c, t_env *env);
void			print_arg(va_list ap, t_env *env, char type);
int				ft_size_nbr(int n);
int				ft_print_c(va_list ap, t_env *env);
int				ft_print_s(va_list ap, t_env *env);
int				ft_print_o(va_list ap, t_env *env);
int				ft_strlen(char *str);
int				ft_print_x(va_list ap, t_env *env);
int				ft_print_X(va_list ap, t_env *env);
int				ft_print_di(va_list ap, t_env *env);
int				ft_print_p(va_list ap, t_env *env);
int				ft_print_xcap(va_list ap, t_env *env);
int				ft_print_pe(va_list ap, t_env *env);
#endif
