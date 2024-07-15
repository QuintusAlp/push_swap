/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithme_00.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qalpesse <qalpesse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 13:21:01 by qalpesse          #+#    #+#             */
/*   Updated: 2024/07/15 14:13:33 by qalpesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

int	ft_check_begin_min(t_list **lst)
{
	int		value;
	int		subvalue_elements;
	t_list	*tmp;

	value = ft_atoi((*lst)->content);
	subvalue_elements = 0;
	tmp = *lst;
	while (tmp != NULL)
	{
		if (ft_atoi(tmp->content) < value)
			subvalue_elements += 1;
		tmp = tmp->next;
	}
	if (subvalue_elements > 0)
		return (0);
	else
		return (1);
}

t_list	*ft_findmin(t_list **lst)
{
	t_list	*min;
	t_list	*element;

	if (!lst)
		return (NULL);
	element = *lst;
	min = *lst;
	while (element)
	{
		if (element->simplified < min->simplified)
			min = element;
		element = element->next;
	}
	return (min);
}

int	ft_elementindex(t_list *element, t_list **lst)
{
	int		i;
	t_list	*e;

	e = *lst;
	i = 0;
	while (e && ft_atoi(e->content) != ft_atoi(element->content))
	{
		i++;
		e = e->next;
	}
	return (i);
}

void	ft_algorithme_00(t_list **a, t_list **b)
{
	int	i;
	int	minindex;
	int	k;

	k = 0;
	while (*a != NULL && k < 2)
	{
		minindex = ft_elementindex(ft_findmin(a), a);
		i = ft_check_begin_min(a);
		while (i == 0)
		{
			if (minindex < ft_lstsize(*a) / 2)
				ft_instructions("ra", a, b);
			else
				ft_instructions("rra", a, b);
			i = ft_check_begin_min(a);
		}
		ft_instructions("pb", a, b);
		k++;
	}
	ft_last3(a, b);
	k = -1;
	while (k++, *b != NULL && k < 2)
		ft_instructions("pa", a, b);
}
