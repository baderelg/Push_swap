/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baelgadi <baelgadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 03:36:33 by baelgadi          #+#    #+#             */
/*   Updated: 2025/08/22 21:16:18 by baelgadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define WINDOW_SMALL 15
# define WINDOW_BIG 35

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

int		parse_args(int ac, char **av, t_stack **a);

int		is_sorted(t_stack *stack);
void	free_stack(t_stack **stack);
void	error_exit(t_stack **a, t_stack **b);
int		stack_len(t_stack *s);
void	bubble_sort_array(int *arr, int size);

void	push_stack(t_stack **src, t_stack **dst);
void	rotate_stack(t_stack **stack);
void	reverse_rotate_stack(t_stack **stack);
void	swap_stack(t_stack **stack);
void	append_stack(t_stack **stack, int value);

void	sa(t_stack **a);
void	pa(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rra(t_stack **a);

void	sb(t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	rb(t_stack **b);
void	rrb(t_stack **b);

void	ss(t_stack **a, t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);

void	ez_sort(t_stack **a, t_stack **b, int size);

void	turk_sort(t_stack **a, t_stack **b, int size);

#endif
