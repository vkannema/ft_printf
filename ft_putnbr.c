/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 10:43:43 by vkannema          #+#    #+#             */
/*   Updated: 2017/01/12 18:32:52 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_putnbr(long long n)
{
	if (n < 0)
	{
		n = -n;
		ft_putchar('-');
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	if (n <= 9 && n >= 0)
		ft_putchar(n + '0');
}

void		ft_putabs(long long n)
{
	if (n < 0)
		n = -n;
	ft_putnbr(n);
}

void	ft_puthexa(unsigned long long nb, const char *base)
{
	size_t beg;
	size_t end;

	end = nb % 16;
	beg = (nb - end) / 16;
	if (beg)
		ft_puthexa(beg, base);
	ft_putchar(base[end]);
}

void	ft_putunsigned(unsigned long long n)
{
	if (n > 9)
	{
		ft_putunsigned(n / 10);
		ft_putunsigned(n % 10);
	}
	if (n <= 9)
		ft_putchar(n + '0');
}
