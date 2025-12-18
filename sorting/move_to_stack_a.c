/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: watoumi <watoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:13:23 by watoumi           #+#    #+#             */
/*   Updated: 2025/12/05 17:19:10 by watoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	both_stacks_same_dir(t_stack *stack_a, t_stack *stack_b, t_cost *cost)
{
	while (cost->cost_a > 0 && cost->cost_b > 0
		&& cost->use_reverse_a == cost->use_reverse_b)
	{
		if (cost->use_reverse_a)
			rrr(stack_a, stack_b, 1);
		else
			rr(stack_a, stack_b, 1);
		cost->cost_a--;
		cost->cost_b--;
	}
}

void	make_move(t_stack *stack_a, t_stack *stack_b, t_cost *cost)
{
	both_stacks_same_dir(stack_a, stack_b, cost);
	while (cost->cost_a > 0)
	{
		if (cost->use_reverse_a)
			rra(stack_a, 1);
		else
			ra(stack_a, 1);
		cost->cost_a--;
	}
	while (cost->cost_b > 0)
	{
		if (cost->use_reverse_b)
			rrb(stack_b, 1);
		else
			rb(stack_b, 1);
		cost->cost_b--;
	}
	pa(stack_a, stack_b, 1);
}
