/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongkim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 03:38:29 by seongkim          #+#    #+#             */
/*   Updated: 2025/03/07 14:03:48 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	bresenham_razer(t_point p1, t_point p2, int color, t_data *data)
{
    int dx = abs(p2.x - p1.x);
    int dy = abs(p2.y - p1.y);
    int sx = (p1.x < p2.x) ? 1 : -1;
    int sy = (p1.y < p2.y) ? 1 : -1;
    int err = dx - dy;

    while (1)
	{
		my_mlx_pixel_put_map(data, p1.x, p1.y, color);
        if ((p1.x == p2.x && p1.y == p2.y) || ((hit_check_map(p1.x, p1.y, data) || \
            hit_check_map(p1.x, p1.y + 1, data) || hit_check_map(p1.x + 1, p1.y, data) || \
            hit_check_map(p1.x - 1, p1.y, data) || hit_check_map(p1.x, p1.y - 1, data))))
			break ;
        int e2 = err * 2;
        if (e2 > -dy)
		{
            err -= dy;
            p1.x += sx;
        }
        if (e2 < dx)
		{
            err += dx;
            p1.y += sy;
        }
    }
}

int draw_razer(double angle, int color, t_data *data)
{
    t_point h;
	double	m;
	t_point	player;

	point_locate_map(get_player_point(&player, WS, data));
    m = tan(rad(angle));
    if (angle >= 315 || angle <= 45)
    {
        h.x = MG;
        h.y = (player.x - h.x) * m + player.y;
    }
    else if (angle > 45 && angle < 135)
    {
        h.y = WS * data->map_y + MG;
        h.x = (player.y - h.y) / m + player.x;
    }
    else if (angle >= 135 && angle <= 225)
    {
        h.x = WS * data->map_x + MG;
        h.y = (player.x - h.x) * m + player.y;
    }
    else if (angle > 225 && angle < 315)
    {
        h.y = MG;
        h.x = (player.y - h.y) / m + player.x;
    }
    bresenham_razer(player, h, color, data);
    return (0);
}

void    draw_rader(double angle, int color, t_data *data)
{
    double i;

    i = -60;
    while (i <= 60)
    {
        draw_razer(angle + i, color, data);
        i += 0.05;
    }
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
		while(x < max_x)
		{
			if ((y - MG) / WS < data->map_y && (x - MG) / WS < data->map_x && 
                data->map[(y - MG) / WS][(x - MG) / WS] == '1')
				my_mlx_pixel_put_map(data, x, y, 0x333333);
			else
				my_mlx_pixel_put_map(data, x, y, 0x000000);
			++x;
		}
		++y;
	}
    draw_rader(get_deg(&data->player.dir), 0x118811, data);
	draw_razer(get_deg(&data->player.dir), 0xFF0000, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
	