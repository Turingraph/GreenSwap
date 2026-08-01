#include"turk_sort.h"

// time : O(n)
// space: O(1)
int	single_rotate_1st(size_t target_b, t_2intlist *dst,
	const t_turk_costs *turk_cost, int show)
{
	size_t	i;
	int		cost;

	cost = 0;
	i = 0;
	if (dst != NULL && is_turk_cost_valid(turk_cost, target_b) == true)
	{
		while (i < target_b)
		{
			action_rotate(dst, show, E_B);
			i += 1;
		}
		i = 0;
		while ((int)i < f_abs((int)turk_cost->rotate_cost[target_b]))
		{
			cost += (int)action_rrotate(dst, show, E_A);
			i += 1;
		}
	}
	return (cost);
}

// time : O(n)
// space: O(1)
int	single_rotate_2nd(size_t target_b, t_2intlist *dst,
	const t_turk_costs *turk_cost, int show)
{
	size_t	i;
	int		cost;

	cost = 0;
	i = 0;
	if (dst != NULL && is_turk_cost_valid(turk_cost, target_b) == true)
	{
		while (i < target_b)
		{
			action_rrotate(dst, show, E_B);
			i += 1;
		}
		i = 0;
		while ((int)i < f_abs((int)turk_cost->rotate_cost[target_b]))
		{
			cost += -1 * (int)action_rotate(dst, show, E_A);
			i += 1;
		}
	}
	return (cost);
}

// time : O(n)
// space: O(1)
int	double_rotate_1st(size_t target_b, t_2intlist *dst,
	const t_turk_costs *turk_cost, int show)
{
	size_t	i;
	size_t	j;
	int		cost;

	cost = 0;
	i = 0;
	if (dst != NULL && is_turk_cost_valid(turk_cost, target_b) == true)
	{
		j = 0;
		while (i < target_b && j < (size_t)f_abs((int)turk_cost->rotate_cost[target_b]))
		{
			cost += (int)action_rotate(dst, show, E_AB);
			i += 1;
			j += 1;
		}
		while (i < target_b)
		{
			action_rotate(dst, show, E_B);
			i += 1;
		}
		while (j < (size_t)f_abs((int)turk_cost->rotate_cost[target_b]))
		{
			cost += (int)action_rotate(dst, show, E_A);
			j += 1;
		}
	}
	return (cost);
}

// time : O(n)
// space: O(1)
int	double_rotate_2nd(size_t target_b, t_2intlist *dst,
	const t_turk_costs *turk_cost, int show)
{
	size_t	i;
	size_t	j;
	int		cost;

	cost = 0;
	i = 0;
	if (dst != NULL && is_turk_cost_valid(turk_cost, target_b) == true)
	{
		j = 0;
		while (i < target_b && j < (size_t)(f_abs((int)turk_cost->rotate_cost[target_b])))
		{
			cost += -1 * (int)action_rrotate(dst, show, E_AB);
			i += 1;
			j += 1;
		}
		while (i < target_b)
		{
			action_rrotate(dst, show, E_B);
			i += 1;
		}
		while (j < (size_t)(f_abs((int)turk_cost->rotate_cost[target_b])))
		{
			cost += -1 * (int)action_rrotate(dst, show, E_A);
			j += 1;
		}
	}
	return (cost);
}

// time : O(n)
// space: O(1)
int	rotate_2intlist(size_t target_b, t_2intlist *dst,
	const t_turk_costs *turk_cost, int show)
{
	int	cost;

	cost = 0;
	if (dst != NULL && is_turk_cost_valid(turk_cost, target_b) == true
		&& turk_cost->length == dst->b.length)
	{
		if (target_b <= dst->b.length / 2
			&& turk_cost->rotate_cost[target_b] >= 0)
			cost = double_rotate_1st(target_b, dst, turk_cost, show);
		else if (target_b <= dst->b.length / 2
			&& turk_cost->rotate_cost[target_b] < 0)
			cost = single_rotate_1st(target_b, dst, turk_cost, show);
		else if (target_b > dst->b.length / 2
			&& turk_cost->rotate_cost[target_b] >= 0)
			cost = single_rotate_2nd(target_b, dst, turk_cost, show);
		else if (target_b > dst->b.length / 2
			&& turk_cost->rotate_cost[target_b] < 0)
			cost = double_rotate_2nd(target_b, dst, turk_cost, show);
	}
	return (cost);
}
