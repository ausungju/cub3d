/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongkim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 21:45:55 by seongkim          #+#    #+#             */
/*   Updated: 2025/01/21 05:34:29 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	n;
	void	*temp;

	n = nmemb * size;
	if (size != 0 && n / size != nmemb)
		return (NULL);
	temp = malloc(nmemb * size);
	if (temp != NULL)
		ft_bzero(temp, nmemb * size);
	return (temp);
}
