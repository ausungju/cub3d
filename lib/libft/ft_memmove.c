/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongkim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 21:47:54 by seongkim          #+#    #+#             */
/*   Updated: 2025/01/21 05:34:46 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*temp;
	const char	*s;

	if (dest == NULL && src == NULL)
		return (NULL);
	temp = (char *)dest;
	s = (const char *)src;
	if (dest <= src)
		while (n--)
			*(temp++) = *(s++);
	else
	{
		temp += n;
		s += n;
		while (n--)
			*(--temp) = *(--s);
	}
	return (dest);
}
