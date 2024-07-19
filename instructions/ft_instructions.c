/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qalpesse <qalpesse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:11:08 by qalpesse          #+#    #+#             */
/*   Updated: 2024/06/22 10:56:56 by qalpesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	ft_swap(t_list **lst)
{
	int				ssub;
	char			*scontent;
	t_list		*next_element;

	if (!lst)
		return ;
	ssub = (*lst)->simplified;
	scontent = (*lst)->content;
	next_element = (*lst)->next;
	(*lst)->content = next_element->content;
	(*lst)->simplified = next_element->simplified;
	next_element->simplified = ssub;
	next_element->content = scontent;
}

void	ft_push(t_list **a, t_list **b)
{
	t_list	*sub;

	if (!b)
		return ;
	sub = *b;
	*b = (*b)->next;
	ft_lstadd_front(a, sub);
}

t_list	*ft_last_element(t_list *lst)
{
	t_list	*last_e;

	if (!lst)
		return (NULL);
	last_e = lst;
	while (last_e)
	{
		if ((last_e->next) == NULL)
			return (last_e);
		else
			last_e = last_e->next;
	}
	return (last_e);
}

void	ft_rotate(t_list **lst)
{
	t_list	*last_e;
	t_list	*sub;

	if (*lst == NULL || !lst)
		return ;
	last_e = ft_last_element(*lst);
	sub = *lst;
	last_e->next = sub;
	*lst = (*lst)->next;
	sub->next = NULL;
}

void	ft_reverse_rotate(t_list **lst)
{
	t_list	*last_e;
	t_list	*sub;

	if (!lst)
		return ;
	last_e = *lst;
	while (last_e)
	{
		if ((last_e->next)->next == NULL)
		{
			sub = last_e;
			last_e = sub->next;
			sub->next = NULL;
			break ;
		}
		else
			last_e = last_e->next;
	}
	sub = *lst;
	last_e->next = sub;
	*lst = last_e;
}
