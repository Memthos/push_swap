/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:28:59 by mperrine          #+#    #+#             */
/*   Updated: 2025/11/26 17:00:59 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	stack_sorted(t_stack **stack)
{
	t_stack	*current;

	current = *stack;
	while (current->next)
	{
		if (current->idx > current->next->idx)
			return (0);
		current = current->next;
	}
	return (1);
}

int	get_stack_size(t_stack **stack)
{
	int		size;
	t_stack	*current;

	size = 0;
	if (!stack || !*stack)
		return (size);
	current = *stack;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}

t_stack	*get_last_elem(t_stack **stack)
{
	t_stack	*current;

	if (!stack || !*stack)
		return (NULL);
	current = *stack;
	while (current->next)
		current = current->next;
	return (current);
}

int	get_max_index(t_stack **stack)
{
	t_stack	*current;
	int		max_index;

	current = *stack;
	max_index = 0;
	while (current)
	{
		if (current->idx > max_index)
			max_index = current->idx;
		current = current->next;
	}
	return (max_index);
}

int	get_index_pos(t_stack **stack, int idx)
{
	t_stack	*current;
	int		pos;

	current = *stack;
	pos = 0;
	while (current)
	{
		if (current->idx == idx)
			return (pos);
		current = current->next;
		pos++;
	}
	return (-1);
}
