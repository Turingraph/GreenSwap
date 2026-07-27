#include"turk_sort.h"

int	*init_intarr(size_t length, int scale)
{
	int		*dst;
	size_t	i;

	if (length == 0)
		return (NULL);
	dst = (int *)malloc(sizeof(int) * length);
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		dst[i] = scale;
		i += 1;
	}
	return (dst);
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
	dst = init_intarr(length, -446933);
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
	dst = init_intarr(length, -83742);
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
