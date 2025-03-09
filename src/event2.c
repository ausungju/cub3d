/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 03:34:49 by seongkim          #+#    #+#             */
/*   Updated: 2025/03/09 22:26:37 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_event_sleep(t_data *data)
{
	t_time	time;
	int		ms;

	if (gettimeofday(&time, NULL))
		parse_error(data);
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

int	mouse_event_sleep(t_data *data)
{
	t_time	time;
	int		ms;

	if (gettimeofday(&time, NULL))
		parse_error(data);
	ms = (long)(time.tv_sec * MS) - (long)(data->mouse_time.tv_sec * MS);
	ms += (long)(time.tv_usec / MS) - (long)(data->mouse_time.tv_usec / MS);
	if (ms > data->sleep_time)
	{
		data->mouse_time.tv_sec = time.tv_sec;
		data->mouse_time.tv_usec = time.tv_usec;
		data->sleep_time = M_DEFALT_SLEEP;
		return (0);
	}
	return (1);
}

int	mouse_event(int key_code, int x, int y, t_data *data)
{
	if (data->mouse_status)
	{
		mlx_mouse_show(data->mlx, data->win);
		mlx_mouse_move(data->mlx, data->win, WIDTH / 2, HEIGHT / 2);
	}
	else
	{
		mlx_mouse_hide(data->mlx, data->win);
		mlx_mouse_move(data->mlx, data->win, WIDTH / 2, HEIGHT / 2);
	}
	data->mouse_status = !data->mouse_status;
	return (0);
}

int	mouse_move_event(int x, int y, t_data *data)
{
	if (data->mouse_status)
	{
		rotate(&data->player.dir, (x - WIDTH / 2) * MOUSE_SPEED);
		rotate(&data->player.plane, (x - WIDTH / 2) * MOUSE_SPEED);
		mlx_mouse_move(data->mlx, data->win, WIDTH / 2, HEIGHT / 2);
	}
	return (0);
}
