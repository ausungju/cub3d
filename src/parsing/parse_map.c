/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongkim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 06:23:17 by seongkim          #+#    #+#             */
/*   Updated: 2025/03/08 06:50:01 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_map_size(t_data *data)
{
	int	y;
	int	i;

	y = get_strarr_size(data->map);
	data->map_y = y * WS;
	data->map_x = ft_calloc(y, sizeof(int));
	if (data->map_x == NULL)
		parse_error(data);
	i = 0;
	while (i < y)
	{
		data->map_x[i] = WS * ft_strlen(data->map[i]);
		++i;
	}
}

void	verify_map(t_data *data)
{
	
}

void	set_and_verify_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (check_character(data->map[y][x]))
			{
				data->player.char_dir = data->map[y][x];
				data->player.point.x = x;
				data->player.point.y = y;
				break ;
			}
			++x;
		}
		++y;
	}
	set_map_size(data);
}
