/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongkim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 18:50:38 by seongkim          #+#    #+#             */
/*   Updated: 2025/03/05 21:24:49 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_player *player, t_data *data)
{
	(void)data;
	player->point.x = 1;
	player->point.y = 2;
	player->dir.x = 0;
	player->dir.y = -1;
	player->plane.x = -0.66;
	player->plane.y = 0;
}

t_fpoint	*get_player_point(t_fpoint *point, int scope, t_data *data)
{
	point->x = data->player.point.x * scope;
	point->y = data->player.point.y * scope;
	return (point);
}

t_fpoint	*point_locate_map(t_fpoint *point)
{
	point->x += MG;
	point->y += MG;
	return (point);
}

t_data	*init_data(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		parse_error(NULL);
	data = ft_calloc(1, sizeof (t_data));
	if (data == NULL)
		exit(0);
	parse_argv(argv[1], data);
	init_player(&data->player, data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "cub3d");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_pixel, \
		&data->line_length, &data->endian);
	data->img_map = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr_map = mlx_get_data_addr(data->img_map, &data->bits_pixel, \
		&data->line_length, &data->endian);
	init_texture(data);
	return (data);
}

void	get_map_size(t_data *data)
{
	int	y_len;

	if (*data->map == NULL)
		exit(1);
	data->map_x = ft_strlen(*data->map);
	y_len = 0;
	while (data->map[y_len])
		++y_len;
	data->map_y = y_len;
}

void	parse_argv(char *file_name, t_data *data)
{
	char	*map_str;
	char	*line;
	char	*tmp;
	int		fd;

	if (ft_strncmp(ft_strrchr(file_name, '.'), ".cub", 5) != 0)
		parse_error(data);
	fd = open(file_name, O_RDONLY);
	map_str = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		tmp = map_str;
		map_str = ft_strjoin(map_str, line);
		free(line);
		free(tmp);
		if (map_str == NULL)
		{
			close(fd);
			parse_error(data);
		}
		line = get_next_line(fd);
	}
	close(fd);
	data->map = ft_split(map_str, '\n');
	get_map_size(data);
	if (data->map == NULL)
		parse_error(data);
}

void	parse_error(t_data *data)
{
	write(2, "Error\n", 7);
	free(data);
	exit(0);
}

int	call_exit(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data);
	exit(0);
}
