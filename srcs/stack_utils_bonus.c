/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:28:59 by mperrine          #+#    #+#             */
/*   Updated: 2026/03/09 12:34:44 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

int	stack_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->idx > stack->next->idx)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	get_stack_size(t_stack *stack)
{
	int		size;

	size = 0;
	if (!stack)
		return (size);
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

t_stack	*get_last_elem(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_stack	*get_penultimate_elem(t_stack *stack)
{
	if (!stack || !stack->next)
		return (NULL);
	while (stack->next->next)
		stack = stack->next;
	return (stack);
}
