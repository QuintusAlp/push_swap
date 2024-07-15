/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithme_03_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qalpesse <qalpesse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 13:33:18 by qalpesse          #+#    #+#             */
/*   Updated: 2024/07/15 13:43:21 by qalpesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

int	ft_check_begin_max(t_list **lst)
{
	int		value;
	t_list	*tmp;

	value = ft_atoi((*lst)->content);
	tmp = *lst;
	while (tmp != NULL)
	{
		if (ft_atoi(tmp->content) > value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_check_begin_oneofmax(t_list **lst)
{
	int		value;
	int		nbr_sup;
	t_list	*tmp;

	value = ft_atoi((*lst)->content);
	nbr_sup = 0;
	tmp = *lst;
	while (tmp != NULL)
	{
		if (ft_atoi(tmp->content) > value)
			nbr_sup += 1;
		tmp = tmp->next;
	}
	if (nbr_sup > 1)
		return (0);
	else
		return (1);
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
		if (element->simplified < chunk
			&& !ft_intchr(element->simplified, array, 5))
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
