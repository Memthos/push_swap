/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_read_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 12:38:35 by mperrine          #+#    #+#             */
/*   Updated: 2026/03/09 13:22:18 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

static void	swap_operation(char *input, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(input, "sa\n") == 0)
		swap(stack_a);
	else if (ft_strcmp(input, "sb\n") == 0)
		swap(stack_b);
	else
	{
		swap(stack_a);
		swap(stack_b);
	}
}

static void	push_operation(char *input, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(input, "pa\n") == 0)
		push(stack_b, stack_a);
	else
		push(stack_a, stack_b);
}

static void	rotate_operation(char *input, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(input, "ra\n") == 0)
		rotate(stack_a);
	else if (ft_strcmp(input, "rb\n") == 0)
		rotate(stack_b);
	else
	{
		rotate(stack_a);
		rotate(stack_b);
	}
}

static void	rev_rot_operation(char *input, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(input, "rra\n") == 0)
		reverse_rotate(stack_a);
	else if (ft_strcmp(input, "rrb\n") == 0)
		reverse_rotate(stack_b);
	else
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
	}
}

void	read_input(t_stack **stack_a, t_stack **stack_b)
{
	char	*input;

	input = get_next_line(0);
	while (ft_strcmp(input, "\n") != 0)
	{
		if (ft_strcmp(input, "sa\n") == 0 || ft_strcmp(input, "sb\n") == 0
			|| ft_strcmp(input, "ss\n") == 0)
			swap_operation(input, stack_a, stack_b);
		else if (ft_strcmp(input, "pa\n") == 0 || ft_strcmp(input, "pb\n") == 0)
			push_operation(input, stack_a, stack_b);
		else if (ft_strcmp(input, "ra\n") == 0 || ft_strcmp(input, "rb\n") == 0
			|| ft_strcmp(input, "rr\n") == 0)
			rotate_operation(input, stack_a, stack_b);
		else if (ft_strcmp(input, "rra\n") == 0
			|| ft_strcmp(input, "rrb\n") == 0 || ft_strcmp(input, "rrr\n") == 0)
			rev_rot_operation(input, stack_a, stack_b);
		else
			error_exit(*stack_a, *stack_b);
		free(input);
		input = get_next_line(0);
	}
	free(input);
}
