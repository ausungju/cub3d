	 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 21:38:12 by seongkim          #+#    #+#             */
/*   Updated: 2025/03/09 22:23:40 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_and_verify_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (check_character(data->map[y][x]))
			{
				if (data->player.char_dir)
					parse_error(data);
				data->player.char_dir = data->map[y][x];
				data->player.point.x = x;
				data->player.point.y = y;
			}
			++x;
		}
		++y;
	}
	if (data->player.char_dir == '\0')
		parse_error(data);
	set_map_size(data);
	// verify_map(data);
}

void	set_map(int fd, t_data *data)
{
	char	*map_str;
	char	*line;
	char	*tmp;

	map_str = ft_strdup("");
	line = gnl_pass_empty_line(fd, FALSE);
	if (line == NULL)
		parse_error(data);
	while (line)
	{
		tmp = map_str;
		map_str = ft_strjoin(map_str, line);
		free(line);
		free(tmp);
		if (map_str == NULL)
			parse_error(data);
		line = get_next_line(fd);
	}
	data->map = ft_split(map_str, '\n');
	free(map_str);
	if (data->map == NULL)
		parse_error(data);
	set_and_verify_map(data);
}

void	set_parameter(char *line, t_data *data)
{
	int	id;

	id = select_parameter(&line, data);
	if (id == F || id == C)
		set_color(id, line, data);
	else
		set_texture(id, line, data);
}

void	file_parsing(char *file_path, t_data *data)
{
	char	*line;
	int		fd;
	int		i;

	if (ft_strncmp(ft_strrchr(file_path, '.'), ".cub", 5) != 0)
		parse_error(data);
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		parse_error(data);
	i = 0;
	while (i < 9)
	{
		line = gnl_pass_empty_line(fd, TRUE);
		if (line == NULL)
			parse_error(data);
		set_parameter(line, data);
		free(line);
		++i;
	}
	set_map(fd, data);
	close(fd);
}
