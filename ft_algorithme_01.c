/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithme_01.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qalpesse <qalpesse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:53:41 by qalpesse          #+#    #+#             */
/*   Updated: 2024/06/27 15:29:27 by qalpesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int ft_check_is_trim(t_list **a)
{
	t_list *tmp = *a;

	while (tmp != NULL)
	{
		if (ft_check_begin_min(&tmp) != 1)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
t_list *ft_circular_lst(t_list **lst)
{
	t_list	*circular_lst;
	t_list	*element;

	if (!lst)
		return (NULL);
	circular_lst = NULL;
	while (*lst)
	{
		ft_lstadd_back(&circular_lst, ft_lstnew((*lst)->content));
		*lst = (*lst)->next;
	}
	element = ft_lstlast(circular_lst);
	element->next = circular_lst;

	return (circular_lst);
}

int ft_ismin_len(t_list *a, int size)
{
	t_list *tmp = a;
	int i = 0;
	int c = ft_atoi(tmp->content);
	tmp = tmp->next;
	while (i < size - 1)
	{
		if (c > ft_atoi(tmp->content))
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}
int ft_istrimcirc(t_list *lst, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (!ft_ismin_len(lst, len - i))
			return (0);
		lst = lst->next;
		i++;
	}
	return (1);
}
//is trim somewhere
int ft_istrim_somewhere(t_list **a)
{
	t_list *lst = *a;
	t_list *tmp = ft_circular_lst(&lst);
	int c = ft_atoi(tmp->content);
	int len = ft_lstsize(*a);
	if (ft_istrimcirc(tmp, len) == 1)
		return (1);
	tmp = tmp->next;
	while(ft_atoi(tmp->content) != c)
	{
		if (ft_istrimcirc(tmp, len) == 1)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
void ft_algorithme_01(t_list **a, t_list **b)
{
	int i;
	int len;
	i = 0;
	len = ft_lstsize(*a) - 1;
	(void)b;
	while (!ft_check_is_trim(a))
	{
		if((ft_atoi((*a)->content) > ft_atoi(((*a)->next)->content)) && (!ft_istrim_somewhere(a)) && i < len)
		{
			ft_s(a, 'a');
			i++;
		}
		else
			i = 0;
		if (ft_check_is_trim(a) == 1)
			break ;
		ft_r(a, 'a');
	}
}