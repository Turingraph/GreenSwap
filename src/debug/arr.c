/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 11:00:31 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/11 11:00:32 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

// time : O(n)
// space: O(1)
bool	is_intarr_sort(const int *src, size_t length, int ascending)
{
	size_t	i;

	i = 1;
	while (i < length && src != NULL)
	{
		if (src[i - 1] * ascending > src[i] * ascending)
			return (false);
		i += 1;
	}
	return (true);
}

// time : O(n)
// space: O(n)
int	*clone_intarr(const int *src, size_t length)
{
	int		*dst;
	size_t	i;

	if (src == NULL || length == 0)
		return (NULL);
	dst = malloc(sizeof(int) * length);
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		dst[i] = src[i];
		i += 1;
	}
	return (dst);
}

// time : O(n)
// space: O(1)
void	write_intarr(int *src, size_t length, char *str)
{
	size_t	i;

	i = 0;
	if (str != NULL || str[0] != '\0')
		write(1, str, f_strlen(str));
	while (src != NULL && i < length)
	{
		ft_putnbr_fd(src[i], 1, "0123456789", 1);
		write(1, ", ", 2);
		i += 1;
	}
	write(1, "\n", 1);
}

// time : O(n)
// space: O(1)
bool	is_2intarr_same(const int *str_1, const int *str_2, size_t n)
{
	size_t	i;

	i = 0;
	if (str_1 == NULL && str_2 == NULL)
		return (true);
	if ((str_1 == NULL && str_2 != NULL) || (str_1 != NULL && str_2 == NULL))
		return (false);
	while (i < n - 1 && *str_1 == *str_2)
	{
		i += 1;
		str_1 += 1;
		str_2 += 1;
	}
	if (*str_1 - *str_2 == 0)
		return (true);
	return (false);
}
