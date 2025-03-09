/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:28:36 by seongkim          #+#    #+#             */
/*   Updated: 2025/03/09 22:33:07 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	re_draw(t_data *data)
{
	int	x;
	int	y;

	data->ani_val = (data->ani_val + 0.1);
	draw_cam(data);
	draw_map(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = init_data(argc, argv);
	draw_cam(data);
	draw_map(data);
	mlx_hook(data->win, 2, 1L << 0, key_event, data);
	mlx_hook(data->win, 6, 1L << 6, mouse_move_event, data);
	mlx_hook(data->win, 4, 1L << 2, mouse_event, data);
	mlx_hook(data->win, 17, 0, call_exit, data);
	mlx_loop_hook(data->mlx, re_draw, data);
	mlx_loop(data->mlx);
}
