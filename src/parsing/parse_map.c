/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 06:23:17 by seongkim          #+#    #+#             */
/*   Updated: 2025/03/09 22:38:48 by seongkim         ###   ########.fr       */
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

// void	verify_map(t_data *data)
// {
// 	char	**map;
// 	t_point	cur;

// 	map = data->map;
// 	cur.y = 0;
// 	while (data->map[cur.y])
// 	{
// 		cur.x = 0;
// 		while (data->map[cur.y][cur.x])
// 		{
// 			if (data->map[cur.y][cur.x] == ' ')
// 			{
// 			}
// 		}
// 	}
// }
