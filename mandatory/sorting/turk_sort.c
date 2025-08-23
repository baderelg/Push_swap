/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baelgadi <baelgadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 04:21:24 by baelgadi          #+#    #+#             */
/*   Updated: 2025/08/23 03:39:38 by baelgadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_pos(t_stack *s, int value)
{
	int	pos;

	pos = 0;
	while (s)
	{
		if (s->value == value)
			return (pos);
		pos++;
		s = s->next;
	}
	return (-1);
}

static void	move_to_top(t_stack **s, int pos)
{
	int	len;

	len = stack_len(*s);
	if (pos <= len / 2)
	{
		while (pos-- > 0)
			rb(s);
	}
	else
	{
		while (pos++ < len)
			rrb(s);
	}
}

static int	*create_sorted_array(t_stack *a, int size)
{
	int	*arr;
	int	i;

	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (a)
	{
		arr[i++] = a->value;
		a = a->next;
	}
	bubble_sort_array(arr, size);
	return (arr);
}

static void	push_chunks_to_b(t_stack **a, t_stack **b, int *arr, int size)
{
	int	i;
	int	window;
	int	upper;

	i = 0;
	if (size <= 100)
		window = WINDOW_SMALL;
	else
		window = WINDOW_BIG;
	while (*a)
	{
		upper = i + window - 1;
		if (upper >= size)
			upper = size - 1;
		if ((*a)->value <= arr[upper])
		{
			pb(a, b);
			if ((*b)->value <= arr[i])
				rb(b);
			i++;
		}
		else
			ra(a);
	}
}

void	turk_sort(t_stack **a, t_stack **b, int size)
{
	int	*arr;

	arr = create_sorted_array(*a, size);
	if (!arr)
		error_exit(a, b);
	push_chunks_to_b(a, b, arr, size);
	while (size > 0)
	{
		move_to_top(b, find_pos(*b, arr[size - 1]));
		pa(a, b);
		size--;
	}
	free(arr);
}
