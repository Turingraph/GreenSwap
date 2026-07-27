#include"turk_sort.h"

// time : O(n)
// space: O(1)
int	single_rotate_1st(size_t target_b, t_double_int_list *dst, t_turk_costs *turk_cost, int show)
{
	size_t	i;
	int		cost;

	cost = 0;
	i = 0;
	if (dst != NULL && is_turk_cost_valid(turk_cost, target_b) == true)
	{
		while (i < target_b)
		{
			write_available_operator(dst, E_B, show, E_RROTATE);
			operate_green_swap(dst, E_B, E_RROTATE, act_rrotate);
			i += 1;
		}
		i = 0;
		while ((int)i < -1 * turk_cost->rotate_cost[target_b])
		{
			cost += (int)write_available_operator(dst, E_A, show, E_ROTATE);
			operate_green_swap(dst, E_A, E_ROTATE, act_rotate);
			i += 1;
		}
	}
	return (cost);
}

// time : O(n)
// space: O(1)
int	single_rotate_2nd(size_t target_b, t_double_int_list *dst, t_turk_costs *turk_cost, int show)
{
	size_t	i;
	int		cost;

	cost = 0;
	i = 0;
	if (dst != NULL && is_turk_cost_valid(turk_cost, target_b) == true)
	{
		while (i < target_b)
		{
			write_available_operator(dst, E_B, show, E_ROTATE);
			operate_green_swap(dst, E_B, E_ROTATE, act_rotate);
			i += 1;
		}
		i = 0;
		while ((int)i < -1 * turk_cost->rotate_cost[target_b])
		{
			cost += -1 * (int)write_available_operator(dst, E_A, show, E_RROTATE);
			operate_green_swap(dst, E_A, E_RROTATE, act_rrotate);
			i += 1;
		}
	}
	return (cost);
}

// time : O(n)
// space: O(1)
int	double_rotate_1st(size_t target_b, t_double_int_list *dst, t_turk_costs *turk_cost, int show)
{
	size_t	i;
	size_t	j;
	int		cost;

	cost = 0;
	i = 0;
	if (dst != NULL && is_turk_cost_valid(turk_cost, target_b) == true)
	{
		j = 0;
		while (i < target_b && j < turk_cost->rotate_cost[target_b])
		{
			cost += (int)write_available_operator(dst, E_AB, show, E_RROTATE);
			operate_green_swap(dst, E_AB, E_RROTATE, act_rrotate);
			i += 1;
			j += 1;
		}
		while (i < target_b)
		{
			write_available_operator(dst, E_B, show, E_RROTATE);
			operate_green_swap(dst, E_B, E_RROTATE, act_rrotate);
			i += 1;
		}
		while (j < turk_cost->rotate_cost[target_b])
		{
			cost += (int)write_available_operator(dst, E_A, show, E_RROTATE);
			operate_green_swap(dst, E_A, E_RROTATE, act_rrotate);
			j += 1;
		}
	}
	return (cost);
}

// time : O(n)
// space: O(1)
int	double_rotate_2nd(size_t target_b, t_double_int_list *dst, t_turk_costs *turk_cost, int show)
{
	size_t	i;
	size_t	j;
	int		cost;

	cost = 0;
	i = 0;
	if (dst != NULL && is_turk_cost_valid(turk_cost, target_b) == true)
	{
		j = 0;
		while (i < target_b && j < turk_cost->rotate_cost[target_b])
		{
			cost += -1 * (int)write_available_operator(dst, E_AB, show, E_ROTATE);
			operate_green_swap(dst, E_AB, E_ROTATE, act_rotate);
			i += 1;
			j += 1;
		}
		while (i < target_b)
		{
			write_available_operator(dst, E_B, show, E_ROTATE);
			operate_green_swap(dst, E_B, E_ROTATE, act_rotate);
			i += 1;
		}
		while (j < turk_cost->rotate_cost[target_b])
		{
			cost += -1 * (int)write_available_operator(dst, E_A, show, E_ROTATE);
			operate_green_swap(dst, E_A, E_ROTATE, act_rotate);
			j += 1;
		}
	}
	return (cost);
}

// time : O(n)
// space: O(1)
int	rotate_green_swap(size_t target_b, t_double_int_list *dst, t_turk_costs *turk_cost, int show)
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
