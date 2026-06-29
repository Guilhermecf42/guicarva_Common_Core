/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 23:42:32 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/02 21:30:01 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*text[MAX_FD];
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	text[fd] = read_text(fd, text[fd]);
	if (!text[fd] || text[fd][0] == '\0')
		return (free(text[fd]), text[fd] = NULL, NULL);
	if (ft_strchr(text[fd], '\n'))
	{
		line = ft_substr(text[fd], 0, ft_strchr(text[fd], '\n') - text[fd] + 1);
		if (!line)
			return (free(text[fd]), text[fd] = NULL, NULL);
		temp = ft_strdup(ft_strchr(text[fd], '\n') + 1);
		return (free(text[fd]), text[fd] = temp, line);
	}
	line = ft_strdup(text[fd]);
	return (free(text[fd]), text[fd] = NULL, line);
}
