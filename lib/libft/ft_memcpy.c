/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongkim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 21:47:57 by seongkim          #+#    #+#             */
/*   Updated: 2025/01/21 05:33:39 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*temp;
	const char		*s;

	if (dest == 0 && src == 0)
		return (NULL);
	temp = (unsigned char *)dest;
	s = (const char *)src;
	while (n--)
		*(temp++) = *(s++);
	return (dest);
}
