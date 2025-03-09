/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 02:35:39 by seongkim          #+#    #+#             */
/*   Updated: 2025/03/09 22:33:54 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	select_parameter(char **line, t_data *data)
{
	int	id;

	if (ft_strncmp(*line, "NO ", 3) == 0)
		id = NO;
	else if (ft_strncmp(*line, "SO ", 3) == 0)
		id = SO;
	else if (ft_strncmp(*line, "WE ", 3) == 0)
		id = WE;
	else if (ft_strncmp(*line, "EA ", 3) == 0)
		id = EA;
	else if (ft_strncmp(*line, "FA ", 3) == 0)
		id = FA;
	else if (ft_strncmp(*line, "DR ", 3) == 0)
		id = DR;
	else if (ft_strncmp(*line, "PT ", 3) == 0)
		id = PT;
	else if (ft_strncmp(*line, "F ", 2) == 0)
		id = F;
	else if (ft_strncmp(*line, "C ", 2) == 0)
		id = C;
	else
		parse_error(data);
	*line += 2;
	return (id);
}

int	get_color(int id, char *line, t_data *data)
{
	char	*element;
	int		color;
	int		i;

	i = 0;
	color = 0;
	while (i < 3)
	{
		element = get_element(id, &line);
		if (element == NULL)
			parse_error(data);
		color += ft_atoi(element) << ((2 - i++) * 8);
		free(element);
	}
	element = get_element(id, &line);
	if (element != NULL)
		parse_error(data);
	return (color);
}

void	set_color(int id, char *line, t_data *data)
{
	int		color;

	color = get_color(id, line, data);
	if (id == F)
	{
		if (data->floor != -1)
			parse_error(data);
		data->floor = color;
	}
	else
	{
		if (data->ceiling != -1)
			parse_error(data);
		data->ceiling = color;
	}
}

t_tex_info	*load_texture(char *path, t_data *data)
{
	t_tex_info	*tex;

	tex = ft_calloc(1, sizeof (t_tex_info));
	if (tex == NULL)
		parse_error(data);
	tex->img = mlx_xpm_file_to_image(data->mlx, path, &tex->x, &tex->y);
	if (tex->img == NULL || tex->x > tex->y || tex->y % tex->x != 0)
		parse_error(data);
	tex->addr = mlx_get_data_addr(tex->img, &tex->bits_pixel, \
		&tex->line_length, &tex->endian);
	tex->num = tex->y / tex->x;
	if (tex->num != 1)
	{
		tex->max_y = tex->y;
		tex->y = tex->x;
	}
	if (tex->addr == NULL)
		parse_error(data);
	return (tex);
}

void	set_texture(int id, char *line, t_data *data)
{
	t_tex_info	*tex;
	char		*path;
	char		*tmp;

	if (data->texture[id] != NULL)
		parse_error(data);
	path = get_element(id, &line);
	if (path == NULL)
		parse_error(data);
	tmp = get_element(id, &line);
	if (tmp != NULL)
		parse_error(data);
	tex = load_texture(path, data);
	free(path);
	data->texture[id] = tex;
}
