#include"turk_sort.h"

// time : O(n)
// space: O(1)
void	free_turk_cost(t_turk_costs *dst)
{
	if (dst != NULL)
	{
		free(dst->target_a);
		free(dst->target_rotate);
		free(dst->rotate_cost);
		free(dst->total_cost);
		dst->target_a = NULL;
		dst->target_rotate = NULL;
		dst->rotate_cost = NULL;
		dst->total_cost = NULL;
		dst->length = 0;
		dst->capacity = 0;
	}
}

// time : O(1)
// space: O(n)
t_turk_costs	init_turk_cost(size_t length)
{
	t_turk_costs	dst;

	dst.length = 0;
	dst.capacity = length;
	dst.target_a = NULL;
	dst.target_rotate = NULL;
	dst.rotate_cost = NULL;
	dst.total_cost = NULL;
	if (length > 0)
	{
		dst.target_a = (int *)malloc(sizeof(int) * length);
		dst.target_rotate = (size_t *)malloc(sizeof(size_t) * length);
		dst.rotate_cost = (size_t *)malloc(sizeof(size_t) * length);
		dst.total_cost = (size_t *)malloc(sizeof(size_t) * length);
	}
	return (dst);
}

// time : O(1)
// space: O(1)
void	load_target_unit_a(t_turk_costs *dst,
			size_t index, size_t rotate_cost, int target)
{
	if (dst != NULL && dst->target_a != NULL && index < dst->length
		&& dst->target_rotate != NULL)
	{
		dst->target_a[index] = target;
		dst->rotate_cost[index] = rotate_cost;
	}
}

// time : O(n)
// space: O(1)
void	load_target_item_a(t_int_node *item_a, t_int_node *item_b,
			t_turk_costs *dst, size_t index)
{
	if (dst != NULL && dst->target_a != NULL && index < dst->length
		&& dst->target_rotate != NULL && item_a != NULL
		&& item_b != NULL)
	{
		load_target_unit_a(dst, index, 0, item_a->moment);
		while (item_a != NULL)
		{
			if (dst->target_a[index] > item_a->moment
				&& item_a->moment > item_b->moment)
				load_target_unit_a(dst, index, 0, item_a->moment);
			item_a = item_a->future;
		}
	}
}

// time : O(n)
// space: O(1)
void	load_target_a(const t_green_swap *src, t_turk_costs *dst)
{
	size_t		i;
	t_int_node	*item_b;

	if (src != NULL && src->a.length == 3
		&& is_both_stack_n_more(src, 3, 1) == true && dst != NULL)
	{
		dst->length = src->b.length;
		item_b = src->b.item_1st;
		i = 0;
		while (i < src->b.length)
		{
			load_target_item_a(src->a.item_1st, item_b, dst, i);
			item_b = item_b->future;
			i += 1;
		}
	}
}

