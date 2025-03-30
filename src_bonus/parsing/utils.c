/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 02:36:42 by seongkim          #+#    #+#             */
/*   Updated: 2025/03/09 23:11:01 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*gnl_pass_empty_line(int fd, int is_insert_nl)
{
	char	*s;

	s = get_next_line(fd);
	if (s == NULL)
		return (NULL);
	while (*s == '\n')
	{
		free(s);
		s = get_next_line(fd);
	}
	if (is_insert_nl)
		s[ft_strlen(s) - 1] = '\0';
	return (s);
}

char	*pass_space(char *line)
{
	while (*line == ' ')
		++line;
	return (line);
}

char	*get_element(char **line)
{
	char	*res;
	int		size;

	*line = pass_space(*line);
	if (**line == '\0')
		return (NULL);
	size = 0;
	while ((*line)[size] && (*line)[size] != ' ' && (*line)[size] != ',')
		++size;
	res = ft_substr(*line, 0, size);
	if ((*line)[size] == ',')
		++(*line);
	*line += size;
	return (res);
}

int	check_character(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}
