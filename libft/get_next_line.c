/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongkim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:35:05 by seongkim          #+#    #+#             */
/*   Updated: 2025/02/18 20:36:24 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	update_pointer(char **line, char **temp, char *str)
{
	char	*s;

	if (!str)
	{
		free(*line);
		free(*temp);
		*line = NULL;
		*temp = NULL;
		return (0);
	}
	s = ft_gnl_strjoin(*line, str);
	if (*line && *line != s)
		free(*line);
	*line = s;
	s = ft_substr_nl(str);
	if (*temp && *temp != s)
		free(*temp);
	*temp = s;
	if (*line && (*line)[ft_str_search_nl(*line) - 1] == '\n')
		return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	ssize_t		len;
	char		buf[BUFFER_SIZE + 1];
	char		*line;
	static char	*backup = NULL;

	line = NULL;
	if (backup && update_pointer(&line, &backup, backup))
		return (line);
	len = read(fd, buf, BUFFER_SIZE);
	while (len > 0)
	{
		buf[len] = 0;
		if (update_pointer(&line, &backup, buf))
			return (line);
		len = read(fd, buf, BUFFER_SIZE);
	}
	if (len == -1)
		update_pointer(&line, &backup, NULL);
	return (line);
}
