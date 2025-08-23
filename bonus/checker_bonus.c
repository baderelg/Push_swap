/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baelgadi <baelgadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 01:33:51 by baelgadi          #+#    #+#             */
/*   Updated: 2025/08/22 21:19:41 by baelgadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	read_instructions(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_instruction(0);
	while (line)
	{
		if (!apply_instructions(line, a, b))
		{
			free(line);
			error_exit(a, b);
		}
		free(line);
		line = get_next_instruction(0);
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	if (!parse_args(ac, av, &a))
		error_exit(&a, &b);
	read_instructions(&a, &b);
	if (is_sorted(a) && b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
