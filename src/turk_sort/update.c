#include"turk_sort.h"

// time : O(n)
// space: O(1)
void	update_target_a(t_turk_costs *turk_cost, t_int_list *list_b, int dekmia)
{
	size_t		i;
	t_int_node	*item;

	item = NULL;
	if (list_b != NULL)
		item = list_b->item_1st;
	i = 0;
	while (is_turk_cost_valid(turk_cost, i) == true && item != NULL)
	{
		if ((dekmia >= item->moment && (dekmia < turk_cost->target_a[i]
				|| turk_cost->target_a[i] <= item->moment))
			|| (dekmia <= turk_cost->target_a[i]
				&& turk_cost->target_a[i] <= item->moment))
		{
			turk_cost->rotate_cost[i] = 0;
			turk_cost->target_a[i] = dekmia;
		}
		item = item->future;
		i += 1;
	}
}

// time : O(n)
// space: O(1)
void	update_rotate_cost(t_turk_costs *turk_cost, size_t rotate)
{
	size_t	i;
	size_t	half;
	
	if (turk_cost != NULL)
		half = turk_cost->length;
	i = 0;
	while (is_turk_cost_valid(turk_cost, i) == true)
	{
		if (turk_cost->rotate_cost[i] - (int)rotate >= (int)half * -1
			&& turk_cost->rotate_cost[i] <= (int)half)
			turk_cost->rotate_cost[i] -= (int)rotate;
		else if (turk_cost->rotate_cost[i] - (int)rotate < (int)half * -1)
			turk_cost->rotate_cost[i] = half;
		i += 1;
	}
}

// time : O(n)
// space: O(1)
void	update_rrotate_cost(t_turk_costs *turk_cost, size_t rotate)
{
	size_t	i;
	size_t	half;
	
	if (turk_cost != NULL)
		half = turk_cost->length;
	i = 0;
	while (is_turk_cost_valid(turk_cost, i) == true)
	{
		if (turk_cost->rotate_cost[i] + (int)rotate <= (int)half
			&& turk_cost->rotate_cost[i] >= (int)half * -1)
			turk_cost->rotate_cost[i] += (int)rotate;
		else if (turk_cost->rotate_cost[i] + (int)rotate > (int)half)
			turk_cost->rotate_cost[i] = (int)half * -1;
		i += 1;
	}
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
	while (i <= dst->length / 2)
	{
		if (dst->rotate_cost[i] < 0)
			cost = (size_t)(i + f_abs(dst->rotate_cost[i]));
		else
			cost = (size_t)(f_max(i, dst->rotate_cost[i]));
		update_min_cost(i, cost, &min_cost, &min_index);
		i += 1;
	}
	while (i < dst->length)
	{
		if (dst->rotate_cost[i] > 0)
			cost = (size_t)((dst->length - i) + f_abs(dst->rotate_cost[i]));
		else
			cost = (size_t)(f_max((dst->length - i), dst->rotate_cost[i]));
		update_min_cost(i, cost, &min_cost, &min_index);
		i += 1;
	}
	return (min_index);
}
