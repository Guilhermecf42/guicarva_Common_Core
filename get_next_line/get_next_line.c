/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 23:42:02 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/02 21:16:07 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_text(int fd, char *text)
{
	char	*buffer;
	char	*temp;
	ssize_t	bytes_read;

	if (!text)
		text = ft_strdup("");
	if (!text)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free(text), NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(text, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), free(text), NULL);
		buffer[bytes_read] = '\0';
		temp = ft_join_free(text, buffer);
		if (!temp)
			return (free(buffer), NULL);
		text = temp;
	}
	return (free(buffer), text);
}

char	*get_next_line(int fd)
{
	static char	*text;
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	text = read_text(fd, text);
	if (!text || text[0] == '\0')
		return (free(text), text = NULL, NULL);
	if (ft_strchr(text, '\n'))
	{
		line = ft_substr(text, 0, ft_strchr(text, '\n') - text + 1);
		if (!line)
			return (free(text), text = NULL, NULL);
		temp = ft_strdup(ft_strchr(text, '\n') + 1);
		return (free(text), text = temp, line);
	}
	line = ft_strdup(text);
	return (free(text), text = NULL, line);
}
