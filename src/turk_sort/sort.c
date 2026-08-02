#include"turk_sort.h"

// time : O(n)
// space: O(n)
t_turk_costs	first_turk_sort(t_2intlist *src, int show)
{
	t_turk_costs	dst;

	dst = load_turk_cost(NULL);
	if (is_2intlist_n_more(src, 3, 0) == true)
	{
		while (src->a.length > 3)
			action_push(src, show, E_A);
		sort_three(src, show);
		if (src->b.length == 0)
			return (dst);
		dst = load_turk_cost(src);
	}
	else if (is_2intlist_n_more(src, 2, 0) == true)
		sort_two(src, show);
	return (dst);
}

// time : O(1)
// space: O(1)
void	update_min_cost(size_t index, size_t cost, size_t *min_cost, size_t *min_index)
{
	if (min_cost != NULL && min_index != NULL
		&& (index == 0 || *min_cost > cost))
	{
		*min_cost = cost;
		*min_index = index;
	}
}

// time : O(n)
// space: O(1)
size_t	pod_of_greed(t_turk_costs *dst)
{
	size_t	i;
	size_t	min_cost;
	size_t	min_index;
	size_t	cost;

	if (is_turk_cost_valid(dst, 0) == false)
		return (0);
	min_cost = 0;
	min_index = 0;
	i = 0;
	while (is_turk_cost_valid(dst, i) == true && i <= dst->length / 2)
	{
		cost = (size_t)(i + f_abs(dst->rotate_cost[i]));
		update_min_cost(i, cost, &min_cost, &min_index);
		i += 1;
	}
	while (is_turk_cost_valid(dst, i) == true && i < dst->length)
	{
		cost = (size_t)((dst->length - i) + f_abs(dst->rotate_cost[i]));
		update_min_cost(i, cost, &min_cost, &min_index);
		i += 1;
	}
	return (min_index);
}
