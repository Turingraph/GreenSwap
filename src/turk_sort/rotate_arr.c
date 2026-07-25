#include"turk_sort.h"

// time : O(n)
// space: O(1)
int	*shift_by1_arr(int *dst, size_t length)
{
	size_t	i;

	i = 0;
	while (i < length - 1)
	{
		dst[i] = dst[i + 1];
		i += 1;
	}
	return (dst);
}

// time : O(n)
// space: O(n)
int	*rotate_arr(int *src, size_t length, size_t index)
{
	int		*dst;
	size_t	i;
	size_t	j;

	if (src == NULL || length == 0 || index >= length)
		return (NULL);
	dst = (int *)malloc(sizeof(int) * length);
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i + index < length)
	{
		dst[i] = src[i + index];
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
int	*rrotate_arr(int *src, size_t length, size_t index)
{
	int		*dst;
	size_t	i;
	size_t	j;

	if (src == NULL || length == 0 || index >= length)
		return (NULL);
	dst = (int *)malloc(sizeof(int) * length);
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i + index < length)
	{
		dst[i + index] = src[i];
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
