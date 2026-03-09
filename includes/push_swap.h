/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 12:53:55 by mperrine          #+#    #+#             */
/*   Updated: 2026/03/09 12:28:47 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack_node
{
	int					nb;
	int					idx;
	struct s_stack_node	*next;
}						t_stack;

void	add_to_stack(const int nb, t_stack **stack);
int		get_number(char **input, t_stack *stack);
int		is_str_empty(char **input);
int		already_in_stack(t_stack *stack, const int nb);

void	error_exit(t_stack *stack_a, t_stack *stack_b);
void	clear_stack(t_stack *stack);

void	reintegration_sort(t_stack **stack_a, t_stack **stack_b);
void	k_distribution_sort(t_stack **stack_a, t_stack **stack_b);
void	small_sort(t_stack **stack_a, t_stack **stack_b);

int		stack_sorted(t_stack *stack);
int		get_stack_size(t_stack *stack);
t_stack	*get_last_elem(t_stack *stack);
t_stack	*get_penultimate_elem(t_stack *stack);

void	swap(t_stack **stack, const char stack_name);
void	push(t_stack **push, t_stack **pull, const char stack_name);
void	rotate(t_stack **stack, const char stack_name);
void	reverse_rotate(t_stack **stack, const char stack_name);

#endif
