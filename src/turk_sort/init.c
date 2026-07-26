#include"turk_sort.h"

// time : O(1)
// space: O(1)
void	free_turk_cost(t_turk_costs *src)
{
	if (src != NULL)
	{
		free(src->rotate_cost);
		free(src->target_a);
		src->capacity = 0;
		src->length = 0;
		src->target_a = NULL;
		src->rotate_cost = NULL;
	}
}

// time : O(n)
// space: O(n)
t_turk_costs	init_turk_cost(size_t length)
{
	t_turk_costs	dst;
	size_t			i;

	dst.length = length;
	dst.capacity = length;
	dst.target_a = NULL;
	dst.rotate_cost = NULL;
	if (length > 0)
	{
		dst.target_a = (int *)malloc(sizeof(int) * length);
		if (dst.target_a == NULL)
			return (dst);
		dst.rotate_cost = (int *)malloc(sizeof(int) * length);
		if (dst.rotate_cost == NULL)
		{
			free_turk_cost(&dst);
			return (dst);
		}
		i = 0;
		while (i < length)
		{
			dst.target_a[i] = 0;
			dst.rotate_cost[i] = 0;
			i += 1;
		}
	}
	return (dst);
}

// time : O(1)
// space: O(1)
void	define_ith_turk_cost(int target_a, int rotate_cost,
			t_turk_costs *turk_cost, size_t index)
{
	if (is_turk_cost_valid(turk_cost, index) == true)
	{
		turk_cost->rotate_cost[index] = rotate_cost;
		turk_cost->target_a[index] = target_a;
	}
}

// time : O(a)
// space: O(1)
void	load_turk_cost_item(t_int_list *item_a, t_int_node *item_b,
	t_turk_costs *turk_cost, size_t index)
{
	t_int_node	*item;
	size_t		i;

	if (is_1_or_more(item_a) == true && item_b != NULL
		&& is_turk_cost_valid(turk_cost, 0) == true)
	{
		i = 0;
		item = item_a->item_1st;
		define_ith_turk_cost(item->moment, 0, turk_cost, index);
		while (item != NULL && i < item_a->length)
		{
			if (i <= item_a->length / 2)
				define_ith_turk_cost(item->moment, (int)i, turk_cost, index);
			else
				define_ith_turk_cost(item->moment,
					(int)item_a->length - (int)i,
					turk_cost, index);
			i += 1;
			item = item->future;
		}
	}
}

// time : O(b * a)
// space: O(b)
t_turk_costs	load_turk_cost(t_green_swap *src)
{
	t_int_node		*item_a;
	t_int_node		*item_b;
	size_t			i;
	t_turk_costs	dst;

	if (src == NULL || src->b.length == 0 || src->b.item_1st == NULL)
		return (init_turk_cost(0));
	dst = init_turk_cost(src->b.length);
	item_b = src->b.item_1st;
	i = 0;
	while (item_b == NULL && i < src->b.length)
	{
		load_turk_cost_item(&(src->a), item_b, &dst, i);
		item_b = item_b->future;
		i += 1;
	}
	return (dst);
}

