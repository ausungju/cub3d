/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 20:01:25 by seongkim          #+#    #+#             */
/*   Updated: 2025/03/10 18:00:09 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_player_vector(int angle, t_player *player)
{
	player->dir.x = cos(rad(angle));
	player->dir.y = sin(rad(angle));
	player->plane.x = sin(rad(angle)) * 0.66;
	player->plane.y = -cos(rad(angle)) * 0.66;
}

void	init_player(t_player *player)
{
	if (player->char_dir == 'N')
		set_player_vector(90, player);
	else if (player->char_dir == 'S')
		set_player_vector(270, player);
	else if (player->char_dir == 'W')
		set_player_vector(180, player);
	else if (player->char_dir == 'E')
		set_player_vector(0, player);
}

void	init_mlx_var(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		parse_error("mlx_init failed");
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "cub3d");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (data->win == NULL || data->img == NULL)
		parse_error("mlx object creation failed");
	data->pause_img = mlx_xpm_file_to_image(data->mlx, "tex/pause_img.xpm", \
		&data->pause_x, &data->pause_y);
	if (data->pause_img == NULL)
		parse_error("mlx_xpm_file_to_image failed");
	data->addr = mlx_get_data_addr(data->img, &data->bits_pixel, \
		&data->line_length, &data->endian);
	if (data->addr == NULL)
		parse_error("mlx_get_data_addr() failed");
	data->texture = ft_calloc(7, sizeof (t_tex_info *));
	if (data->texture == NULL)
		parse_error("allocation failed");
}

t_data	*init_data(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		parse_error("empty argument");
	data = ft_calloc(1, sizeof (t_data));
	if (data == NULL)
		parse_error("allocation failed");
	data->floor = -1;
	data->ceiling = -1;
	data->player.char_dir = '\0';
	data->pause_status = 1;
	data->ani_val = 0;
	init_mlx_var(data);
	if (!mlx_mouse_get_pos(data->mlx, data->win, \
		&data->mouse_x, &data->mouse_y))
		parse_error("mlx_mouse_get_pos() failed\n");
	mlx_do_key_autorepeaton(data->mlx);
	file_parsing(argv[1], data);
	init_player(&data->player);
	if (gettimeofday(&data->key_time, NULL))
		parse_error("gettimeofday() failed");
	if (gettimeofday(&data->mouse_time, NULL))
		parse_error("gettimeofday() failed");
	return (data);
}
