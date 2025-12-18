/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: watoumi <watoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:14:13 by watoumi           #+#    #+#             */
/*   Updated: 2025/12/05 17:14:15 by watoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd, char *stash, char *buffer)
{
	char	*newline;
	int		bytes;
	char	*tmp;

	newline = ft_strchr(stash, '\n');
	while (!newline)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buffer);
			free(stash);
			stash = NULL;
			return (NULL);
		}
		if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		tmp = ft_strjoin(stash, buffer);
		free(stash);
		stash = tmp;
		newline = ft_strchr(stash, '\n');
	}
	free(buffer);
	return (stash);
}

static char	*stash_null(char **stash)
{
	if (!*stash || *stash[0] == '\0')
	{
		free(*stash);
		*stash = NULL;
		return (NULL);
	}
	return (*stash);
}

static char	*print_line(char **stash)
{
	char	*newline;
	char	*line;
	char	*tmp;
	int		len;

	newline = ft_strchr(*stash, '\n');
	if (newline)
	{
		len = newline - *stash + 1;
		line = ft_strndup(*stash, len);
		tmp = ft_strdup(*stash + len);
		free(*stash);
		*stash = tmp;
		return (line);
	}
	else
	{
		line = ft_strdup(*stash);
		free(*stash);
		*stash = NULL;
		return (line);
	}
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!stash)
		stash = ft_strdup("");
	stash = read_line(fd, stash, buffer);
	line = stash_null(&stash);
	line = print_line(&stash);
	return (line);
}
