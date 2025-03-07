/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongkim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 04:28:20 by seongkim          #+#    #+#             */
/*   Updated: 2025/03/07 21:12:36 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_tex_info	*load_texture(char *path, t_data *data)
{
	t_tex_info	*tex;

	tex = ft_calloc(1, sizeof (t_tex_info));
	if (tex == NULL)
		parse_error(data);
	tex->img = mlx_xpm_file_to_image(data->mlx, path, &tex->x, &tex->y);
	if (tex->img == NULL)
		parse_error(data);
	tex->addr = mlx_get_data_addr(tex->img, &tex->bits_pixel, \
		&tex->line_length, &tex->endian);
	if (tex->addr == NULL)
		parse_error(data);
	return (tex);
}

void	init_textures(t_data *data)
{
	data->texture[0] = load_texture("tex/emeral.xpm", data);
	data->texture[1] = load_texture("tex/redstone.xpm", data);
	data->texture[2] = load_texture("tex/gold.xpm", data);
	data->texture[3] = load_texture("tex/dia.xpm", data);
	data->texture[4] = load_texture("tex/face.xpm", data);
}
