/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 11:37:51 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/11 11:37:52 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "turk_sort.h"

// time : O(n)
// space: O(1)
int	*shift_arr(int *dst, size_t length)
{
	int		temp;
	int		temp2;

	temp = 0;
	if (dst != NULL)
		temp = dst[length - 1];
	while (length > 1 && dst != NULL)
	{
		temp2 = dst[length - 2];
		dst[length - 2] = temp;
		temp = temp2;
		length -= 1;
	}
	return (dst);
}

// time : O(n)
// space: O(1)
int	*rotate_value(int *src, size_t length_b,
	size_t rotate_effect, size_t length_a)
{
	size_t	i;

	if (src == NULL || length_b == 0 || rotate_effect > length_a)
		return (src);
	i = 0;
	while (i < length_b)
	{
		if ((src[i] - (int)rotate_effect >= -1 * (int)length_a / 2
				&& length_a % 2 == 1)
			|| (src[i] - (int)rotate_effect > -1 * (int)length_a / 2
				&& length_a % 2 == 0))
			src[i] -= (int)rotate_effect;
		else
			src[i] = src[i] - (int)rotate_effect + length_a;
		i += 1;
	}
	return (src);
}

// time : O(n)
// space: O(1)
int	*rrotate_value(int *src, size_t length_b,
	size_t rotate_effect, size_t length_a)
{
	size_t	i;

	if (src == NULL || length_b == 0 || rotate_effect > length_a)
		return (src);
	i = 0;
	while (i < length_b)
	{
		if (src[i] + (int)rotate_effect <= (int)length_a / 2)
			src[i] += (int)rotate_effect;
		else
			src[i] = src[i] + (int)rotate_effect - (int)length_a;
		i += 1;
	}
	return (src);
}

// time : O(n)
// space: O(n)
int	*rrotate_arr(int *src, size_t length, size_t rotate_effect)
{
	int		*dst;
	size_t	i;
	size_t	j;

	if (src == NULL || length == 0 || rotate_effect >= length)
		return (NULL);
	dst = (int *)malloc(sizeof(int) * length);
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i + rotate_effect < length)
	{
		dst[i] = src[i + rotate_effect];
		i += 1;
	}
	j = 0;
	while (i < length)
	{
		dst[i] = src[j];
		i += 1;
		j += 1;
	}
	return (dst);
}
