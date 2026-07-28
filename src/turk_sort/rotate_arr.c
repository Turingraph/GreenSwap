#include"turk_sort.h"

// time : O(n)
// space: O(1)
void	push_rotate_arr(int *dst, size_t length, bool is_reverse)
{
	size_t	i;

	i = 0;
	while (i < length && dst != NULL)
	{
		if (is_reverse == false && length % 2 == 0
			&& dst[i] >= 0 && dst[i] < (int)(length / 2))
			dst[i] += 1;
		else if (is_reverse == false && length % 2 == 0
			&& dst[i] == (int)(length / 2))
			dst[i] *= -1;
		if (is_reverse == false && length % 2 == 1
			&& dst[i] >= 0 && dst[i] < (int)(length / 2) + 1)
			dst[i] += 1;
		if (is_reverse == true
			&& dst[i] < 0 && dst[i] > -1 * (int)(length / 2))
			dst[i] -= 1;
		if (is_reverse == true
			&& dst[i] == -1 * (int)(length / 2))
			dst[i] = (int)(length / 2);
		i += 1;
	}
}

// time : O(n)
// space: O(1)
int	*shift_by1_arr(int *dst, size_t length)
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

// time : O(n)
// space: O(n)
int	*rotate_arr(int *src, size_t length, size_t rotate_effect)
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
		dst[i + rotate_effect] = src[i];
		i += 1;
	}
	j = 0;
	while (i < length)
	{
		dst[j] = src[i];
		i += 1;
		j += 1;
	}
	return (dst);
}

// time : O(n)
// space: O(1)
int	*intarr_mod(int *dst, size_t length_b, int rotate_effect, size_t length_a)
{
	size_t	i;

	i = 0;
	while (i < length_b && dst != NULL && length_a > 0)
	{
		if (dst[i] < 0)
			dst[i] += length_a;
		dst[i] -= rotate_effect;
		dst[i] = dst[i] % length_a;
		if (dst[i] > (int)(length_a / 2))
			dst[i] = (int)(length_a - dst[i]) * -1;
		i += 1;
	}
	return (dst);
}

/*
80,	05,	13,	17,	32,	42
01,	20,	42,	60,	70
+1,	+2,	+5,	+0,	+0

05,	13,	17,	32,	42,	80
01,	20,	42,	60,	70
+0,	+3,	+4,	+5,	+5

13,	17,	32,	42,	80,	05
01,	20,	42,	60,	70
+5,	+2,	+3,	+4,	+4

17,	32,	42,	80,	05,	13
01,	20,	42,	60,	70
+4,	+1,	+2,	+3,	+3
*/

