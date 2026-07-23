#include"turk_sort.h"

// time : O(1)
// space: O(n)
t_turk_costs	init_turk_cost(size_t length)
{
	t_turk_costs	dst;

	dst.length = 0;
	dst.capacity = length;
	dst.smallest_big_a = NULL;
	dst.smallest_big_rotate = NULL;
	dst.rotate_cost = NULL;
	dst.total_cost = NULL;
	if (length > 0)
	{
		dst.smallest_big_a = (int *)malloc(sizeof(int) * length);
		dst.smallest_big_rotate = (size_t *)malloc(sizeof(size_t) * length);
		dst.rotate_cost = (size_t *)malloc(sizeof(size_t) * length);
		dst.total_cost = (size_t *)malloc(sizeof(size_t) * length);
	}
	return (dst);
}

// time : O(n)
// space: O(1)
void	update_rotate_cost()
{
	//
}

// time : O(n)
// space: O(1)
void	update_turk_cost(const t_green_swap *src, t_turk_costs *dst)
{
	if (src != NULL && dst != NULL)
	{
		dst->length = src->b.length;
	}
}
