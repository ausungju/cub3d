/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 03:34:49 by seongkim          #+#    #+#             */
/*   Updated: 2025/03/09 22:28:19 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ad_envet(int key_code, t_data *data)
{
	t_point	p;

	if (key_code == 97)
	{
		p.y = (int)(data->player.point.y - data->player.dir.x * MOVE_CHECK);
		p.x = (int)(data->player.point.x);
		if (data->map[p.y][p.x] != '1' && data->map[p.y][p.x] != '2')
			data->player.point.y -= data->player.dir.x * MOVE_SPEED;
		p.y = (int)(data->player.point.y);
		p.x = (int)(data->player.point.x + data->player.dir.y * MOVE_CHECK);
		if (data->map[p.y][p.x] != '1' && data->map[p.y][p.x] != '2')
			data->player.point.x += data->player.dir.y * MOVE_SPEED;
	}
	else if (key_code == 100)
	{
		p.y = (int)(data->player.point.y + data->player.dir.x * MOVE_CHECK);
		p.x = (int)(data->player.point.x);
		if (data->map[p.y][p.x] != '1' && data->map[p.y][p.x] != '2')
			data->player.point.y += data->player.dir.x * MOVE_SPEED;
		p.y = (int)(data->player.point.y);
		p.x = (int)(data->player.point.x - data->player.dir.y * MOVE_CHECK);
		if (data->map[p.y][p.x] != '1' && data->map[p.y][p.x] != '2')
			data->player.point.x -= data->player.dir.y * MOVE_SPEED;
	}
	return (0);
}

int	ws_envet(int key_code, t_data *data)
{
	t_point	p;

	if (key_code == 119)
	{
		p.y = (int)(data->player.point.y + data->player.dir.y * MOVE_CHECK);
		p.x = (int)(data->player.point.x);
		if (data->map[p.y][p.x] != '1' && data->map[p.y][p.x] != '2')
			data->player.point.y += data->player.dir.y * MOVE_SPEED;
		p.y = (int)(data->player.point.y);
		p.x = (int)(data->player.point.x + data->player.dir.x * MOVE_CHECK);
		if (data->map[p.y][p.x] != '1' && data->map[p.y][p.x] != '2')
			data->player.point.x += data->player.dir.x * MOVE_SPEED;
	}
	else if (key_code == 115)
	{
		p.y = (int)(data->player.point.y - data->player.dir.y * MOVE_CHECK);
		p.x = (int)(data->player.point.x);
		if (data->map[p.y][p.x] != '1' && data->map[p.y][p.x] != '2')
			data->player.point.y -= data->player.dir.y * MOVE_SPEED;
		p.y = (int)(data->player.point.y);
		p.x = (int)(data->player.point.x - data->player.dir.x * MOVE_CHECK);
		if (data->map[p.y][p.x] != '1' && data->map[p.y][p.x] != '2')
			data->player.point.x -= data->player.dir.x * MOVE_SPEED;
	}
	return (ad_envet(key_code, data));
}

void	door_event(t_data *data)
{
	t_point	p;
	double	d;

	d = 0;
	while (d < DOOR_DISTANCE)
	{
		p.y = (int)(data->player.point.y + data->player.dir.y * d);
		p.x = (int)(data->player.point.x + data->player.dir.x * d);
		if (data->map[p.y][p.x] == O_DR || data->map[p.y][p.x] == C_DR)
		{
			if (data->map[p.y][p.x] == O_DR)
				data->map[p.y][p.x] = C_DR;
			else
				data->map[p.y][p.x] = O_DR;
			data->sleep_time = DOOR_SLEEP;
			break ;
		}
		else if (data->map[p.y][p.x] == WALL || data->map[p.y][p.x] == PORTAL)
			break ;
		d += 0.01;
	}
}

int	key_event(int key_code, t_data *data)
{
	if (key_code == 65307)
		call_exit(data);
	if (key_event_sleep(data))
		return (0);
	if (key_code == 32)
		door_event(data);
	else if (key_code == 65361)
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
		ws_envet(key_code, data);
	return (0);
}
