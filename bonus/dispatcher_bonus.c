/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baelgadi <baelgadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 01:33:56 by baelgadi          #+#    #+#             */
/*   Updated: 2025/08/22 21:19:46 by baelgadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	is_valid_instruction(const char *line, const char *instruction)
{
	while (*line && *instruction && *line == *instruction)
	{
		line++;
		instruction++;
	}
	return (*line == '\0' && *instruction == '\0');
}

static int	dispatch_pushes(const char *line, t_stack **a, t_stack **b)
{
	if (is_valid_instruction(line, "pa\n"))
		push_stack(b, a);
	else if (is_valid_instruction(line, "pb\n"))
		push_stack(a, b);
	else
		return (0);
	return (1);
}

static int	dispatch_swaps(const char *line, t_stack **a, t_stack **b)
{
	if (is_valid_instruction(line, "sa\n"))
		swap_stack(a);
	else if (is_valid_instruction(line, "sb\n"))
		swap_stack(b);
	else if (is_valid_instruction(line, "ss\n"))
	{
		swap_stack(a);
		swap_stack(b);
	}
	else
		return (0);
	return (1);
}

static int	dispatch_rotates(const char *line, t_stack **a, t_stack **b)
{
	if (is_valid_instruction(line, "ra\n"))
		rotate_stack(a);
	else if (is_valid_instruction(line, "rb\n"))
		rotate_stack(b);
	else if (is_valid_instruction(line, "rr\n"))
	{
		rotate_stack(a);
		rotate_stack(b);
	}
	else if (is_valid_instruction(line, "rra\n"))
		reverse_rotate_stack(a);
	else if (is_valid_instruction(line, "rrb\n"))
		reverse_rotate_stack(b);
	else if (is_valid_instruction(line, "rrr\n"))
	{
		reverse_rotate_stack(a);
		reverse_rotate_stack(b);
	}
	else
		return (0);
	return (1);
}

int	apply_instructions(const char *line, t_stack **a, t_stack **b)
{
	if (line[0] == 'p')
		return (dispatch_pushes(line, a, b));
	if (line[0] == 's')
		return (dispatch_swaps(line, a, b));
	if (line[0] == 'r')
		return (dispatch_rotates(line, a, b));
	return (0);
}
