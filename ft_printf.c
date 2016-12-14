/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 15:44:55 by vkannema          #+#    #+#             */
/*   Updated: 2016/12/14 12:49:38 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int			i;
	va_list		ap;
	t_ype		*type;
	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'd')
			{
				type->d = va_arg(ap, int);
				ft_putnbr(type->d);
			}
			if (format[i + 1] == 's')
			{
				type->s = va_arg(ap, char *);
				ft_putstr(type->s);
			}
			if (format[i + 1] == 'c')
			{
				type->c = va_arg(ap, char);
				ft_putchar(type->c);
			}
			i+=2;
		}
		ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (i);
}
