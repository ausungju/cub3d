/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongkim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 21:47:36 by seongkim          #+#    #+#             */
/*   Updated: 2025/01/21 05:34:14 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	get_digit(long long *num, int *is_minus, size_t *i)
{
	long long	result;

	if (*num == 0)
		return (1);
	if (*num < 0)
	{
		*is_minus = 1;
		*num *= -1;
		(*i)++;
	}
	result = 1;
	while (result <= *num)
		result *= 10;
	return ((int)(result / 10));
}

static	size_t	get_len(long long n, int digit)
{
	size_t	result;

	result = 0;
	while (digit >= 1)
	{
		result++;
		digit /= 10;
	}
	if (n < 0)
		result++;
	return (result + 1);
}

static	char	*get_temp(long long num, int digit, int is_minus)
{
	char	*result;

	if (is_minus)
	{
		result = (char *)malloc(sizeof (char) * (get_len(num, digit) + 1));
		if (result == NULL)
			return (NULL);
		*result = '-';
	}
	else
		result = (char *)malloc(sizeof (char) * (get_len(num, digit)));
	if (result == NULL)
		return (NULL);
	return (result);
}

char	*ft_itoa(int n)
{
	long long	num;
	int			digit;
	int			is_minus;
	size_t		i;
	char		*result;

	num = (long long)n;
	is_minus = 0;
	i = 0;
	digit = get_digit(&num, &is_minus, &i);
	result = get_temp(num, digit, is_minus);
	if (result == NULL)
		return (NULL);
	while (digit > 0)
	{
		result[i++] = (char)(num / digit + '0');
		num %= digit;
		digit /= 10;
	}
	result[i] = 0;
	return (result);
}
