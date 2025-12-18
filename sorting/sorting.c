/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: watoumi <watoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:13:15 by watoumi           #+#    #+#             */
/*   Updated: 2025/12/05 19:29:54 by watoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// sort 3 elements in stack a
void	sort_three(t_stack *stack_a, int a, int b, int c)
{
	if (a > b && b > c)
	{
		ra(stack_a, 1);
		sa(stack_a, 1);
	}
	else if (a > b && b < c && c > a)
		sa(stack_a, 1);
	else if (a > b && b < c && c < a)
		ra(stack_a, 1);
	else if (a < b && b > c && c < a)
		rra(stack_a, 1);
	else if (a < b && b > c && c > a)
	{
		sa(stack_a, 1);
		ra(stack_a, 1);
	}
}

void	handle_small_stack(t_stack *a)
{
	if (a->size == 2)
	{
		if (a->array[0] > a->array[1])
			sa(a, 1);
	}
	if (a->size == 3)
	{
		sort_three(a, a->array[0], a->array[1], a->array[2]);
	}
}

void	handle_big_stack(t_stack *a, t_stack *b)
{
	t_cost	less_cost;
	t_cost	current_cost;
	int		i;

	push_to_b_chunked(a, b);
	if (a->size == 3)
		sort_three(a, a->array[0], a->array[1], a->array[2]);
	else if (a->size == 2 && a->array[0] > a->array[1])
		sa(a, 1);
	while (b->size > 0)
	{
		less_cost = calculate_cost(a, b, 0);
		i = 1;
		while (i < b->size)
		{
			current_cost = calculate_cost(a, b, i);
			if (current_cost.total < less_cost.total)
				less_cost = current_cost;
			i++;
		}
		make_move(a, b, &less_cost);
	}
}

void	rotate_until_sorted(t_stack *stack_a)
{
	int	min_pos;

	min_pos = find_position_of_min(stack_a);
	if (min_pos <= stack_a->size / 2)
	{
		while (min_pos > 0)
		{
			ra(stack_a, 1);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < stack_a->size)
		{
			rra(stack_a, 1);
			min_pos++;
		}
	}
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a))
		return ;
	if (stack_a->size <= 3)
		handle_small_stack(stack_a);
	else
	{
		handle_big_stack(stack_a, stack_b);
		rotate_until_sorted(stack_a);
	}
}
