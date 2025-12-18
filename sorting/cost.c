/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: watoumi <watoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:13:26 by watoumi           #+#    #+#             */
/*   Updated: 2025/12/05 17:19:06 by watoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	data_of_cost(t_cost *cost, int min_cost, int best_combo)
{
	cost->total = min_cost;
	cost->use_reverse_a = (best_combo == 1 || best_combo == 3);
	cost->use_reverse_b = (best_combo == 1 || best_combo == 2);
}

void	data_of_cost_a(t_cost *cost, int a_rev, int pos_a)
{
	if (cost->use_reverse_a)
		cost->cost_a = a_rev;
	else
		cost->cost_a = pos_a;
}

void	data_of_cost_b(t_cost *cost, int b_rev, int pos_b)
{
	if (cost->use_reverse_b)
		cost->cost_b = b_rev;
	else
		cost->cost_b = pos_b;
}

t_cost	calculate_cost(t_stack *stack_a, t_stack *stack_b, int pos_b)
{
	t_cost	cost;
	int		pos_a;
	int		min_cost;
	int		best_combo;

	pos_a = find_target_position(stack_a, stack_b->array[pos_b]);
	min_cost = INT_MAX;
	best_combo = 0;
	combo0(pos_a, pos_b, &min_cost, &best_combo);
	combo1((stack_a->size - pos_a), (stack_b->size - pos_b),
		&min_cost, &best_combo);
	combo2(pos_a, (stack_b->size - pos_b), &min_cost, &best_combo);
	combo3(pos_b, (stack_a->size - pos_a), &min_cost, &best_combo);
	data_of_cost(&cost, min_cost, best_combo);
	data_of_cost_a(&cost, (stack_a->size - pos_a), pos_a);
	data_of_cost_b(&cost, (stack_b->size - pos_b), pos_b);
	return (cost);
}
