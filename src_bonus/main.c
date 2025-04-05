/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:28:36 by seongkim          #+#    #+#             */
/*   Updated: 2025/03/10 18:04:42 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	re_draw(t_data *data)
{
	data->ani_val = (data->ani_val + TEXTURE_SPEED);
	if (!data->pause_status)
	{
		if (!mlx_mouse_get_pos(data->mlx, data->win, \
			&data->mouse_x, &data->mouse_y))
			parse_error("mlx_mouse_get_pos() failed\n");
		rotate(&data->player.dir, (data->mouse_x - WIDTH / 2) * MOUSE_SPEED);
		rotate(&data->player.plane, (data->mouse_x - WIDTH / 2) * MOUSE_SPEED);
		mlx_mouse_move(data->mlx, data->win, WIDTH / 2, HEIGHT / 2);
		mlx_destroy_image(data->mlx, data->img);
		data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
		if (data->img == NULL)
			parse_error("mlx_new_image() failed\n");
		draw_cam(data);
		draw_map(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
		printf("%f %f\n",data->player.point.x, data->player.point.y);
	}
	else
		mlx_put_image_to_window(data->mlx, data->win, data->pause_img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = init_data(argc, argv);
	mlx_hook(data->win, 2, 1L << 0, key_event, data);
	mlx_hook(data->win, 4, 1L << 2, mouse_event, data);
	mlx_hook(data->win, 17, 0, call_exit, data);
	mlx_loop_hook(data->mlx, re_draw, data);
	mlx_loop(data->mlx);
}
