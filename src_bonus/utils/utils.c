/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohchoi <bohchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 18:50:38 by seongkim          #+#    #+#             */
/*   Updated: 2025/04/03 19:43:29 by bohchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_fpoint	*get_player_point(t_fpoint *point, int scope, t_data *data)
{
	point->x = data->player.point.x * scope + 0.5;
	point->y = data->player.point.y * scope + 0.5;
	return (point);
}

void	point_locate_map(t_point *dest, t_fpoint *point)
{
	dest->x = point->x + MG;
	dest->y = point->y + MG;
}

void	parse_error(char *msg)
{
	write(2, "Error: ", 8);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(0);
}

int	call_exit(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
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
