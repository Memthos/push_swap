/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 12:55:31 by mperrine          #+#    #+#             */
/*   Updated: 2026/03/09 12:01:42 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack **stack, const char stack_name)
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
	write(1, "s", 1);
	write(1, &stack_name, 1);
	write(1, "\n", 1);
}

void	push(t_stack **push, t_stack **pull, const char stack_name)
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
	write(1, "p", 1);
	write(1, &stack_name, 1);
	write(1, "\n", 1);
}

void	rotate(t_stack **stack, const char stack_name)
{
	t_stack	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	get_last_elem(*stack)->next = tmp;
	write(1, "r", 1);
	write(1, &stack_name, 1);
	write(1, "\n", 1);
}

void	reverse_rotate(t_stack **stack, const char stack_name)
{
	t_stack	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = get_last_elem(*stack);
	get_penultimate_elem(*stack)->next = NULL;
	tmp->next = *stack;
	*stack = tmp;
	write(1, "rr", 2);
	write(1, &stack_name, 1);
	write(1, "\n", 1);
}
