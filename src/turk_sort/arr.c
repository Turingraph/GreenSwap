#include"turk_sort.h"

// time : O(n)
// space: O(1)
void	shift_intarr(int *dst, size_t length, size_t missing_index)
{
	size_t	i;

	if (length > 0 && dst != NULL && missing_index < length - 1)
	{
		i = missing_index;
		while (i < length - 1)
		{
			dst[i] = dst[i + 1];
			i += 1;
		}
	}
}

// time : O(n)
// space: O(1)
void	update_rotate_cost(size_t *dst, size_t length)
{
	size_t	i;

	i = 0;
	while (dst != NULL && i <= length / 2)
	{
		dst[i] = i;
		i += 1;
	}
	while (dst != NULL && i < length)
	{
		dst[i] = length - i;
		i += 1;
	}
}

// time : O(n)
// space: O(1)
void	update_total_cost(const size_t *dst_a, size_t *dst_sum, size_t length)
{
	size_t	i;

	i = 0;
	while (i < length && dst_sum != NULL && dst_a != NULL)
	{
		dst_sum[i] += dst_a[i];
		i += 1;
	}
}
