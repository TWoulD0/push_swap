/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: watoumi <watoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:13:31 by watoumi           #+#    #+#             */
/*   Updated: 2025/12/05 19:14:33 by watoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_next_in_chunk(t_stack *stack_a, int max_val)
{
	int	i;

	i = 0;
	while (i < stack_a->size)
	{
		if (stack_a->array[i] <= max_val)
			return (i);
		i++;
	}
	return (-1);
}

void	sort_arr(int *sorted, t_stack *stack_a)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < stack_a->size - 1)
	{
		j = 0;
		while (j < stack_a->size - i - 1)
		{
			if (sorted[j] > sorted[j + 1])
			{
				tmp = sorted[j];
				sorted[j] = sorted[j + 1];
				sorted[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	sort_stacka_in_arr(int **sorted, t_stack *stack_a)
{
	int	i;

	*sorted = malloc(sizeof(int) * stack_a->size);
	if (!*sorted)
		return ;
	i = 0;
	while (i < stack_a->size)
	{
		(*sorted)[i] = stack_a->array[i];
		i++;
	}
	sort_arr(*sorted, stack_a);
}
