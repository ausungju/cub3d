/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongkim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:46:04 by seongkim          #+#    #+#             */
/*   Updated: 2024/09/29 21:27:14 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_str_search_nl(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

char	*ft_substr_nl(char *s)
{
	size_t	i;
	size_t	start;
	size_t	temp_len;
	char	*temp;

	i = 0;
	start = ft_str_search_nl(s);
	if (!s[start])
		return (NULL);
	temp_len = ft_strlen(s) - start;
	if (temp_len > ft_strlen(s))
		return (NULL);
	temp = (char *)ft_calloc(sizeof (char), ++temp_len);
	if (!temp)
		return (NULL);
	while (s[i] && i < temp_len)
		temp[i++] = s[start++];
	return (temp);
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	stop;
	char	*temp;

	i = 0;
	if (!s1)
		s1 = "";
	stop = ft_str_search_nl(s2);
	temp = (char *)ft_calloc(sizeof (char), ft_strlen(s1) + stop + 1);
	if (!temp)
		return (NULL);
	j = 0;
	while (s1[j])
		temp[i++] = s1[j++];
	j = 0;
	while (s2[j] && j < stop)
		temp[i++] = s2[j++];
	return (temp);
}
