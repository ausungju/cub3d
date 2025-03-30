/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongkim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:28:36 by seongkim          #+#    #+#             */
/*   Updated: 2025/03/30 20:11:50 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	re_draw(t_data *data)
{
	draw_cam(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = init_data(argc, argv);
	mlx_hook(data->win, 2, 1L << 0, key_event, data);
	mlx_hook(data->win, 17, 0, call_exit, data);
	mlx_loop_hook(data->mlx, re_draw, data);
	mlx_loop(data->mlx);
}
