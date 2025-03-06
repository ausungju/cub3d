/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongkim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 21:46:51 by seongkim          #+#    #+#             */
/*   Updated: 2025/01/21 05:32:37 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

static	size_t	get_start(char const *s, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (set[j] != s[i] && set[j])
			j++;
		if (set[j] == 0)
			break ;
		i++;
	}
	return (i);
}

static	size_t	get_end(char const *s, char const *set)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(s) - 1;
	while (s[i])
	{
		j = 0;
		while (set[j] != s[i] && set[j])
			j++;
		if (set[j] == 0)
			break ;
		i--;
	}
	return (i + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*temp;
	size_t	start;
	size_t	end;
	size_t	i;

	i = 0;
	if (!s1)
		return (NULL);
	start = get_start(s1, set);
	end = get_end(s1, set);
	if (end < start)
		return (ft_strdup(""));
	temp = (char *)malloc(sizeof (char) * end - start + 1);
	if (temp == 0)
		return (NULL);
	while (start < end)
		temp[i++] = s1[start++];
	temp[i] = 0;
	return (temp);
}
