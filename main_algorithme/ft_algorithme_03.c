/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithme_03.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qalpesse <qalpesse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:05:58 by qalpesse          #+#    #+#             */
/*   Updated: 2024/06/22 13:35:48 by qalpesse         ###   ########.fr       */
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

void	ft_verif_topvalue_median(t_list **a, t_list **b, int median, int chunk)
{
	if ((*b)->simplified < median)
	{
		if (!ft_frst_lower(a, chunk))
			ft_instructions("rr", a, b);
		else
			ft_instructions("rb", a, b);
	}
}

int	ft_chunk(t_list **lst)
{
	if (ft_lstsize(*lst) > 200)
		return (8);
	else
		return (4);
}

void	ft_algorithme_03(t_list **a, t_list **b)
{
	int	chunk_i;
	int	chunk;
	int	median;

	chunk = 0;
	chunk_i = ft_lstsize(*a) / ft_chunk(a);
	ft_simplified(a);
	while (*a != NULL)
	{
		median = (chunk + (chunk + chunk_i)) / 2;
		chunk += chunk_i;
		while (ft_element_lower(a, chunk))
		{
			while (!ft_frst_lower(a, chunk))
			{
				if (ft_find_closerindex(a, chunk) < ft_lstsize(*a) / 2)
					ft_instructions("ra", a, b);
				else
					ft_instructions("rra", a, b);
			}
			ft_instructions("pb", a, b);
			ft_verif_topvalue_median(a, b, median, chunk);
		}
	}
	ft_push_b_to_a(a, b);
}
