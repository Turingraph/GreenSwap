#include"merge_sort.h"

// time : O(n)
// space: O(1)
void	copy_intarr(const int *src, int *dst, size_t start, size_t stop)
{
	while (src != NULL && dst != NULL && start <= stop)
	{
		dst[start] = src[start];
		start += 1;
	}
}

// time : O(n)
// space: O(1)
void	linear_merge(const int *src, int *dst, size_t start, size_t stop)
{
	size_t	mid;
	size_t	i;
	size_t	j;

	if (start < stop && src != NULL && dst != NULL)
	{
		mid = (stop + start) / 2;
		i = start;
		j = mid + 1;
		while (i <= mid && j <= stop)
		{
			if (src[i] <= src[j])
			{
				dst[i] = src[i];
				i += 1;
			}
			else
			{
				dst[j] = src[j];
				j += 1;
			}
		}
		copy_intarr(src, dst, i, mid);
		copy_intarr(src, dst, j, stop);
	}
}

// time : O(n log n)
// space: O(1)
void	space_free_merge_sort(const int *src, int *dst, size_t start, size_t stop)
{
	size_t	mid;

	if (start < stop && src != NULL && dst != NULL)
	{
		mid = (stop + start) / 2;
		space_free_merge_sort(src, dst, start, mid);
		space_free_merge_sort(src, dst, mid + 1, stop);
		linear_merge(src, dst, start, stop);
	}
}

// time : O(n log n)
// space: O(n)
int	*merge_sort(const int *src, size_t length)
{
	int	*dst;

	if (src == NULL || length == 0)
		return (NULL);
	dst = (int *)malloc(sizeof(int) * length);
	if (dst == NULL)
		return (NULL);
	space_free_merge_sort(src, dst, 0, length - 1);
	return (dst);
}
