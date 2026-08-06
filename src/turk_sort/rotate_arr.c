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

	// if (length_b == 2)
	// {
	// 	write(1, "rotate_effect\t=\t", 17);
	// 	ft_putnbr_fd(rotate_effect, 1, "0123456789", 1);
	// 	write(1, "\n", 1);
	// 	write(1, "length_a\t=\t", 12);
	// 	ft_putnbr_fd(length_a, 1, "0123456789", 1);
	// 	write(1, "\n", 1);
	// }

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
		if ((src[i] - (int)rotate_effect >= -1 * (int)length_a / 2 && length_a % 2 == 1)
			|| (src[i] - (int)rotate_effect > -1 * (int)length_a / 2 && length_a % 2 == 0))
			src[i] -= (int)rotate_effect;
		else
			src[i] = src[i] - (int)rotate_effect + length_a;
		i += 1;
	}
	return (src);
}

/*
// version 1
		src[i] += (int)length_a;
		src[i] -= (int)rotate_effect;
		src[i] = src[i] % length_a;
		if (src[i] > (int)(length_a / 2))
			src[i] = -1 * (int)(length_a - src[i]);

// version 2 (this is wrong)
		if ((src[i] - (int)rotate_effect <= -1 * (int)length_a / 2 && length_a % 2 == 1)
			|| (src[i] - (int)rotate_effect < -1 * (int)length_a / 2 && length_a % 2 == 0))
			src[i] -= (int)rotate_effect;
		else
			src[i] = (int)length_a + src[i] - (int)rotate_effect;

// version 3
		if ((src[i] - (int)rotate_effect >= -1 * (int)length_a / 2 && length_a % 2 == 1)
			|| (src[i] - (int)rotate_effect > -1 * (int)length_a / 2 && length_a % 2 == 0))
			src[i] -= (int)rotate_effect;
		else
			src[i] = src[i] - (int)rotate_effect + length_a;

// version 4
		if ((src[i] - (int)rotate_effect >= -1 * (int)length_a / 2 && length_a % 2 == 1)
			|| (src[i] - (int)rotate_effect > -1 * (int)length_a / 2 && length_a % 2 == 0))
			src[i] -= (int)rotate_effect;
		else
			src[i] = src[i] - (int)rotate_effect + length_a;
*/

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
