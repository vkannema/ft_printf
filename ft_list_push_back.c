/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 15:49:37 by vkannema          #+#    #+#             */
/*   Updated: 2016/08/25 15:37:26 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *current;

	current = *begin_list;
	if (current == NULL)
		*begin_list = ft_create_elem(data);
	else
	{
		while (current->next)
			current = current->next;
		current->next = ft_create_elem(data);
	}
}
