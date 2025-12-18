/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: watoumi <watoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:11:46 by watoumi           #+#    #+#             */
/*   Updated: 2025/12/05 18:36:08 by watoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	init_stacks(t_stack **a, t_stack **b, int total_count)
{
	*a = init_stack(total_count);
	*b = init_stack(total_count);
	if (!*a || !*b)
	{
		free_stack(*a);
		free_stack(*b);
		return (0);
	}
	return (1);
}

static int	parsing_arg(t_stack *a, t_stack *b, int argc, char **argv)
{
	if (!parse_arguments(argc, argv, a))
	{
		write(2, "Error\n", 6);
		free_stack(a);
		free_stack(b);
		return (0);
	}
	return (1);
}

static int	is_sort(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
	{
		free_stack(a);
		free_stack(b);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		total_count;

	if (argc < 2)
		return (0);
	total_count = count_total_numbers(argc, argv);
	if (!init_stacks(&stack_a, &stack_b, total_count))
		return (1);
	if (!parsing_arg(stack_a, stack_b, argc, argv))
		return (1);
	if (is_sort(stack_a, stack_b))
		return (0);
	sort_stack(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
