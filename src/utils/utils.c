/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongkim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 18:50:38 by seongkim          #+#    #+#             */
/*   Updated: 2025/03/08 05:53:43 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_fpoint	*get_player_point(t_fpoint *point, int scope, t_data *data)
{
	point->x = data->player.point.x * scope;
	point->y = data->player.point.y * scope;
	return (point);
}

void	point_locate_map(t_point *dest, t_fpoint *point)
{
	dest->x = point->x + MG;
	dest->y = point->y + MG;
}

void	parse_error(t_data *data)
{
	write(2, "Error\n", 7);
	exit(0);
}

int	call_exit(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data);
	exit(0);
}

int	get_strarr_size(char **ptr)
{
	int	size;

	size = 0;
	while (ptr[size])
		++size;
	return (size);
}
