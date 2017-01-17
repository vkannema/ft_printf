/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c_cap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 15:21:11 by vkannema          #+#    #+#             */
/*   Updated: 2017/01/16 19:55:22 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_fill_str(char *str, unsigned int nb)
{
	int	i;
	int	end;

	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		if (str[i] == 'x')
		{
			end = nb % 2;
			nb = (nb - end) / 2;
			str[i] = end + '0';
			i--;
		}
		else
			i--;
	}
	return (str);
}

int		ft_size_bin(unsigned int nb)
{
	size_t	beg;
	size_t	end;
	int		i;

	i = 0;
	end = nb % 2;
	beg = (nb - end) / 2;
	i++;
	while (beg)
	{
		end = beg % 2;
		beg = (beg - end) / 2;
		i++;
	}
	return (i);
}

int		convert_to_int(char *str, int tab)
{
	int	i;
	int	j;
	int	nb;
	int	ind;
	int	k;
	int *res;

	ind = 0;
	nb = 0;
	j = 1;
	k = 1;
	i = ft_strlen(str) - 1;
	res = (int *)malloc(sizeof(int) * tab);
	res[0] = 0;
	res[1] = 0;
	res[2] = 0;
	res[3] = 0;
	while (tab >= 0)
	{
		while (k <= 8 && i >= 0)
		{
			if (str[i] == '1')
				nb = nb + j;
			j *= 2;
			i--;
			k++;
		}
		res[tab] = nb;
		k = 1;
		nb = 0;
		tab--;
		j = 1;
	}
	write(1, &res[0], 1);
	write(1, &res[1], 1);
	write(1, &res[2], 1);
	write(1, &res[3], 1);
	return (nb);
}

int		ft_print_c_cap(va_list ap, t_env *env)
{
	unsigned int	nb;
	int				size;
	char			**str;
	char			*ret;

	str = (char **)malloc(sizeof(char *) * 4);
	nb = va_arg(ap, unsigned int);
	size = ft_size_bin(nb);
	if (size <= 7)
	{
		write(1, &nb, 1);
		env->size += 1;
		str[0] = "0xxxxxxx";
		return (0);
	}
	else if (size <= 11)
	{
		str[1] = ft_strdup("110xxxxx10xxxxxx");
		ret = ft_fill_str(str[1], nb);
		convert_to_int(ret, 1);
	}
	else if (size > 11 && size <= 16)
	{
		str[2] = ft_strdup("110xxxxx10xxxxxx10xxxxxx");
		ret = ft_fill_str(str[2], nb);
	}
	else
	{
		str[3] = "110xxxxx10xxxxxx10xxxxxx10xxxxxx";
		ret = ft_fill_str(str[3], nb);
	}
	return (0);
}
