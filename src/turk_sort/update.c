#include"turk_sort.h"

// time : O(n)
// space: O(1)
void	update_target_a(const t_green_swap *src,
			t_turk_costs *dst, int new_item)
{
	size_t		i;
	t_int_node	*item_b;

	if (src != NULL && is_both_stack_n_more(src, 3, 1) == true && dst != NULL)
	{
		dst->length = src->b.length;
		item_b = src->b.item_1st;
		i = 0;
		while (i < src->b.length)
		{
			if (new_item > item_b->moment
				&& ((dst->target_a[i] >= item_b->moment
						&& new_item <= dst->target_a[i])
					|| dst->target_a[i] < item_b->moment))
				dst->target_a[i] = new_item;
			item_b = item_b->future;
			i += 1;
		}
	}
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

