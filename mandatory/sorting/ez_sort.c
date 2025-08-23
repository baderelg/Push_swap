/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ez_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baelgadi <baelgadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 04:11:26 by baelgadi          #+#    #+#             */
/*   Updated: 2025/08/20 04:43:16 by baelgadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && first < third && second < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && first > third && second < third)
		ra(a);
	else if (first < second && first < third && second > third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && first > third && second > third)
		rra(a);
}

static t_stack	*find_min(t_stack *a)
{
	t_stack	*min;

	min = a;
	while (a)
	{
		if (a->value < min->value)
			min = a;
		a = a->next;
	}
	return (min);
}

static void	push_min_to_b(t_stack **a, t_stack **b, int size)
{
	t_stack	*min;
	int		pos;
	t_stack	*tmp;

	min = find_min(*a);
	pos = 0;
	tmp = *a;
	while (tmp && tmp != min)
	{
		pos++;
		tmp = tmp->next;
	}
	if (pos <= size / 2)
		while (pos-- > 0)
			ra(a);
	else
		while (pos++ < size)
			rra(a);
	pb(a, b);
}

void	ez_sort(t_stack **a, t_stack **b, int size)
{
	if (size == 2 && !is_sorted(*a))
		sa(a);
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
	{
		while (size > 3)
		{
			push_min_to_b(a, b, size);
			size--;
		}
		sort_three(a);
		while (*b)
			pa(a, b);
	}
}
