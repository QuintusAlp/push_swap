/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithme_03_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qalpesse <qalpesse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 13:33:18 by qalpesse          #+#    #+#             */
/*   Updated: 2024/07/09 19:40:06 by qalpesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

int	ft_element_lower(t_list **list, int max)
{
	t_list	*element;

	element = *list;
	while (element)
	{
		if (element->simplified < max)
			return (1);
		element = element->next;
	}
	return (0);
}

int	ft_frst_lower(t_list **lst, int chunk)
{
	if (*lst == NULL)
		return (0);
	if ((*lst)->simplified < chunk)
		return (1);
	else
		return (0);
}

int	ft_find_closerindex(t_list **lst, int chunk, int *array)
{
	int		index;
	t_list	*element;
	int		cost;
	int		new_cost;

	index = -1;
	cost = 100000000;
	element = *lst;
	while (element)
	{
		if (element->simplified < chunk && !ft_intchr(element->simplified, array, 5))
		{
			new_cost = ft_elementcost(element, lst);
			if (new_cost < cost)
			{
				cost = new_cost;
				index = ft_elementindex(element, lst);
			}
		}
		element = element->next;
	}
	return (index);
}
