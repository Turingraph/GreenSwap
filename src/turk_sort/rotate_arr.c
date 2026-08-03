#include"turk_sort.h"

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

	if (src == NULL || length_b == 0 || rotate_effect > length_b)
		return (src);
	i = 0;
	if (length_b == 2)
	{
		write(1, "rotate_effect\t=\t", 17);
		ft_putnbr_fd(rotate_effect, 1, "0123456789", 1);
		write(1, "\n", 1);
		write(1, "length_a\t=\t", 12);
		ft_putnbr_fd(length_a, 1, "0123456789", 1);
		write(1, "\n", 1);
	}
	while (i < length_b)
	{
		src[i] += (int)length_a;
		src[i] -= (int)rotate_effect;
		src[i] = src[i] % length_a;
		if (src[i] > (int)(length_a / 2))
			src[i] = -1 * (int)(length_a - src[i]);
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
