/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 12:53:54 by mperrine          #+#    #+#             */
/*   Updated: 2026/03/09 13:21:59 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	error_exit(t_stack *stack_a, t_stack *stack_b)
{
	clear_stack(stack_a);
	clear_stack(stack_b);
	write(2, "Error\n", 6);
	exit(1);
}

void	clear_stack(t_stack *stack)
{
	t_stack	*next;

	if (!stack)
		return ;
	while (stack)
	{
		next = stack->next;
		free(stack);
		stack = next;
	}
}

static void	setup_stack_indexes(t_stack **stack)
{
	t_stack	*current;
	t_stack	*checking;

	current = *stack;
	while (current)
	{
		current->idx = 0;
		checking = *stack;
		{
			while (checking)
			{
				if (current->nb > checking->nb)
					current->idx++;
				checking = checking->next;
			}
		}
		current = current->next;
	}
}

static t_stack	*setup_stack(char **input)
{
	t_stack	*stack;
	int		nb;

	stack = NULL;
	while (*input)
	{
		if (is_str_empty(input))
			error_exit(stack, NULL);
		while (**input)
		{
			if (**input == ' ')
				(*input)++;
			else
			{
				nb = get_number(input, stack);
				if (already_in_stack(stack, nb))
					error_exit(stack, NULL);
				add_to_stack(nb, &stack);
			}
		}
		input++;
	}
	if (!stack)
		error_exit(stack, NULL);
	return (stack);
}

int	main(int argc, char *argv[])
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	if (argc < 2)
		return (0);
	stack_b = NULL;
	stack_a = setup_stack(argv + 1);
	setup_stack_indexes(&stack_a);
	read_input(&stack_a, &stack_b);
	if (stack_sorted(stack_a) && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	clear_stack(stack_a);
}
