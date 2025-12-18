/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: watoumi <watoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:13:06 by watoumi           #+#    #+#             */
/*   Updated: 2025/12/05 17:19:23 by watoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*word_malloc(char *str)
{
	int		len;
	char	*word;
	int		i;

	len = word_len(str);
	word = malloc(len + 1);
	i = 0;
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

void	free_all(char **words, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(words[i]);
		i++;
	}
	free(words);
}

static char	**fill_words(char **words, char *str)
{
	int		i;
	int		word_index;

	i = 0;
	word_index = 0;
	while (str[i])
	{
		while (str[i] && is_there_space(str[i]))
			i++;
		if (str[i])
		{
			words[word_index] = word_malloc(str + i);
			if (!words[word_index])
			{
				free_all(words, word_index);
				return (NULL);
			}
			word_index++;
			while (str[i] && !is_there_space(str[i]))
				i++;
		}
	}
	words[word_index] = NULL;
	return (words);
}

char	**ft_split(char *str)
{
	int		count;
	char	**words;

	count = num_of_words(str);
	words = malloc(sizeof(char *) * (count + 1));
	if (!words)
		return (NULL);
	return (fill_words(words, str));
}
