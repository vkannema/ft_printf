/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 15:31:30 by vkannema          #+#    #+#             */
/*   Updated: 2016/12/14 12:44:31 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <libft.h>
# include <stdarg.h>

void	ft_printf_me(char *str);

typedef struct	s_type
{
	int		d;
	char	*s;
	long	ld;
	char	c;

}				t_ype;

#endif
