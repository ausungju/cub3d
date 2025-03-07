/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongkim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 21:47:14 by seongkim          #+#    #+#             */
/*   Updated: 2024/09/28 21:47:15 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			count++;
			while (*s != c && *s)
				s++;
		}
	}
	return (count);
}

static char	*get_words(const char *s, char c, size_t *s_idx)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	*temp;

	i = 0;
	j = *s_idx;
	size = 0;
	while (s[j] != c && s[j])
	{
		size++;
		j++;
	}
	temp = (char *)ft_calloc(sizeof(char), size + 1);
	if (temp == NULL)
		return (NULL);
	while (i < size)
		temp[i++] = s[(*s_idx)++];
	return (temp);
}

static void	*free_ptr(char **result)
{
	size_t	i;

	i = 0;
	while (*(result + i))
		free(*(result + i++));
	free(result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	**ptr;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	len = count_word(s, c);
	ptr = (char **)ft_calloc(sizeof(char *), len + 1);
	if (ptr == NULL)
		return (NULL);
	while (i < len)
	{
		while (s[j] == c)
			j++;
		ptr[i] = get_words(s, c, &j);
		if (ptr[i] == NULL)
			return (free_ptr(ptr));
		i++;
	}
	return (ptr);
}
