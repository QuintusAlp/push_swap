/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qalpesse <qalpesse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:55:21 by qalpesse          #+#    #+#             */
/*   Updated: 2024/07/09 19:31:29 by qalpesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H
# include "./libft/libft.h"
# include <stdlib.h>//pour exit

typedef struct s_data
{
	int	lstsize;
	int	closerindex;
	int	cost;
	int	element_cost;
}	t_data;
//--instructions--
void	ft_swap(t_list **a);
void	ft_push(t_list **a, t_list **b);
void	ft_rotate(t_list **a);
void	ft_reverse_rotate(t_list **lst);
t_list	*ft_last_element(t_list *lst);
//--instructions utils--
void	ft_s(t_list **a, char pile);
void	ft_ss(t_list **a, t_list **b);
void	ft_p(t_list **a, t_list **b, char pile);
void	ft_r(t_list **a, char pile);
void	ft_rr(t_list **a, t_list **b);
void	ft_rev_r(t_list **a, char pile);
void	ft_instructions(char *str, t_list **a, t_list **b);
//--checkerrors
int		ft_checkerros(char *element, t_list **lst);
//--printf lst
void	ft_printlst(t_list **a);
//--algorithme--
//--00--
t_list	*ft_findmin(t_list **lst);
int		ft_check_begin_min(t_list **lst);
int		ft_elementindex(t_list *element, t_list **lst);
void	ft_algorithme_00(t_list **a, t_list **b);
//--for the tree last
void	ft_last3(t_list **a, t_list **b);
//--verify if A is trim 
int ft_istrim(t_list **a);
//int chr
int ft_intchr(int i, int *array, int size);
//--01--
void	ft_algorithme_01(t_list **a, t_list **b);
//--simplified the numbers--
void	ft_simplified(t_list **a);
//--03 - QuickSort--
void	ft_algorithme_03(t_list **a, t_list **b);
void	ft_push_b_to_a(t_list **a, t_list **b);
int		ft_elementcost(t_list *element, t_list **lst);
//--utils--
int		ft_element_lower(t_list **list, int max);
int		ft_frst_lower(t_list **lst, int chunk);
int		ft_find_closerindex(t_list **lst, int chunk, int *array);
#endif