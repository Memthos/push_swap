/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_02.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:02:31 by mperrine          #+#    #+#             */
/*   Updated: 2025/11/26 16:30:27 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	error_exit(t_stack **stack_a, t_stack **stack_b)
{
	clear_stack(stack_a);
	clear_stack(stack_b);
	write(2, "Error\n", 6);
	exit(1);
}

void	clear_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

int	not_in_stack(t_stack **stack, const int nb)
{
	t_stack	*current;

	current = *stack;
	while (current)
	{
		if (current->nb == nb)
			return (1);
		current = current->next;
	}
	return (0);
}
