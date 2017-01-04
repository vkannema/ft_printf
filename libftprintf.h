/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 08:24:21 by vkannema          #+#    #+#             */
/*   Updated: 2017/01/04 14:55:36 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

/*
Env
*/

typedef struct		s_flag
{
	char			value;
	int				pos;
	struct s_flag	*prev;
	struct s_flag	*next;
}					t_flag;

typedef struct		s_flag_list
{
	int				nb;
	t_flag			*first;
	t_flag			*last;
}					t_flag_list;

typedef	struct		s_env
{
	int				i;
	int				size;
	int				flag;
	int				type;
	char			conv;
	int				precision;
	int				width;
	t_flag_list		*flags;
}					t_env;



/*
Libft functions
*/
int					ft_isdigit(int c);
int					ft_strlen(char *str);
int					ft_putchar(char c);
int					ft_putstr(const char *s);
void				ft_putoctal(unsigned int nb);
int					ft_size_nbr(int n);
int					ft_atoi(const char *str);
void				ft_putnbr(int n);


int					ft_printf(const char *format, ...);
int					check_type(char c, t_env *env);
void				print_arg(va_list ap, t_env *env, char type);
//int					get_width(const char *format, int	i, t_env *env);
int					get_precision(const char *format, int i, t_env *env);
int					get_precision_star(t_env *env, va_list ap);
/*
Print types
*/

int					ft_print_c(va_list ap, t_env *env);
int					ft_print_s(va_list ap, t_env *env);
int					ft_print_o(va_list ap, t_env *env);
int					ft_print_x(va_list ap, t_env *env);
int					ft_print_X(va_list ap, t_env *env);
int					ft_print_di(va_list ap, t_env *env);
int					ft_print_p(va_list ap, t_env *env);
int					ft_print_xcap(va_list ap, t_env *env);
int					ft_print_pe(va_list ap, t_env *env);

/*
Precision
*/

int					print_precision_di(int nb, t_env *env);
int					print_precision_s(char *str, t_env *env);

/*
FLAGS
*/

void				add_flag(t_env *env, char value, int pos);
int					check_flag(char c);
int					zero_flag(t_env *env);
int					space_flag(t_env *env);
int					pos_flag(t_env *env);
int					neg_flag(t_env *env);
int					hashtag_flag(t_env *env);

#endif
