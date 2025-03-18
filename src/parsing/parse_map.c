/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohchoi <bohchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 06:23:17 by seongkim          #+#    #+#             */
/*   Updated: 2025/03/18 19:52:06 by bohchoi          ###   ########.fr       */
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
		parse_error("allocation failed");
	i = 0;
	while (i < y)
	{
		data->map_x[i] = WS * ft_strlen(data->map[i]);
		++i;
	}
}

int	map_range(t_data *data, int x, int y)
{
	return (y >= 0 && y < data->map_y && x >= 0 && \
			x < (int)ft_strlen(data->map[y]));
}

void	check_wall(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if ((data->map[y][x] < '0' || data->map[y][x] > '3') &&
				(!(ft_strchr("NSEW ", data->map[y][x]))))
				parse_error("invalid map file111111");
			if (data->map[y][x] == '0' || data->map[y][x] == '3' ||
				ft_strchr("NSEW", data->map[y][x]))
			{
				if (!map_range(data, x, y - 1) || data->map[y - 1][x] == ' ' ||
					!map_range(data, x, y + 1) || data->map[y + 1][x] == ' ' ||
					!map_range(data, x - 1, y) || data->map[y][x - 1] == ' ' ||
					!map_range(data, x + 1, y) || data->map[y][x + 1] == ' ')
					parse_error("invalid map file222222");
			}
			x++;
		}
		y++;
	}
}
