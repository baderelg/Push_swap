/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baelgadi <baelgadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 03:40:27 by baelgadi          #+#    #+#             */
/*   Updated: 2025/08/21 00:32:27 by baelgadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	swap_stack(a);
	write(1, "sa\n", 3);
}

void	pa(t_stack **a, t_stack **b)
{
	push_stack(b, a);
	write(1, "pa\n", 3);
}

void	ra(t_stack **a)
{
	rotate_stack(a);
	write(1, "ra\n", 3);
}

void	rra(t_stack **a)
{
	reverse_rotate_stack(a);
	write(1, "rra\n", 4);
}
