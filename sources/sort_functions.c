/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 12:55:31 by mperrine          #+#    #+#             */
/*   Updated: 2025/11/26 17:04:49 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	swap(t_stack **stack, const char *stack_name)
{
	int	tmp_nb;
	int	tmp_idx;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp_nb = (*stack)->nb;
	tmp_idx = (*stack)->idx;
	(*stack)->nb = (*stack)->next->nb;
	(*stack)->idx = (*stack)->next->idx;
	(*stack)->next->nb = tmp_nb;
	(*stack)->next->idx = tmp_idx;
	ft_printf("s%s\n", stack_name);
}

void	push(t_stack **push, t_stack **pull, const char *stack_name)
{
	t_stack	*tmp;

	if (!push || !*push)
		return ;
	tmp = *push;
	*push = (*push)->next;
	if (*push)
		(*push)->prev = NULL;
	if (!*pull)
		tmp->next = NULL;
	else
	{
		(*pull)->prev = tmp;
		tmp->next = *pull;
	}
	*pull = tmp;
	ft_printf("p%s\n", stack_name);
}

void	rotate(t_stack **stack, const char *stack_name)
{
	t_stack	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	tmp->next = NULL;
	tmp->prev = get_last_elem(stack);
	get_last_elem(stack)->next = tmp;
	ft_printf("r%s\n", stack_name);
}

void	reverse_rotate(t_stack **stack, const char *stack_name)
{
	t_stack	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = get_last_elem(stack);
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = tmp;
	ft_printf("rr%s\n", stack_name);
}
