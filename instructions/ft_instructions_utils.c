/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qalpesse <qalpesse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:35:08 by qalpesse          #+#    #+#             */
/*   Updated: 2024/07/15 11:49:19 by qalpesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	ft_s(t_list **a, char pile)
{
	ft_swap(a);
	ft_printf("s%c\n", pile);
}

void	ft_ss(t_list **a, t_list **b)
{
	ft_swap(a);
	ft_swap(b);
	ft_printf("ss\n");
}

void	ft_p(t_list **a, t_list **b, char pile)
{
	ft_push(a, b);
	ft_printf("p%c\n", pile);
}

void	ft_r(t_list **a, char pile)
{
	ft_rotate(a);
	ft_printf("r%c\n", pile);
}

void	ft_rr(t_list **a, t_list **b)
{
	ft_rotate(a);
	ft_rotate(b);
	ft_printf("rr\n");
}
