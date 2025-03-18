/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohchoi <bohchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 21:38:12 by seongkim          #+#    #+#             */
/*   Updated: 2025/03/18 15:42:38 by bohchoi          ###   ########.fr       */
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
					parse_error("invalid map file");
				data->player.char_dir = data->map[y][x];
				data->player.point.x = x;
				data->player.point.y = y;
			}
			++x;
		}
		++y;
	}
	if (data->player.char_dir == '\0')
		parse_error("invalid map file");
	set_map_size(data);
	check_wall(data);
}

void	set_map(int fd, t_data *data)
{
	char	*map_str;
	char	*line;
	char	*tmp;

	map_str = ft_strdup("");
	line = gnl_pass_empty_line(fd, FALSE);
	if (line == NULL)
		parse_error("invalid map file");
	while (line)
	{
		tmp = map_str;
		map_str = ft_strjoin(map_str, line);
		free(line);
		free(tmp);
		if (map_str == NULL)
			parse_error("ft_strjoin() failed");
		line = get_next_line(fd);
	}
	data->map = ft_split(map_str, '\n');
	free(map_str);
	if (data->map == NULL)
		parse_error("ft_split() failed");
	set_and_verify_map(data);
}

void	set_parameter(char *line, t_data *data)
{
	int	id;

	id = select_parameter(&line);
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
		parse_error("invalid map file name");
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		parse_error("open() failed");
	i = 0;
	while (i < 9)
	{
		line = gnl_pass_empty_line(fd, TRUE);
		if (line == NULL)
			parse_error("gnl_pass_empty_line() failed");
		set_parameter(line, data);
		free(line);
		++i;
	}
	set_map(fd, data);
	close(fd);
}
