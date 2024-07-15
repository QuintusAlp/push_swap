/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions_utils2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qalpesse <qalpesse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 11:22:15 by qalpesse          #+#    #+#             */
/*   Updated: 2024/07/15 11:49:42 by qalpesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	ft_rev_r(t_list **a, char pile)
{
	ft_reverse_rotate(a);
	ft_printf("rr%c\n", pile);
}

void	ft_rrr(t_list **a, t_list **b)
{
	ft_rev_r(a, 'a');
	ft_rev_r(b, 'b');
	ft_printf("rrr\n");
}

void	ft_instructions(char *str, t_list **a, t_list **b)
{
	if (!ft_strncmp(str, "sa", 2))
		return (ft_s(a, 'a'));
	if (!ft_strncmp(str, "sb", 2))
		return (ft_s(b, 'b'));
	if (!ft_strncmp(str, "ss", 2))
		return (ft_ss(a, b));
	if (!ft_strncmp(str, "pa", 2))
		return (ft_p(a, b, 'a'));
	if (!ft_strncmp(str, "pb", 2))
		return (ft_p(b, a, 'b'));
	if (!ft_strncmp(str, "ra", 2))
		return (ft_r(a, 'a'));
	if (!ft_strncmp(str, "rb", 2))
		return (ft_r(b, 'b'));
	if (!ft_strncmp(str, "rra", 3))
		return (ft_rev_r(a, 'a'));
	if (!ft_strncmp(str, "rrb", 3))
		return (ft_rev_r(b, 'b'));
	if (!ft_strncmp(str, "rrr", 3))
		return (ft_rrr(a, b));
	if (!ft_strncmp(str, "rr", 2))
		return (ft_rr(a, b));
}
