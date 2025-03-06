/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongkim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:28:36 by seongkim          #+#    #+#             */
/*   Updated: 2025/03/02 03:19:39 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = init_data(argc, argv);
	draw_cam(data);
	draw_map(data);
	mlx_key_hook(data->win, key_event, data);
	mlx_hook(data->win, 2, 1L << 0, key_event, data);
	mlx_hook(data->win, 17, 0, call_exit, data);
	mlx_loop(data->mlx);
}
