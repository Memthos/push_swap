/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:10:36 by mperrine          #+#    #+#             */
/*   Updated: 2026/03/09 12:26:31 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_max_index(t_stack *stack)
{
	int		max_index;

	max_index = 0;
	while (stack)
	{
		if (stack->idx > max_index)
			max_index = stack->idx;
		stack = stack->next;
	}
	return (max_index);
}

static int	get_index_pos(t_stack *stack, int idx)
{
	int		pos;

	pos = 0;
	while (stack)
	{
		if (stack->idx == idx)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}

void	reintegration_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	max_index;
	int	max_index_pos;

	while (*stack_b)
	{
		max_index = get_max_index(*stack_b);
		max_index_pos = get_index_pos(*stack_b, max_index);
		if (max_index_pos <= get_stack_size(*stack_b) / 2)
		{
			while ((*stack_b)->idx != max_index)
				rotate(stack_b, 'b');
		}
		else
		{
			while ((*stack_b)->idx != max_index)
				reverse_rotate(stack_b, 'b');
		}
		push(stack_b, stack_a, 'a');
	}
}

void	k_distribution_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size_t;
	int	delta;
	int	threshold;

	size_t = get_stack_size(*stack_a);
	delta = size_t / 20 + 7;
	threshold = 0;
	while (*stack_a)
	{
		if ((*stack_a)->idx <= threshold + delta)
		{
			push(stack_a, stack_b, 'b');
			if ((*stack_b)->idx <= threshold)
				rotate(stack_b, 'b');
			threshold++;
		}
		else
			rotate(stack_a, 'a');
	}
}

void	small_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (get_stack_size(*stack_a) < 3)
	{
		swap(stack_a, 'a');
		return ;
	}
	while (!stack_sorted(*stack_a) || get_stack_size(*stack_b) > 0)
	{
		if ((!stack_sorted(*stack_a) && get_stack_size(*stack_a) < 3)
			|| ((*stack_a)->nb > (*stack_a)->next->nb
				&& (*stack_a)->nb < (*stack_a)->next->next->nb))
			swap(stack_a, 'a');
		else if ((*stack_a)->nb > (*stack_a)->next->nb
			&& (*stack_a)->nb > (*stack_a)->next->next->nb)
			rotate(stack_a, 'a');
		else if (get_last_elem(*stack_a)->nb < (*stack_a)->nb
			&& get_last_elem(*stack_a)->nb < (*stack_a)->next->nb)
			reverse_rotate(stack_a, 'a');
		else if (!stack_sorted(*stack_a) && get_stack_size(*stack_a) > 2
			&& (*stack_a)->nb < (*stack_a)->next->nb
			&& (*stack_a)->nb < get_last_elem(*stack_a)->nb)
			push(stack_a, stack_b, 'b');
		else
			push(stack_b, stack_a, 'a');
	}
}
