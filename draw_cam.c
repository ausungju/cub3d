/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongkim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 03:38:29 by seongkim          #+#    #+#             */
/*   Updated: 2025/03/07 13:11:39 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_dda_wall_var(int x, t_fpoint pos, t_data *data, t_dda *dda)
{
	double		cam_x;

	cam_x = 1 - (2 * x / (double)WIDTH);
	copy_fpoint(&dda->pos, &pos);
	dda->ray_dir.x = data->player.dir.x + data->player.plane.x * cam_x;
	dda->ray_dir.y = data->player.dir.y + data->player.plane.y * cam_x;
	dda->delta_dist.x = fabs(1 / dda->ray_dir.x);
	dda->delta_dist.y = fabs(1 / dda->ray_dir.y);
	dda->map.x = (int)pos.x;
	dda->map.y = (int)pos.y;
	set_dda_var_with_raydir(dda->ray_dir, pos, dda);
}

void	dda_wall(int x, t_dda *dda, t_data *data)
{
	int		y;

	if (dda->side == 0)
		dda->perp_wall_dist = (dda->side_dist.x - dda->delta_dist.x);
	else
		dda->perp_wall_dist = (dda->side_dist.y - dda->delta_dist.y);
		
	dda->line_weight = (int)((double)HEIGHT / dda->perp_wall_dist);
	
	dda->draw_start = -dda->line_weight / 2 + HEIGHT / 2;
	if (dda->draw_start < 0)
		dda->draw_start = 0;

	dda->draw_end = dda->line_weight / 2 + HEIGHT / 2;
	if (dda->draw_end >= HEIGHT)
		dda->draw_end = HEIGHT - 1;
	draw_texture(x, dda, data);
}

void	draw_wall(int x, t_fpoint pos, t_data *data)
{
	t_dda	dda;
	int		hit;

	hit = 0;
	set_dda_wall_var(x, pos, data, &dda);
	while (hit == 0)
	{
		if (dda.side_dist.x < dda.side_dist.y)
		{
			dda.side_dist.x += dda.delta_dist.x;
			dda.map.x += dda.step.x;
			dda.side = 0;
		}
		else
		{
			dda.side_dist.y += dda.delta_dist.y;
			dda.map.y += dda.step.y;
			dda.side = 1;
		}
		if (data->map[dda.map.y][dda.map.x] == '1')
			hit = 1;
	}
	dda_wall(x, &dda, data);
}

void	draw_cam(t_data *data)
{
	t_fpoint	pos;
	int		 	x;

	get_player_point(&pos, 1, data);
	x = 0;
	while (x < WIDTH)
	{
		draw_wall(x, pos, data);
		++x;
	}
}
