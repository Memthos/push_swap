/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_operations_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 12:55:31 by mperrine          #+#    #+#             */
/*   Updated: 2026/03/09 12:52:49 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	swap(t_stack **stack)
{
	int	tmp_nb;
	int	tmp_idx;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp_nb = (*stack)->nb;
	tmp_idx = (*stack)->idx;
	(*stack)->nb = (*stack)->next->nb;
	(*stack)->idx = (*stack)->next->idx;
	(*stack)->next->nb = tmp_nb;
	(*stack)->next->idx = tmp_idx;
}

void	push(t_stack **push, t_stack **pull)
{
	t_stack	*tmp;

	if (!push || !*push)
		return ;
	tmp = *push;
	*push = (*push)->next;
	if (!*pull)
		tmp->next = NULL;
	else
		tmp->next = *pull;
	*pull = tmp;
}

void	rotate(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	get_last_elem(*stack)->next = tmp;
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = get_last_elem(*stack);
	get_penultimate_elem(*stack)->next = NULL;
	tmp->next = *stack;
	*stack = tmp;
}
