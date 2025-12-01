/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 12:53:55 by mperrine          #+#    #+#             */
/*   Updated: 2025/11/26 18:27:11 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libs/ft_printf/ft_printf.h"

typedef struct s_stack_node
{
	int					nb;
	int					idx;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack;

void	setup_stack(char **input, t_stack **stack);
int		not_in_stack(t_stack **stack, const int nb);
void	error_exit(t_stack **stack_a, t_stack **stack_b);
void	clear_stack(t_stack **stack);
int		stack_sorted(t_stack **stack);
void	k_distribution_sort(t_stack **stack_a, t_stack **stack_b);
void	reintegration_sort(t_stack **stack_a, t_stack **stack_b);
int		get_max_index(t_stack **stack);
int		get_index_pos(t_stack **stack, int idx);
void	small_sort(t_stack **stack_a, t_stack **stack_b);
int		get_stack_size(t_stack **stack);
t_stack	*get_last_elem(t_stack **stack);
void	swap(t_stack **stack, const char *stack_name);
void	push(t_stack **push, t_stack **pull, const char *stack_name);
void	rotate(t_stack **stack, const char *stack_name);
void	reverse_rotate(t_stack **stack, const char *stack_name);

#endif