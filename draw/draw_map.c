/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongkim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 03:38:29 by seongkim          #+#    #+#             */
/*   Updated: 2025/03/07 21:08:05 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_drawing_charater_var(t_point *origin, t_point *pos, t_data *data)
{
	t_fpoint	player;

	point_locate_map(origin, get_player_point(&player, WS, data));
	origin->x -= data->texture[4]->x / 2;
	origin->y -= data->texture[4]->y / 2;
	copy_point(pos, origin);
}

int	draw_character(t_data *data)
{
	t_point		origin_pos;
	t_point		pos;
	t_point		idx;

	set_drawing_charater_var(&origin_pos, &pos, data);
	idx.x = 0;
	while (idx.x < data->texture[4]->x)
	{
		idx.y = 0;
		pos.y = origin_pos.y;
		while (idx.y < data->texture[4]->y)
		{
			my_mlx_pixel_put(data, pos.x, pos.y, \
				get_texture_color(idx.x, idx.y, 4, data));
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
	int	max_y;

	y = MG;
	max_x = WS * data->map_x + MG;
	max_y = WS * data->map_y + MG;
	while (y < max_y)
	{
		x = MG;
		while (x < max_x)
		{
			if ((y - MG) / WS < data->map_y && (x - MG) / WS < data->map_x && \
				data->map[(y - MG) / WS][(x - MG) / WS] == '1')
				my_mlx_pixel_put(data, x, y, 0x333333);
			else
				my_mlx_pixel_put(data, x, y, 0x000000);
			++x;
		}
		++y;
	}
	draw_character(data);
}
