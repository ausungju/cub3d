/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongkim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 04:28:20 by seongkim          #+#    #+#             */
/*   Updated: 2025/03/06 18:12:51 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_texture(t_data *data)
{
	int	tex_x;
	int	tex_y;
	
	data->texture[0] = mlx_xpm_file_to_image(data->mlx, "tex/coal.xpm", &tex_x, &tex_y);
	data->texture_addr[0] = mlx_get_data_addr(data->texture[0], &data->bits_pixel_tex, &data->line_length_tex, &data->endian_tex);
	data->texture[1] = mlx_xpm_file_to_image(data->mlx, "tex/dia.xpm", &tex_x, &tex_y);
	data->texture_addr[1] = mlx_get_data_addr(data->texture[1], &data->bits_pixel_tex, &data->line_length_tex, &data->endian_tex);
	data->texture[2] = mlx_xpm_file_to_image(data->mlx, "tex/emeral.xpm", &tex_x, &tex_y);
	data->texture_addr[2] = mlx_get_data_addr(data->texture[2], &data->bits_pixel_tex, &data->line_length_tex, &data->endian_tex);
	data->texture[3] = mlx_xpm_file_to_image(data->mlx, "tex/gold.xpm", &tex_x, &tex_y);
	data->texture_addr[3] = mlx_get_data_addr(data->texture[3], &data->bits_pixel_tex, &data->line_length_tex, &data->endian_tex);
	data->texture[4] = mlx_xpm_file_to_image(data->mlx, "tex/iron.xpm", &tex_x, &tex_y);
	data->texture_addr[4] = mlx_get_data_addr(data->texture[4], &data->bits_pixel_tex, &data->line_length_tex, &data->endian_tex);
	data->texture[5] = mlx_xpm_file_to_image(data->mlx, "tex/lapis.xpm", &tex_x, &tex_y);
	data->texture_addr[5] = mlx_get_data_addr(data->texture[5], &data->bits_pixel_tex, &data->line_length_tex, &data->endian_tex);
	data->texture[6] = mlx_xpm_file_to_image(data->mlx, "tex/brick.xpm", &tex_x, &tex_y);
	data->texture_addr[6] = mlx_get_data_addr(data->texture[6], &data->bits_pixel_tex, &data->line_length_tex, &data->endian_tex);
}