/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohchoi <bohchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 02:35:39 by seongkim          #+#    #+#             */
/*   Updated: 2025/04/02 18:21:54 by bohchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	select_parameter(char **line)
{
	int	id;

	id = 0;
	if (ft_strncmp(*line, "NO ", 3) == 0)
		id = NO;
	else if (ft_strncmp(*line, "SO ", 3) == 0)
		id = SO;
	else if (ft_strncmp(*line, "WE ", 3) == 0)
		id = WE;
	else if (ft_strncmp(*line, "EA ", 3) == 0)
		id = EA;
	else if (ft_strncmp(*line, "F ", 2) == 0)
		id = F;
	else if (ft_strncmp(*line, "C ", 2) == 0)
		id = C;
	else
		parse_error("invalid map file");
	*line += 2;
	return (id);
}

int	get_color(char *line)
{
	char	*element;
	int		color;
	int		i;

	i = 0;
	color = 0;
	while (i < 3)
	{
		element = get_element(&line);
		if (element == NULL)
			parse_error("get_element() failed");
		color += get_single_color(element) << ((2 - i++) * 8);
		free(element);
	}
	element = get_element(&line);
	if (element != NULL)
		parse_error("invalid map file");
	return (color);
}

void	set_color(int id, char *line, t_data *data)
{
	int		color;

	color = get_color(line);
	if (id == F)
	{
		if (data->floor != -1)
			parse_error("invalid map file");
		data->floor = color;
	}
	else
	{
		if (data->ceiling != -1)
			parse_error("invalid map file");
		data->ceiling = color;
	}
}

t_tex_info	*load_texture(char *path, t_data *data)
{
	t_tex_info	*tex;

	tex = ft_calloc(1, sizeof (t_tex_info));
	if (tex == NULL)
		parse_error("allocation failed");
	tex->img = mlx_xpm_file_to_image(data->mlx, path, &tex->x, &tex->y);
	if (tex->img == NULL)
		parse_error("mlx_xpm_file_to_image() failed");
	if (tex->x > tex->y || tex->y % tex->x != 0)
		parse_error("invalid texture size");
	tex->addr = mlx_get_data_addr(tex->img, &tex->bits_pixel, \
		&tex->line_length, &tex->endian);
	if (tex->addr == NULL)
		parse_error("mlx_get_data_addr() failed");
	tex->num = tex->y / tex->x;
	if (tex->num != 1)
	{
		tex->max_y = tex->y;
		tex->y = tex->x;
	}
	return (tex);
}

void	set_texture(int id, char *line, t_data *data)
{
	t_tex_info	*tex;
	char		*path;
	char		*tmp;

	if (data->texture[id] != NULL)
		parse_error("Invalid map file");
	path = get_element(&line);
	if (path == NULL)
		parse_error("get_element() failed");
	tmp = get_element(&line);
	if (tmp != NULL)
		parse_error("Invalid map file");
	tex = load_texture(path, data);
	free(path);
	data->texture[id] = tex;
}
