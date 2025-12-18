/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_by_chunks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: watoumi <watoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:13:20 by watoumi           #+#    #+#             */
/*   Updated: 2025/12/05 19:25:09 by watoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	get_num_chunks(int size)
{
	if (size > 100)
		return (5);
	return (3);
}

static int	get_chunk_max(int *sorted, int chunk, int num_chunks, int size)
{
	int	chunk_size;
	int	push_total;

	push_total = size - 3;
	chunk_size = push_total / num_chunks;
	if (chunk == num_chunks - 1)
		return (sorted[push_total - 1]);
	return (sorted[(chunk + 1) * chunk_size - 1]);
}

static int	get_target_push_count(int chunk, int num_chunks, int size)
{
	int	chunk_size;
	int	push_total;

	push_total = size - 3;
	chunk_size = push_total / num_chunks;
	if (chunk == num_chunks - 1)
		return (push_total - (chunk_size * (num_chunks - 1)));
	return (chunk_size);
}

static void	push_chunk(t_stack *a, t_stack *b, int chunk_max, int target)
{
	int	pushed;
	int	pos;

	pushed = 0;
	while (pushed < target && a->size > 3)
	{
		if (a->array[0] <= chunk_max)
		{
			pb(a, b, 1);
			pushed++;
		}
		else
		{
			pos = find_next_in_chunk(a, chunk_max);
			if (pos == -1)
				break ;
			if (pos <= a->size / 2)
				ra(a, 1);
			else
				rra(a, 1);
		}
	}
}

void	push_to_b_chunked(t_stack *stack_a, t_stack *stack_b)
{
	int	*sorted;
	int	num_chunks;
	int	chunk;
	int	target;
	int	size;

	size = stack_a->size;
	sort_stacka_in_arr(&sorted, stack_a);
	num_chunks = get_num_chunks(size);
	chunk = 0;
	while (chunk < num_chunks && stack_a->size > 3)
	{
		target = get_target_push_count(chunk, num_chunks, size);
		push_chunk(stack_a, stack_b,
			get_chunk_max(sorted, chunk, num_chunks, size), target);
		chunk++;
	}
	free(sorted);
}
