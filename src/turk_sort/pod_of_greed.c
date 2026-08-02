#include"turk_sort.h"

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
void	first_card(t_turk_costs *dst, size_t *i, size_t *min_cost, size_t *min_index)
{
	size_t	cost;

	while (i != NULL && is_turk_cost_valid(dst, *i) == true
		&& *i <= dst->length / 2
		&& min_cost != NULL && min_index != NULL)
	{
		cost = (size_t)(*i + f_abs(dst->rotate_cost[*i]));
		update_min_cost(*i, cost, min_cost, min_index);
		*i += 1;
	}
}

// time : O(n)
// space: O(1)
void	second_card(t_turk_costs *dst, size_t *i, size_t *min_cost, size_t *min_index)
{
	size_t	cost;

	while (i != NULL && is_turk_cost_valid(dst, *i) == true
		&& *i < dst->length
		&& min_cost != NULL && min_index != NULL)
	{
		cost = (size_t)((dst->length - *i) + f_abs(dst->rotate_cost[*i]));
		update_min_cost(*i, cost, min_cost, min_index);
		*i += 1;
	}
}

// time : O(n)
// space: O(1)
size_t	pod_of_greed(t_turk_costs *dst)
{
	size_t	i;
	size_t	min_cost;
	size_t	min_index;

	if (is_turk_cost_valid(dst, 0) == false)
		return (0);
	min_cost = 0;
	min_index = 0;
	i = 0;
	first_card(dst, &i, &min_cost, &min_index);
	second_card(dst, &i, &min_cost, &min_index);
	return (min_index);
}
