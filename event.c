/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongkim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 03:34:49 by seongkim          #+#    #+#             */
/*   Updated: 2025/03/07 21:09:35 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	re_draw(t_data *data)
{
	draw_cam(data);
	draw_map(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

int	move_envet(int key_code, t_data *data)
{
	if (key_code == 119)
	{
		if (data->map[(int)(data->player.point.y + \
			data->player.dir.y * 0.05)][(int)(data->player.point.x)] != '1')
			data->player.point.y += data->player.dir.y * 0.05;
		if (data->map[(int)(data->player.point.y)][(int)(data->player.point.x + \
			data->player.dir.x * 0.05)] != '1')
			data->player.point.x += data->player.dir.x * 0.05;
	}
	else if (key_code == 115)
	{
		if (data->map[(int)(data->player.point.y - data->player.dir.y * \
			0.05)][(int)(data->player.point.x)] != '1')
			data->player.point.y -= data->player.dir.y * 0.05;
		if (data->map[(int)(data->player.point.y)][(int)(data->player.point.x \
			- data->player.dir.x * 0.05)] != '1')
			data->player.point.x -= data->player.dir.x * 0.05;
	}
	return (0);
}

int	key_event(int key_code, t_data *data)
{
	if (key_code == 65307)
		call_exit(data);
	if (key_code == 65361)
	{
		rotate(&data->player.dir, -1);
		rotate(&data->player.plane, -1);
	}
	else if (key_code == 65363)
	{
		rotate(&data->player.dir, 1);
		rotate(&data->player.plane, 1);
	}
	else
		move_envet(key_code, data);
	re_draw(data);
	return (0);
}
