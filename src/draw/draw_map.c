/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongkim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 03:38:29 by seongkim          #+#    #+#             */
/*   Updated: 2025/03/08 05:39:49 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_drawing_charater_var(t_point *origin, t_point *pos, t_data *data)
{
	t_fpoint	player;

	point_locate_map(origin, get_player_point(&player, WS, data));
	origin->x -= data->texture[FA]->x / 2;
	origin->y -= data->texture[FA]->y / 2;
	copy_point(pos, origin);
}

int	draw_character(t_data *data)
{
	t_point		origin_pos;
	t_point		pos;
	t_point		idx;

	set_drawing_charater_var(&origin_pos, &pos, data);
	idx.x = 0;
	while (idx.x < data->texture[FA]->x)
	{
		idx.y = 0;
		pos.y = origin_pos.y;
		while (idx.y < data->texture[FA]->y)
		{
			my_mlx_pixel_put(data, pos.x, pos.y, \
				get_texture_color(idx.x, idx.y, FA, data));
			++pos.y;
			++idx.y;
		}
		++pos.x;
		++idx.x;
	}
	return (0);
}

void	draw_map(t_data *data)
{
	int	x;
	int	y;
	int	max_x;

	y = 0;
	while (y < data->map_y)
	{
		x = 0;
		max_x = data->map_x[y / WS];
		while (x < max_x)
		{
			if (data->map[y / WS][x / WS] == '1' || \
				data->map[y / WS][x / WS] == ' ')
				my_mlx_pixel_put(data, x + MG, y + MG, 0x333333);
			else
				my_mlx_pixel_put(data, x + MG, y + MG, 0x000000);
			++x;
		}
		++y;
	}
	draw_character(data);
}
