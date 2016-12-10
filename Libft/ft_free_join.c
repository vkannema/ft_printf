/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_join.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 10:43:10 by vkannema          #+#    #+#             */
/*   Updated: 2016/12/10 10:52:01 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_free_join(char *dest, char *buff, int i)
{
	char	*tmp;

	if (!(tmp = ft_strjoin(dest, buff)))
		return (NULL);
	if (i == 0)
		free(dest);
	if (i == 1)
		free(buff);
	if (i == 2)
	{
		free(dest);
		free(buff);
	}
	dest = NULL;
	return (tmp);
}
