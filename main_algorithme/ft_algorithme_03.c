/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithme_03.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qalpesse <qalpesse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:05:58 by qalpesse          #+#    #+#             */
/*   Updated: 2024/07/09 20:02:23 by qalpesse         ###   ########.fr       */
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
	if (*b == NULL)
		return ;
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
//gerer les - de 5
void	ft_last3(t_list **a, t_list **b)
{
	int element1;
	int element2;
	int element3;

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
	{
		//ft_last3(a, b);
		ft_algorithme_00(a, b);
	}
	else
		ft_last3(a, b);
	
}
int	*ft_fiveLastValues(t_list **a)
{
	int *tab;
	t_list *element;
	int	size;
	int	i;

	tab = malloc(5 * sizeof(int));
	element = *a;
	size = -1;
	while(element)
	{
		size++;
		element = element->next;
	}
	i = 0;
	while(i < 5)
	{
		tab[i] = size - i;
		i++;
	}
	return (tab);
}
int ft_intchr(int i, int *array, int size)
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
//----------
void ft_printtab(int *array)
{
	int i = 0;
	while(i < 5)
	{
		ft_printf("%d", array[i]);
		i++;
	}
	ft_printf("\n");
	
}
//-----
void	ft_algorithme_03(t_list **a, t_list **b)
{
	int	chunk_i;
	int	chunk;
	int	median;
	int	*array;

	array = ft_fiveLastValues(a);
	//ft_printlst(a);
	chunk = 0;
	chunk_i = ft_lstsize(*a) / ft_chunk(a);
	while (ft_lstsize(*a) > 5)
	{
		median = (chunk + (chunk + chunk_i)) / 2;
		chunk += chunk_i;
		while (ft_element_lower(a, chunk) && ft_lstsize(*a) > 5)
		{
			while (!ft_frst_lower(a, chunk) && ft_intchr((*a)->simplified, array, 5))
			{
				if (ft_find_closerindex(a, chunk, array) < ft_lstsize(*a) / 2)
					ft_instructions("ra", a, b);
				else
					ft_instructions("rra", a, b);
			}
				ft_instructions("pb", a, b);
				ft_verif_topvalue_median(a, b, median, chunk);
		}
	}
	ft_last5(a, b);
	free(array);
	ft_printlst(a);
	printf("\n");
	ft_printlst(b);
	//ft_push_b_to_a(a, b);
	
	
}
