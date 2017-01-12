/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 08:24:21 by vkannema          #+#    #+#             */
/*   Updated: 2017/01/12 12:35:04 by vkannema         ###   ########.fr       */
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
	struct s_flag	*next;
}					t_flag;

typedef struct		s_flag_list
{
	int				nb;
	t_flag			*first;
}					t_flag_list;

typedef	struct		s_env
{
	int				i;
	int				size;
	int				flag;
	int				type;
	int				conv;
	int				precision;
	int				width;
	int				zero_width;
	char			modif;
	int				dual;
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
int					ft_size_nbr(long long n);
int					ft_atoi(const char *str);
void				ft_putnbr(long long n);
void				ft_puthexa(unsigned long long nb, const char *base);
void				ft_putunsigned(unsigned long long n);
int					ft_size_oct(unsigned long long nb);
void				ft_memdel(void **ap);
void				ft_putabs(long long n);

int					ft_printf(const char *format, ...);
int					check_type(char c, t_env *env);
void				print_arg(va_list ap, t_env *env, char type);
int					get_width(const char *format, int i, t_env *env);
int					get_precision(const char *format, int i, t_env *env);
int					get_precision_star(t_env *env, va_list ap);
int					ft_size_abs(long long n);
int					ft_size_hexa(unsigned long long nb);
int					ft_size_unsigned(unsigned long long n);
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
int					ft_print_u(va_list ap, t_env *env);

/*
Precision
*/

int					print_precision_di(long long nb, t_env *env);
int					print_precision_s(char *str, t_env *env);
int					print_precision_x(unsigned long long nb, t_env *env, const char *base);
int					print_precision_o(unsigned int nb, t_env *env);
int					print_width_str(char *str, t_env *env);
int					print_preciwidth_di(long long nb, t_env *env);
int					print_precision_u(unsigned long long nb, t_env *env);
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

/*
MODIF
*/
int					ft_check_modif(char c);
int					get_modif(const char *format, int i, t_env *env);
intmax_t			convert(va_list ap, t_env *env);
uintmax_t			convert_u(va_list ap, t_env *env);

#endif
