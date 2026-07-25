#include"turk_sort.h"

// time : O(1)
// space: O(1)
int	f_abs(int dst)
{
	if (dst >= 0)
		return (dst);
	if (dst == -2147483648)
		return (2147483647);
	return (dst * -1);
}

// time : O(1)
// space: O(1)
int	f_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

// time : O(1)
// space: O(1)
bool	is_turk_cost_valid(t_turk_costs *dst, size_t index)
{
	if (dst == NULL || dst->rotate_cost == NULL
		|| dst->capacity < dst->length || dst->capacity <= index
		|| dst->target_a == NULL || dst->length <= index)
		return (false);
	return (true);	
}

// time : O(1)
// space: O(1)
void	sort_two(t_green_swap *dst, int show)
{
	if (dst != NULL && dst->a.length == 2
		&& dst->a.item_1st != NULL
		&& dst->a.item_1st->future != NULL
		&& dst->a.item_last != NULL)
	{
		if (dst->a.item_1st->moment >= dst->a.item_last->moment)
		{
			write_available_operator(dst, E_A, show, E_SWAP);
			operate_green_swap(dst, E_A, E_SWAP, act_swap);
		}
	}
}

// time : O(1)
// space: O(1)
void	sort_three(t_green_swap *dst, int show)
{
	if (dst != NULL && dst->a.length == 3
		&& dst->a.item_1st != NULL
		&& dst->a.item_1st->future != NULL
		&& dst->a.item_last != NULL)
	{
		if (dst->a.item_last->moment >= dst->a.item_1st->moment
			&& dst->a.item_last->moment >= dst->a.item_1st->future->moment
			&& dst->a.item_1st->moment > dst->a.item_1st->future->moment)
		{
			write_available_operator(dst, E_A, show, E_SWAP);
			operate_green_swap(dst, E_A, E_SWAP, act_swap);
		}
		else if (dst->a.item_1st->moment >= dst->a.item_last->moment
			&& dst->a.item_1st->moment >= dst->a.item_1st->future->moment)
		{
			write_available_operator(dst, E_A, show, E_ROTATE);
			operate_green_swap(dst, E_A, E_ROTATE, act_rotate);
			sort_large_c(dst, show);
		}
		else if (dst->a.item_1st->future->moment >= dst->a.item_last->moment
			&& dst->a.item_1st->future->moment >= dst->a.item_1st->moment)
		{
			write_available_operator(dst, E_A, show, E_RROTATE);
			operate_green_swap(dst, E_A, E_RROTATE, act_rrotate);
			sort_large_c(dst, show);
		}
	}
}
