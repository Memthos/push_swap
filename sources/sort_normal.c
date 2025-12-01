/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:10:36 by mperrine          #+#    #+#             */
/*   Updated: 2025/11/26 17:01:54 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	reintegration_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	max_index;
	int	max_index_pos;

	while (*stack_b)
	{
		max_index = get_max_index(stack_b);
		max_index_pos = get_index_pos(stack_b, max_index);
		if (max_index_pos <= get_stack_size(stack_b) / 2)
		{
			while ((*stack_b)->idx != max_index)
				rotate(stack_b, "b");
		}
		else
		{
			while ((*stack_b)->idx != max_index)
				reverse_rotate(stack_b, "b");
		}
		push(stack_b, stack_a, "a");
	}
}

void	k_distribution_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size_t;
	int	delta;
	int	threshold;

	size_t = get_stack_size(stack_a);
	delta = size_t / 20 + 7;
	threshold = 0;
	while (*stack_a)
	{
		if ((*stack_a)->idx <= threshold + delta)
		{
			push(stack_a, stack_b, "b");
			if ((*stack_b)->idx <= threshold)
				rotate(stack_b, "b");
			threshold++;
		}
		else
			rotate(stack_a, "a");
	}
}
