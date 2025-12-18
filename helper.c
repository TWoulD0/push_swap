/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: watoumi <watoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:12:39 by watoumi           #+#    #+#             */
/*   Updated: 2025/12/05 17:12:40 by watoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(int capacity)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (0);
	stack->array = (int *)malloc(sizeof(int) * capacity);
	if (!stack->array)
	{
		free(stack);
		return (0);
	}
	stack->size = 0;
	stack->capacity = capacity;
	return (stack);
}

void	free_stack(t_stack *stack)
{
	if (!stack)
		return ;
	if (stack->array)
		free(stack->array);
	free(stack);
}

int	arg_have_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_there_space(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	count_total_numbers(int argc, char **argv)
{
	char	**split;
	int		count;
	int		i;
	int		j;

	count = 0;
	i = 1;
	while (i < argc)
	{
		if (arg_have_space(argv[i]))
		{
			split = ft_split(argv[i]);
			j = 0;
			while (split[j])
			{
				count++;
				j++;
			}
			free_split(split);
		}
		else
			count++;
		i++;
	}
	return (count);
}
