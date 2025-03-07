/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongkim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 20:01:25 by seongkim          #+#    #+#             */
/*   Updated: 2025/03/07 20:07:32 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_player(t_player *player, t_data *data)
{
	(void)data;
	player->point.x = 2;
	player->point.y = 2;
	player->dir.x = 0;
	player->dir.y = 1;
	player->plane.x = 0.66;
	player->plane.y = 0;
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
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_pixel, \
		&data->line_length, &data->endian);
	init_textures(data);
	return (data);
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
