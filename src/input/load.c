#include"input.h"

// time : O(n)
// space: O(n)
char	*copy_str(const char *src)
{
	char	*dst;
	size_t	i;

	if (src == NULL)
		return (NULL);
	dst = malloc(sizeof(char) * (f_strlen(src) + 1));
	if (dst == NULL)
		return (NULL);
	dst[f_strlen(src)] = '\0';
	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i += 1;
	}
	return (dst);
}

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

// time : O(n)
// space: O(n)
char	**copy_strarr(const char **src, size_t length)
{
	char	**dst;
	size_t	i;

	if (src == NULL)
		return (NULL);
	dst = malloc(sizeof(char *) * (length + 1));
	if (dst == NULL)
		return (NULL);
	dst[length] = NULL;
	i = 0;
	while (i < length)
	{
		dst[i] = copy_str(src[i]);
		if (dst[i] == NULL)
		{
			free_2d_arr((void **)dst, i);
			return (NULL);
		}
		i += 1;
	}
	return (dst);
}

// time : O(n)
// space: O(n)
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
		if (f_strlen(src[i]) < 12)
			dst[i] = f_atoi(src[i], &is_int, "0123456789", f_strlen(src[i]));
		else
			is_int = false;
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
t_intnode	*load_intnode(const int *src, size_t length)
{
	t_intnode	*dst;
	t_intnode	*current;
	t_intnode	*next;
	size_t		i;

	if (src == NULL || length == 0)
		return (NULL);
	dst = init_intnode(src[0]);
	if (dst == NULL)
		return (NULL);
	current = dst;
	i = 1;
	while (i < length)
	{
		next = init_intnode(src[i]);
		if (next == NULL)
		{
			free_intnode(dst);
			return (NULL);
		}
		current->next = next;
		next->prev = current;
		current = next;
		i += 1;
	}
	return (dst);
}

// time : O(n)
// space: O(1)
t_intlist	load_intlist(const int *src, size_t length)
{
	t_intlist	dst;
	t_intnode	*item;

	dst.length = length;
	dst.item_1st = load_intnode(src, length);
	item = dst.item_1st;
	if (item != NULL)
	{
		while(item->next != NULL)
			item = item->next;
	}
	dst.item_last = item;
	return (dst);
}

// time : O(n)
// space: O(1)
t_2intlist	load_2intlist(const int *src, size_t length)
{
	t_2intlist	dst;

	dst.b.length = 0;
	dst.b.item_1st = NULL;
	dst.b.item_last = NULL;
	dst.a = load_intlist(src, length);
	return (dst);
}
