/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:01:38 by mperrine          #+#    #+#             */
/*   Updated: 2026/03/09 12:33:42 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	add_to_stack(const int nb, t_stack **stack)
{
	t_stack	*new_elem;

	new_elem = malloc(sizeof(t_stack));
	if (!new_elem)
		error_exit(*stack, NULL);
	new_elem->nb = nb;
	new_elem->next = NULL;
	if (!stack || !*stack)
		*stack = new_elem;
	else
		get_last_elem(*stack)->next = new_elem;
}

int	get_number(char **input, t_stack *stack)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	if (**input == '+' || **input == '-')
		sign = ((*(*input)++ % 43) * -1) + 1;
	if (**input && !(**input >= '0' && **input <= '9'))
		error_exit(stack, NULL);
	while (**input && (**input >= '0' && **input <= '9'))
		res = (res * 10) + (*(*input)++ - '0');
	if (res * sign > INT_MAX || res * sign < INT_MIN
		|| **input == '+' || **input == '-')
		error_exit(stack, NULL);
	return (((int) res) * sign);
}

int	is_str_empty(char **input)
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

int	already_in_stack(t_stack *stack, const int nb)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->nb == nb)
			return (1);
		stack = stack->next;
	}
	return (0);
}
