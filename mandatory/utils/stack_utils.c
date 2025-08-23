/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baelgadi <baelgadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 00:30:12 by baelgadi          #+#    #+#             */
/*   Updated: 2025/08/22 02:20:58 by baelgadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	append_stack(t_stack **stack, int value)
{
	t_stack	*new;
	t_stack	*cur;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return ;
	new->value = value;
	new->next = NULL;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	cur = *stack;
	while (cur->next)
		cur = cur->next;
	cur->next = new;
}
