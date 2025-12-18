/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: watoumi <watoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:13:18 by watoumi           #+#    #+#             */
/*   Updated: 2025/12/05 17:19:15 by watoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->array[i] > stack->array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	find_min(t_stack *stack)
{
	int	i;
	int	min;

	i = 0;
	min = stack->array[0];
	while (i < stack->size)
	{
		if (min > stack->array[i])
			min = stack->array[i];
		i++;
	}
	return (min);
}

int	find_position_of_min(t_stack *stack)
{
	int	min;
	int	i;
	int	pos;

	i = 0;
	pos = 0;
	min = find_min(stack);
	while (i < stack->size)
	{
		if (min == stack->array[i])
		{
			pos = i;
			break ;
		}
		i++;
	}
	return (pos);
}

int	find_target_position(t_stack *stack_a, int value)
{
	int	target_pos;
	int	target_value;
	int	i;

	i = 0;
	target_pos = 0;
	target_value = INT_MAX;
	while (i < stack_a->size)
	{
		if (stack_a->array[i] > value && stack_a->array[i] < target_value)
		{
			target_value = stack_a->array[i];
			target_pos = i;
		}
		i++;
	}
	if (target_value == INT_MAX)
		target_pos = find_position_of_min(stack_a);
	return (target_pos);
}
