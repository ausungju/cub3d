/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongkim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 03:38:29 by seongkim          #+#    #+#             */
/*   Updated: 2025/03/05 21:19:39 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_dda_map_var(t_fpoint pos, t_fpoint rayDir, t_data *data, t_dda *dda)
{
	dda->delta_dist.x = fabs(1.0 / rayDir.x);
	dda->delta_dist.y = fabs(1.0 / rayDir.y);
	dda->map.x = (int)pos.x;
	dda->map.y = (int)pos.y;
	set_dda_var_with_raydir(rayDir, pos, dda);
}

void	dda_line(t_fpoint pos, t_fpoint rayDir, int color, t_data *data)
{
	t_dda	dda;
	int		hit;

	set_dda_map_var(pos, rayDir, data, &dda);
	hit = 0;
	while (hit == 0)
	{
		if (dda.map.x >= WIDTH || dda.map.y >= HEIGHT)
			return ;
		my_mlx_pixel_put(data, dda.map.x, dda.map.y, color);
		if (dda.side_dist.x < dda.side_dist.y)
		{
			dda.side_dist.x += dda.delta_dist.x;
			dda.map.x += dda.step.x;
		}
		else
		{
			dda.side_dist.y += dda.delta_dist.y;
			dda.map.y += dda.step.y;
		}
		if (data->map[(dda.map.y - MG) / WS][(dda.map.x - MG) / WS] == '1')
			hit = 1;
	}
}

void	draw_rader(t_data *data)
{
	t_fpoint	player;
	t_fpoint	dir;
	double		i;

	i = -30;
	point_locate_map(get_player_point(&player, WS, data));
	copy_fpoint(&dir, &data->player.dir);
	rotate(&dir, -30);
	while (i <= 30)
	{
		rotate(&dir, 0.005);
		dda_line(player, dir, 0x11AA11, data);
		i += 0.005;
	}
	dda_line(player, data->player.dir, 0xFF0000, data);
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
	draw_rader(data);
}
