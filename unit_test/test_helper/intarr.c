#include"test_helper.h"

// time : O(n)
// space: O(1)
void	write_intlist(t_intnode *dst, bool is_future)
{
	t_intnode	*temp;

	temp = dst;
	write(1, ">>> ", 4);
	while (temp != NULL)
	{
		ft_putnbr_fd(temp->value, 1, "0123456789", 1);
		write(1, ", ", 2);
		if (is_future == true)
			temp = temp->next;
		else
			temp = temp->prev;
	}
	write(1, "\n", 1);
}

// // time : O(n)
// // space: O(1)
// void	write_intarr(int *dst, size_t length)
// {
// 	size_t	i;

// 	i = 0;
// 	write(1, ">>> ", 4);
// 	while (dst != NULL && i < length)
// 	{
// 		ft_putnbr_fd(dst[i], 1, "0123456789", 1);
// 		write(1, ", ", 2);
// 		i += 1;
// 	}
// 	write(1, "\n", 1);
// }

// time : O(n)
// space: O(1)
bool	is_intarr_sort(const int *dst, size_t length, int ascending)
{
	size_t	i;

	i = 1;
	while (i < length && dst != NULL)
	{
		if (dst[i - 1] * ascending > dst[i] * ascending)
			return (false);
		i += 1;
	}
	return (true);
}

// time : O(n)
// space: O(1)
bool	is_intlist_sort(const t_intnode *dst, int ascending)
{
	while (dst != NULL && dst->next != NULL)
	{
		if (dst->value * ascending > dst->next->value * ascending)
			return (false);
		dst = dst->next;
	}
	return (true);
}

// time : O(n)
// space: O(1)
int	*copy_reverse_intarr(int *dst, const int *src, size_t length)
{
	size_t	i;

	i = 0;
	while (i < length && dst != NULL && src != NULL)
	{
		dst[i] = src[length - i - 1];
		i += 1;
	}
	return (dst);
}

