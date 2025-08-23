/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baelgadi <baelgadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 03:45:15 by baelgadi          #+#    #+#             */
/*   Updated: 2025/08/20 04:45:28 by baelgadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}

static int	has_duplicate(t_stack *a, int value)
{
	while (a)
	{
		if (a->value == value)
			return (1);
		a = a->next;
	}
	return (0);
}

static int	parse_number(const char *s, int *j, int *value)
{
	long	sign;
	long	number;
	int		digit_flag;

	sign = 1;
	number = 0;
	if (s[*j] == '+' || s[*j] == '-')
		if (s[(*j)++] == '-')
			sign = -1;
	digit_flag = 0;
	while (s[*j] >= '0' && s[*j] <= '9')
	{
		digit_flag = 1;
		number = number * 10 + (s[*j] - '0');
		if (sign * number > INT_MAX || sign * number < INT_MIN)
			return (-1);
		(*j)++;
	}
	if (!digit_flag)
		return (-1);
	*value = (int)(sign * number);
	return (1);
}

static int	parse_value(const char *s, int *j, int *value)
{
	int	status;
	int	start_pos;

	start_pos = *j;
	while (s[*j] && is_space(s[*j]))
		(*j)++;
	if (!s[*j])
	{
		if (start_pos == 0)
			return (-1);
		return (0);
	}
	status = parse_number(s, j, value);
	if (status != 1)
		return (status);
	if (s[*j] && !is_space(s[*j]))
		return (-1);
	return (1);
}

int	parse_args(int ac, char **av, t_stack **a)
{
	int	i;
	int	j;
	int	status;
	int	value;

	i = 1;
	while (i < ac)
	{
		j = 0;
		if (!av[i][0])
			return (0);
		while (av[i][j])
		{
			status = parse_value(av[i], &j, &value);
			if (status == -1 || (status == 1 && has_duplicate(*a, value)))
				return (0);
			if (status == 1)
				append_stack(a, value);
		}
		i++;
	}
	return (1);
}
