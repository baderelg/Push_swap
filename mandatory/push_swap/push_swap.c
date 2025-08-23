/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baelgadi <baelgadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 03:37:04 by baelgadi          #+#    #+#             */
/*   Updated: 2025/08/20 04:44:57 by baelgadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	if (!parse_args(ac, av, &a))
		error_exit(&a, &b);
	if (is_sorted(a))
	{
		free_stack(&a);
		return (0);
	}
	size = stack_len(a);
	if (size <= 5)
		ez_sort(&a, &b, size);
	else
		turk_sort(&a, &b, size);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
