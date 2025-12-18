/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: watoumi <watoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:13:35 by watoumi           #+#    #+#             */
/*   Updated: 2025/12/05 17:56:18 by watoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	free_and_return(char **split)
{
	free_split(split);
	return (0);
}

int	if_arg_have_space(char *argv, t_stack *stack_a)
{
	char	**split;
	int		j;
	long	num;

	split = ft_split(argv);
	if (!split)
		return (0);
	j = 0;
	while (split[j])
	{
		if (!is_valid_number(split[j]))
			return (free_and_return(split));
		num = ft_atol(split[j]);
		if (num > INT_MAX || num < INT_MIN)
			return (free_and_return(split));
		push_to_stack(stack_a, (int)num);
		j++;
	}
	free_split(split);
	return (1);
}

int	if_normal_arg(char *argv, t_stack *stack_a)
{
	long	num;

	if (!is_valid_number(argv))
		return (0);
	num = ft_atol(argv);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	push_to_stack(stack_a, (int)num);
	return (1);
}

int	parse_arguments(int argc, char **argv, t_stack *stack_a)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (arg_have_space(argv[i]))
		{
			if (!if_arg_have_space(argv[i], stack_a))
				return (0);
		}
		else
		{
			if (!if_normal_arg(argv[i], stack_a))
				return (0);
		}
		i++;
	}
	if (has_duplicates(stack_a))
		return (0);
	return (1);
}
