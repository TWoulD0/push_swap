/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: watoumi <watoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:12:43 by watoumi           #+#    #+#             */
/*   Updated: 2025/12/05 17:48:43 by watoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line/get_next_line.h"

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

void	get_next_line_and_sort(t_stack *stack_a, t_stack *stack_b)
{
	char	*line;
	int		len;

	line = get_next_line(0);
	while (line != NULL)
	{
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		if (!is_valid_operation(line))
		{
			write(1, "Error\n", 6);
			free(line);
			free_stack(stack_a);
			free_stack(stack_b);
			exit (1);
		}
		sort_stack_no_print(line, stack_a, stack_b);
		free(line);
		line = get_next_line(0);
	}
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
	get_next_line_and_sort(stack_a, stack_b);
	if (is_sorted(stack_a) && stack_b->size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
