/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baelgadi <baelgadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 03:40:33 by baelgadi          #+#    #+#             */
/*   Updated: 2025/08/21 00:32:29 by baelgadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack **b)
{
	swap_stack(b);
	write(1, "sb\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	push_stack(a, b);
	write(1, "pb\n", 3);
}

void	rb(t_stack **b)
{
	rotate_stack(b);
	write(1, "rb\n", 3);
}

void	rrb(t_stack **b)
{
	reverse_rotate_stack(b);
	write(1, "rrb\n", 4);
}
