/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongkim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 21:47:09 by seongkim          #+#    #+#             */
/*   Updated: 2025/01/21 05:33:05 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*temp;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	temp = (char *)malloc(sizeof (char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (temp == NULL)
		return (NULL);
	j = 0;
	while (s1[j])
		temp[i++] = s1[j++];
	j = 0;
	while (s2[j])
		temp[i++] = s2[j++];
	temp[i] = 0;
	return (temp);
}

char	*ft_strjoin_with_sep(char const *s1, char const *s2, char sep)
{
	size_t	i;
	size_t	j;
	char	*temp;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	temp = (char *)malloc(sizeof (char) * ft_strlen(s1) + ft_strlen(s2) + 2);
	if (temp == NULL)
		return (NULL);
	j = 0;
	while (s1[j])
		temp[i++] = s1[j++];
	j = 0;
	temp[i++] = sep;
	while (s2[j])
		temp[i++] = s2[j++];
	temp[i] = 0;
	return (temp);
}
