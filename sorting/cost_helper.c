/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: watoumi <watoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:13:29 by watoumi           #+#    #+#             */
/*   Updated: 2025/12/05 17:19:04 by watoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// both rotate normally
void	combo0(int pos_a, int pos_b, int *min_cost, int *best_combo)
{
	int	combo0;

	if (pos_a > pos_b)
		combo0 = pos_a;
	else
		combo0 = pos_b;
	if (combo0 < *min_cost)
	{
		*min_cost = combo0;
		*best_combo = 0;
	}
}

// both rotate reverse
void	combo1(int a_rev, int b_rev, int *min_cost, int *best_combo)
{
	int	combo1;

	if (a_rev > b_rev)
		combo1 = a_rev;
	else
		combo1 = b_rev;
	if (combo1 < *min_cost)
	{
		*min_cost = combo1;
		*best_combo = 1;
	}
}

// a normal, b reverse
void	combo2(int pos_a, int b_rev, int *min_cost, int *best_combo)
{
	int	combo2;

	combo2 = pos_a + b_rev;
	if (combo2 < *min_cost)
	{
		*min_cost = combo2;
		*best_combo = 2;
	}
}

// a reverse, b normal
void	combo3(int pos_b, int a_rev, int *min_cost, int *best_combo)
{
	int	combo3;

	combo3 = a_rev + pos_b;
	if (combo3 < *min_cost)
	{
		*min_cost = combo3;
		*best_combo = 3;
	}
}
