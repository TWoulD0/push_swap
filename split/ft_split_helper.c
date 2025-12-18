/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: watoumi <watoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:13:09 by watoumi           #+#    #+#             */
/*   Updated: 2025/12/05 17:19:21 by watoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_there_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	word_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] && !is_there_space(str[i]))
		i++;
	return (i);
}

int	num_of_words(char *str)
{
	int	i;
	int	count_word;
	int	in_word;

	i = 0;
	count_word = 0;
	in_word = 0;
	while (str[i])
	{
		if (!is_there_space(str[i]) && !in_word)
		{
			in_word = 1;
			count_word++;
		}
		else if (is_there_space(str[i]))
			in_word = 0;
		i++;
	}
	return (count_word);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
