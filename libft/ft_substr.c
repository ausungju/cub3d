/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongkim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 21:46:49 by seongkim          #+#    #+#             */
/*   Updated: 2025/01/21 05:32:04 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	size_t	temp_len;
	char	*temp;

	if (!s)
		return (NULL);
	i = 0;
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (s_len - start > len)
		temp_len = len;
	else
		temp_len = s_len - start;
	temp = (char *)ft_calloc(sizeof (char), temp_len + 1);
	if (temp == NULL)
		return (NULL);
	while (i < len && start < s_len)
		temp[i++] = s[start++];
	return (temp);
}
