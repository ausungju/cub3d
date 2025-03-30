/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongkim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 03:34:49 by seongkim          #+#    #+#             */
/*   Updated: 2025/03/30 19:43:12 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	move_hit(int x, int y, t_data *data)
{
	return (data->map[y][x] != WALL);
}

int	key_event_sleep(t_data *data)
{
	t_time	time;
	int		ms;

	if (gettimeofday(&time, NULL))
		parse_error("gettimeofday() fail");
	ms = (long)(time.tv_sec * MS) - (long)(data->key_time.tv_sec * MS);
	ms += (long)(time.tv_usec / MS) - (long)(data->key_time.tv_usec / MS);
	if (ms > data->sleep_time)
	{
		data->key_time.tv_sec = time.tv_sec;
		data->key_time.tv_usec = time.tv_usec;
		data->sleep_time = K_DEFALT_SLEEP;
		return (0);
	}
	return (1);
}

int	ad_envet(int key_code, t_data *data)
{
	t_point	p;

	if (key_code == 97)
	{
		p.y = (int)(data->player.point.y - data->player.dir.x * MOVE_CHECK);
		p.x = (int)(data->player.point.x);
		if (move_hit(p.x, p.y, data))
			data->player.point.y -= data->player.dir.x * MOVE_SPEED;
		p.y = (int)(data->player.point.y);
		p.x = (int)(data->player.point.x + data->player.dir.y * MOVE_CHECK);
		if (move_hit(p.x, p.y, data))
			data->player.point.x += data->player.dir.y * MOVE_SPEED;
	}
	else if (key_code == 100)
	{
		p.y = (int)(data->player.point.y + data->player.dir.x * MOVE_CHECK);
		p.x = (int)(data->player.point.x);
		if (move_hit(p.x, p.y, data))
			data->player.point.y += data->player.dir.x * MOVE_SPEED;
		p.y = (int)(data->player.point.y);
		p.x = (int)(data->player.point.x - data->player.dir.y * MOVE_CHECK);
		if (move_hit(p.x, p.y, data))
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
		if (move_hit(p.x, p.y, data))
			data->player.point.y += data->player.dir.y * MOVE_SPEED;
		p.y = (int)(data->player.point.y);
		p.x = (int)(data->player.point.x + data->player.dir.x * MOVE_CHECK);
		if (move_hit(p.x, p.y, data))
			data->player.point.x += data->player.dir.x * MOVE_SPEED;
	}
	else if (key_code == 115)
	{
		p.y = (int)(data->player.point.y - data->player.dir.y * MOVE_CHECK);
		p.x = (int)(data->player.point.x);
		if (move_hit(p.x, p.y, data))
			data->player.point.y -= data->player.dir.y * MOVE_SPEED;
		p.y = (int)(data->player.point.y);
		p.x = (int)(data->player.point.x - data->player.dir.x * MOVE_CHECK);
		if (move_hit(p.x, p.y, data))
			data->player.point.x -= data->player.dir.x * MOVE_SPEED;
	}
	return (ad_envet(key_code, data));
}

int	key_event(int key_code, t_data *data)
{
	if (key_code == 65307)
		call_exit(data);
	if (key_event_sleep(data))
		return (0);
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
