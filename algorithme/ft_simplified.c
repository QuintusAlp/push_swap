/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simplified.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qalpesse <qalpesse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:31:27 by qalpesse          #+#    #+#             */
/*   Updated: 2024/07/15 15:44:35 by qalpesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

int	*ft_list_tab(t_list *lst)
{
	int	*numbers;
	int	lstsize;
	int	i;

	lstsize = ft_lstsize(lst);
	numbers = malloc(lstsize * sizeof(int));
	i = 0;
	while (lst)
	{
		numbers[i] = ft_atoi(lst->content);
		lst = lst->next;
		i++;
	}
	return (numbers);
}

void	ft_trimtab(int *numbers, int tabsize)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < tabsize)
	{
		j = 0;
		while (i + j < tabsize)
		{
			if (numbers[i + j] < numbers[i])
			{
				k = numbers[i + j];
				numbers[i + j] = numbers[i];
				numbers[i] = k;
			}
			j++;
		}
		i++;
	}
}

int	ft_findelementinarray(void *element, int *numbers)
{
	int	i;

	i = 0;
	while (1)
	{
		if (ft_atoi(element) == numbers[i])
			break ;
		i++;
	}
	return (i);
}

void	ft_lst_spfelement(t_list **a, int *numbers)
{
	t_list	*element;

	element = *a;
	while (element)
	{
		element->simplified = ft_findelementinarray(element->content, numbers);
		element = element->next;
	}
}

void	ft_simplified(t_list **a)
{
	int	*numbers;

	numbers = ft_list_tab(*a);
	ft_trimtab(numbers, ft_lstsize(*a));
	ft_lst_spfelement(a, numbers);
	free(numbers);
}
