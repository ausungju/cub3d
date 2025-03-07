/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongkim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 03:38:29 by seongkim          #+#    #+#             */
/*   Updated: 2025/03/07 13:31:34 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int i = 0;
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_pixel / 8));
	*(unsigned int *)dst = color;
}

void	re_draw(t_data *data)
{
	// mlx_destroy_image(data->mlx, data->img);
	// data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	// mlx_clear_window(data->mlx, data->win);
	draw_cam(data);
	draw_map(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	set_dda_var_with_raydir(t_fpoint rayDir, t_fpoint pos, t_dda *dda)
{
	if (rayDir.x < 0)
	{
		dda->step.x = -1;
		dda->side_dist.x = (pos.x - dda->map.x) * dda->delta_dist.x;
	}
	else
	{
		dda->step.x = 1;
		dda->side_dist.x = (dda->map.x + 1.0 - pos.x) * dda->delta_dist.x;
	}
	if (rayDir.y < 0)
	{
		dda->step.y = -1;
		dda->side_dist.y = (pos.y - dda->map.y) * dda->delta_dist.y;
	}
	else
	{
		dda->step.y = 1;
		dda->side_dist.y = (dda->map.y + 1.0 - pos.y) * dda->delta_dist.y;
	}
}

int	select_color(int x, int y, t_dda *dda, t_data *data)
{
	if (y >= dda->draw_start && y <= dda->draw_end)
	{
		if (dda->side == 1 && dda->step.y > 0)
			return (N_COLOR);
		else if (dda->side == 1 && dda->step.y < 0)
			return (S_COLOR);
		else if (dda->step.x > 0)
			return (E_COLOR);
		else
			return (W_COLOR);
	}
	else
		return (0x000000);
}

int	select_texture(t_dda *dda)
{
	if (dda->side == 0 && dda->step.x > 0)
		return (0);
	if (dda->side == 0 && dda->step.x < 0)
		return (1);
	if (dda->step.y > 0)
		return (2);
	return (3);	
}

int	draw_texture(int x, t_dda *dda, t_data *data)
{
	double	wall_x;
	int		texNum;
	int 	color;
	int		texY;
	
	texNum = select_texture(dda);
	if (dda->side == 0)
		wall_x = dda->pos.y + dda->perp_wall_dist * dda->ray_dir.y;
	else
		wall_x = dda->pos.x + dda->perp_wall_dist * dda->ray_dir.x;
	wall_x -= floor((wall_x));

	dda->tex_x = (int)(wall_x * (double)TEX_SIZE);
	if(dda->side == 0 && dda->ray_dir.x > 0) dda->tex_x = TEX_SIZE - dda->tex_x - 1;
	if(dda->side == 1 && dda->ray_dir.y < 0) dda->tex_x = TEX_SIZE - dda->tex_x - 1;

	double step = 1.0 * TEX_SIZE / dda->line_weight;
	double texPos = (dda->draw_start - HEIGHT / 2 + dda->line_weight / 2) * step;

	for(int y = 0; y < HEIGHT; y++)
	{
		int texY = (int)texPos & (TEX_SIZE - 1);
		if (y < dda->draw_start)
			color =  0x000000;
		else if (y >= dda->draw_start && y <= dda->draw_end)
		{
			texPos += step;
			color =  *(((unsigned int **)data->texture_addr)[texNum] + TEX_SIZE * texY + dda->tex_x);
		}
		else
			color = 0x222222;
		my_mlx_pixel_put(data, x, y, color);
	}
	return (0);
}
