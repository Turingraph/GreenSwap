#include"input.h"

/*
// time : O(n)
// space: O(1)
void	free_2d_arr(void **arr, size_t len)
{
	while (len > 0 && arr != NULL)
	{
		if (len > 0 && arr[len - 1] != NULL)
			free(arr[len - 1]);
		len -= 1;
	}
	free(arr);
}
*/

// time : O(n)
// space: O(1)
size_t	f_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str != '\0')
	{
		i += 1;
		str += 1;
	}
	return (i);
}

// time : O(n)
// space: O(1)
int	*strarr_to_intarr(const char **src, size_t length)
{
	size_t	i;
	int		*dst;
	bool	is_int;

	if (length == 0 || src == NULL || *src == NULL)
		return (NULL);
	dst = (int *)malloc(sizeof(int) * length);
	if (dst == NULL)
		return (NULL);
	is_int = true;
	i = 0;
	while (i < length && src[i] != NULL && is_int == true)
	{
		dst[i] = f_atoi(src[i], is_int, "0123456789", f_strlen(src[i]));
		i += 1;
	}
	if (is_int == false)
	{
		free(dst);
		return (NULL);
	}
	return (dst);
}

// time : O(n)
// space: O(1)
t_chapter	*intarr_to_chapter(const int *src, size_t length)
{
	t_chapter	*dst;
	t_chapter	*current;
	t_chapter	*next;
	size_t		i;

	if (src == NULL || length == 0)
		return (NULL);
	dst = init_a_chapter(src[0]);
	if (dst == NULL)
		return (NULL);
	current = dst;
	i = 1;
	while (i < length)
	{
		next = init_a_chapter(src[i]);
		if (next == NULL)
		{
			memento_mori(dst);
			return (NULL);
		}
		current->future = next;
		next->flashback = current;
		current = next;
		i += 1;
	}
	return (dst);
}

// time : O(n)
// space: O(1)
t_int_list	intarr_to_intlist(const int *src, size_t length)
{
	t_int_list	dst;
	t_chapter	*item;

	dst.length = length;
	dst.item_1st = intarr_to_chapter(src, length);
	while(item != NULL && item->future != NULL)
		item = item->future;
	dst.item_last = item;
	return (dst);
}

// time : O(n)
// space: O(1)
t_green_swap	intarr_to_green_swap(const int *src, size_t length)
{
	t_green_swap	dst;
	t_chapter		*item;

	dst.b.length = 0;
	dst.b.item_1st = NULL;
	dst.b.item_last = NULL;
	dst.a = intarr_to_intlist(src, length);
	return (dst);
}
