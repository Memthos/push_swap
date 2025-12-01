/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:01:38 by mperrine          #+#    #+#             */
/*   Updated: 2025/11/28 11:06:26 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	setup_stack_indexes(t_stack **stack)
{
	t_stack	*current;
	t_stack	*checking;
	int		max;

	current = *stack;
	max = 0;
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
		if (current->idx > max)
			max = current->idx;
		current = current->next;
	}
}

static void	add_to_stack(const int nb, t_stack **stack)
{
	t_stack	*new_elem;

	new_elem = malloc(sizeof(t_stack));
	if (!new_elem)
		error_exit(stack, NULL);
	new_elem->nb = nb;
	new_elem->next = NULL;
	if (!*stack)
	{
		new_elem->prev = NULL;
		*stack = new_elem;
	}
	else
	{
		new_elem->prev = get_last_elem(stack);
		get_last_elem(stack)->next = new_elem;
	}
}

static int	get_number(char **input, t_stack **stack)
{
	long int	res;
	int			sign;

	res = 0;
	sign = 1;
	if (**input == '+' || **input == '-')
	{
		if (**input == '-')
			sign = -1;
		(*input)++;
	}
	if (**input && !(**input >= '0' && **input <= '9'))
		error_exit(stack, NULL);
	while (**input && (**input >= '0' && **input <= '9'))
	{
		res = (res * 10) + (**input - 48);
		(*input)++;
	}
	if (res * sign > 2147483647 || res * sign < -2147483648
		|| **input == '+' || **input == '-')
		error_exit(stack, NULL);
	return (((int) res) * sign);
}

static int	is_str_empty(char **input)
{
	int	i;

	i = 0;
	while ((*input)[i])
	{
		if ((*input)[i] >= '0' && (*input)[i] <= '9')
			return (0);
		i++;
	}
	return (1);
}

void	setup_stack(char **input, t_stack **stack)
{
	int	nb;

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
				if (not_in_stack(stack, nb))
					error_exit(stack, NULL);
				add_to_stack(nb, stack);
			}
		}
		input++;
	}
	if (!stack || !*stack)
		error_exit(stack, NULL);
	setup_stack_indexes(stack);
}
