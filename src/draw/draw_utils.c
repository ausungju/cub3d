/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongkim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 03:38:29 by seongkim          #+#    #+#             */
/*   Updated: 2025/03/30 20:13:52 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned int	get_texture_color(int x, int y, int num, t_data *data)
{
	t_tex_info	*tex;

	tex = data->texture[num];
	return (*(unsigned int *)(tex->addr + y * tex->line_length + \
		x * (tex->bits_pixel / 8)));
}

int	select_texture(t_dda *dda)
{
	if (dda->side == 0 && dda->step.x > 0)
		return (EA);
	if (dda->side == 0 && dda->step.x < 0)
		return (WE);
	if (dda->step.y > 0)
		return (NO);
	return (SO);
}

void	set_texture_var(t_dda *dda, t_data *data, t_draw_tex *draw_tex)
{
	double	wall_x;

	draw_tex->n = select_texture(dda);
	if (dda->side == 0)
		wall_x = dda->pos.y + dda->perp_wall_dist * dda->ray_dir.y;
	else
		wall_x = dda->pos.x + dda->perp_wall_dist * dda->ray_dir.x;
	wall_x -= floor((wall_x));
	draw_tex->tex_x = (int)(wall_x * (double)data->texture[draw_tex->n]->x);
	if (dda->side == 0 && dda->ray_dir.x > 0)
		draw_tex->tex_x = data->texture[draw_tex->n]->x - draw_tex->tex_x - 1;
	if (dda->side == 1 && dda->ray_dir.y < 0)
		draw_tex->tex_x = data->texture[draw_tex->n]->x - draw_tex->tex_x - 1;
	draw_tex->step = 1.0 * data->texture[draw_tex->n]->y / dda->line_weight;
	draw_tex->tex_pos = (dda->draw_start - HEIGHT / 2 + \
		dda->line_weight / 2) * draw_tex->step;
}

int	draw_texture(int x, t_dda *dda, t_data *data)
{
	t_draw_tex	draw_tex;
	int			y;
	int			color;
	int			tex_y;

	set_texture_var(dda, data, &draw_tex);
	y = 0;
	while (y < HEIGHT)
	{
		tex_y = (int)draw_tex.tex_pos & (data->texture[draw_tex.n]->y - 1);
		if (y < dda->draw_start)
			color = data->ceiling;
		else if (y >= dda->draw_start && y <= dda->draw_end)
		{
			draw_tex.tex_pos += draw_tex.step;
			color = get_texture_color(draw_tex.tex_x, tex_y, draw_tex.n, data);
		}
		else
			color = data->floor;
		my_mlx_pixel_put(data, x, y, color);
		++y;
	}
	return (0);
}
