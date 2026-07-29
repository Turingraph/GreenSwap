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
void	sort_two(t_2intlist *dst, int show)
{
	if (dst != NULL && dst->a.length == 2
		&& dst->a.item_1st != NULL
		&& dst->a.item_1st->next != NULL
		&& dst->a.item_last != NULL)
	{
		if (dst->a.item_1st->value >= dst->a.item_last->value)
			action_swap(dst, show, E_A);
	}
}

// time : O(1)
// space: O(1)
void	sort_three(t_2intlist *dst, int show)
{
	if (dst != NULL && dst->a.length == 3
		&& dst->a.item_1st != NULL
		&& dst->a.item_1st->next != NULL
		&& dst->a.item_last != NULL)
	{
		if (dst->a.item_last->value >= dst->a.item_1st->value
			&& dst->a.item_last->value >= dst->a.item_1st->next->value
			&& dst->a.item_1st->value > dst->a.item_1st->next->value)
			action_swap(dst, show, E_A);
		else if (dst->a.item_1st->value >= dst->a.item_last->value
			&& dst->a.item_1st->value >= dst->a.item_1st->next->value)
		{
			action_rotate(dst, show, E_A);
			sort_three(dst, show);
		}
		else if (dst->a.item_1st->next->value >= dst->a.item_last->value
			&& dst->a.item_1st->next->value >= dst->a.item_1st->value)
		{
			action_rrotate(dst, show, E_A);
			sort_three(dst, show);
		}
	}
}
