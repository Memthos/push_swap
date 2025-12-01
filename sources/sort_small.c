/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 13:12:35 by mperrine          #+#    #+#             */
/*   Updated: 2025/11/26 16:27:17 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	small_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (get_stack_size(stack_a) < 3)
	{
		swap(stack_a, "a");
		return ;
	}
	while (!stack_sorted(stack_a) || get_stack_size(stack_b) > 0)
	{
		if ((!stack_sorted(stack_a) && get_stack_size(stack_a) < 3)
			|| ((*stack_a)->nb > (*stack_a)->next->nb
				&& (*stack_a)->nb < (*stack_a)->next->next->nb))
			swap(stack_a, "a");
		else if ((*stack_a)->nb > (*stack_a)->next->nb
			&& (*stack_a)->nb > (*stack_a)->next->next->nb)
			rotate(stack_a, "a");
		else if (get_last_elem(stack_a)->nb < (*stack_a)->nb
			&& get_last_elem(stack_a)->nb < (*stack_a)->next->nb)
			reverse_rotate(stack_a, "a");
		else if (!stack_sorted(stack_a) && get_stack_size(stack_a) > 2
			&& (*stack_a)->nb < (*stack_a)->next->nb
			&& (*stack_a)->nb < get_last_elem(stack_a)->nb)
			push(stack_a, stack_b, "b");
		else
			push(stack_b, stack_a, "a");
	}
}
