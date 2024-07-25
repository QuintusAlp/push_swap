/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithme_03.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qalpesse <qalpesse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:05:58 by qalpesse          #+#    #+#             */
/*   Updated: 2024/07/25 18:27:06 by qalpesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	ft_last3(t_list **a, t_list **b)
{
	int	element1;
	int	element2;
	int	element3;

	element1 = (*a)->simplified;
	element2 = ((*a)->next)->simplified;
	element3 = (((*a)->next)->next)->simplified;
	if (ft_istrim(a))
		return ;
	if (element1 > element2 && element1 < element3)
		ft_instructions("sa", a, b);
	if (element1 > element2 && element1 > element3 && element2 > element3)
	{
		ft_instructions("sa", a, b);
		ft_instructions("rra", a, b);
	}
	if (element1 > element2 && element1 > element3 && element2 < element3)
		ft_instructions("ra", a, b);
	if (element1 < element2 && element1 < element3)
	{
		ft_instructions("sa", a, b);
		ft_instructions("ra", a, b);
	}
	if (element1 < element2 && element1 > element3)
		ft_instructions("rra", a, b);
}

void	ft_last5(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) > 3)
		ft_algorithme_00(a, b);
	else if (ft_lstsize(*a) == 3)
		ft_last3(a, b);
	else
	{
		if ((*a)->simplified > ((*a)->next)->simplified)
			ft_instructions("sa", a, b);
	}
}

int	*ft_five_last_values(t_list **a)
{
	int		*tab;
	t_list	*element;
	int		size;
	int		i;

	tab = malloc(5 * sizeof(int));
	element = *a;
	size = -1;
	while (element)
	{
		size++;
		element = element->next;
	}
	i = 0;
	while (i < 5)
	{
		tab[i] = size - i;
		i++;
	}
	return (tab);
}

int	ft_intchr(int i, int *array, int size)
{
	int	k;

	k = 0;
	while (k < size)
	{
		if (array[k] == i)
			return (1);
		k++;
	}
	return (0);
}

void	ft_algorithme_03(t_list **a, t_list **b)
{
	int	*array;

	array = ft_five_last_values(a);
	ft_push_a_to_b(a, b, array);
	ft_last5(a, b);
	ft_push_b_to_a(a, b, 0, 0);
	free(array);
}
