/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongkim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 21:45:49 by seongkim          #+#    #+#             */
/*   Updated: 2025/01/21 05:34:36 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		num;
	int		is_minus;

	i = 0;
	num = 0;
	is_minus = 0;
	while ((nptr[i] <= 9 && nptr[i] >= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			is_minus = 1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		num *= 10;
		num += nptr[i++] - '0';
	}
	if (is_minus)
		num *= -1;
	return (num);
}
