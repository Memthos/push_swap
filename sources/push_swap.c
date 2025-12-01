/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 12:53:54 by mperrine          #+#    #+#             */
/*   Updated: 2025/11/28 15:23:21 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	setup_stack(argv + 1, &stack_a);
	if (stack_sorted(&stack_a))
	{
		clear_stack(&stack_a);
		return (0);
	}
	if (get_stack_size(&stack_a) < 6)
		small_sort(&stack_a, &stack_b);
	else
	{
		k_distribution_sort(&stack_a, &stack_b);
		reintegration_sort(&stack_a, &stack_b);
	}
	clear_stack(&stack_a);
}
