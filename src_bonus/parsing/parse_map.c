/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohchoi <bohchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 06:23:17 by seongkim          #+#    #+#             */
/*   Updated: 2025/03/18 19:54:19 by bohchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_front_space_num(char *str)
{
	int	x;
	
	x = 0;
	while (str[x] && str[x] == ' ')
		x++;
	return (x);
}

void	resizing_map(int remove_num, t_data *data)
{
	int		y;
	int		i;
	char	*new_map_str;

	y = get_strarr_size(data->map);
	i = 0;
	while (i < y)
	{
		new_map_str = ft_substr(data->map[i], remove_num, ft_strlen(data->map[i]) + 1);
		free(data->map[i]);
		if (new_map_str == NULL)
			parse_error("allocation fail");
		data->map[i] = new_map_str;
		data->map_x[i] = WS * ft_strlen(data->map[i]);
		i++;
	}
}

void	set_map_size(t_data *data)
{
	int	y;
	int	i;
	int	min;
	int	space_num;

	y = get_strarr_size(data->map);
	data->map_y = y * WS;
	data->map_x = ft_calloc(y, sizeof(int));
	if (data->map_x == NULL)
		parse_error("allocation failed");
	i = 0;
	min = 2147483647;
	while (i < y)
	{
		data->map_x[i] = WS * ft_strlen(data->map[i]);
		space_num = get_front_space_num(data->map[i]);
		if (min > space_num)
			min = space_num;
		++i;
	}
	resizing_map(min, data);
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
				parse_error("invalid map file");
			if (data->map[y][x] == '0' || data->map[y][x] == '3' ||
				ft_strchr("NSEW", data->map[y][x]))
			{
				if (!map_range(data, x, y - 1) || data->map[y - 1][x] == ' ' ||
					!map_range(data, x, y + 1) || data->map[y + 1][x] == ' ' ||
					!map_range(data, x - 1, y) || data->map[y][x - 1] == ' ' ||
					!map_range(data, x + 1, y) || data->map[y][x + 1] == ' ')
					parse_error("invalid map file");
			}
			x++;
		}
		y++;
	}
}
