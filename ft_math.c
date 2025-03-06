/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongkim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 06:51:39 by seongkim          #+#    #+#             */
/*   Updated: 2025/03/02 04:03:33 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	copy_fpoint(t_fpoint *f1, t_fpoint *f2)
{
	f1->x = f2->x;
	f1->y = f2->y;
}

double	rad(double angle)
{
	double	res;

	res = angle * (PI / 180);
	return (res);
}

void	rotate(t_fpoint *point, double angle)
{
	double	tmp_point_x;

	tmp_point_x = point->x;
	point->x = point->x * cos(rad(angle)) - point->y * sin(rad(angle));
	point->y = tmp_point_x * sin(rad(angle)) + point->y * cos(rad(angle));
}
