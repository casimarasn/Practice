/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:29:02 by msedeno-          #+#    #+#             */
/*   Updated: 2025/09/09 12:38:29 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa, sb, pa, pb;

void	sa(t_stack **a, int print)
{
	t_stack	*first;
	t_stack	*second;
	int		tmp_num;
	int		tmp_pos;

	if (!a || !*a || (*a)->next == *a)
		return ;
	first = *a;
	second = (*a)->next;
	tmp_num = first->num;
	tmp_pos = first->pos;
	first->num = second->num;
	first->pos = second ->pos;
	second->num = tmp_num;
	second->pos = tmp_pos;
	update_pos(*a);
	if (print == 1)
		ft_putstr_fd ("sa\n", 1);
}

void	sb(t_stack **b, int print)
{
	t_stack	*first;
	t_stack	*second;
	int		tmp_num;
	int		tmp_pos;

	if (!b || !*b || (*b)->next == (*b))
		return ;
	first = *b;
	second = (*b)->next;
	tmp_num = first->num;
	tmp_pos = first->pos;
	first->num = second->num;
	first->pos = second->pos;
	second->num = tmp_num;
	second->pos = tmp_pos;
	update_pos(*b);
	if (print == 1)
		ft_putstr_fd("sb\n", 1);
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp_node;

	if (!a || !*a)
		return ;
	tmp_node = *a;
	if (tmp_node->next == tmp_node)
		*a = NULL;
	else
	{
		tmp_node->prev->next = tmp_node->next;
		tmp_node->next->prev = tmp_node->prev;
		*a = tmp_node ->next;
	}
	tmp_node->next = NULL;
	tmp_node->prev = NULL;
	stack_add_front(b, tmp_node);
	update_pos(*a);
	update_pos(*b);
	ft_putstr_fd("pb\n", 1);
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp_node;

	if (!b || !*b)
		return ;
	tmp_node = *b;
	if (tmp_node->next == tmp_node)
		*b = NULL;
	else
	{
		tmp_node->prev->next = tmp_node->next;
		tmp_node->next->prev = tmp_node->prev;
		*b = tmp_node->next;
	}
	tmp_node->next = NULL;
	tmp_node->prev = NULL;
	stack_add_front(a, tmp_node);
	update_pos(*a);
	update_pos(*b);
	ft_putstr_fd ("pa\n", 1);
}
