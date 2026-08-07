#include"turk_sort.h"

// time : O(n)
// space: O(n)
void	rotate_turk_cost(t_turk_costs *dst, size_t rotate_b)
{
	int	*temp;

	if (is_turk_cost_valid(dst, 0) == true)
	{
		temp = rrotate_arr(dst->rotate_cost, dst->length, rotate_b);
		free(dst->rotate_cost);
		dst->rotate_cost = temp;
		temp = rrotate_arr(dst->target_a, dst->length, rotate_b);
		free(dst->target_a);
		dst->target_a = temp;
	}
}

// time : O(1)
// space: O(1)
bool	change_target_a(int value_b, int prev_target_a, int first_item_a)
{
	bool	smallest;
	bool	smallest_larger;
	bool	first_larger;

	smallest = false;
	smallest_larger = false;
	first_larger = false;
	if (value_b > prev_target_a && value_b <= first_item_a)
		first_larger = true;
	if (value_b <= first_item_a && first_item_a <= prev_target_a)
		smallest_larger = true;
	if (value_b > prev_target_a && prev_target_a >= first_item_a)
		smallest = true;
	if (first_larger == true || smallest_larger == true
		|| smallest == true)
		return (true);
	return (false);
}

// time : O(n)
// space: O(1)
void	pop_turk_cost(int first_item_a, t_turk_costs *turk_cost,
	t_intlist *stack_b, size_t length_a)
{
	size_t		i;
	t_intnode	*item_b;

	item_b = NULL;
	if (stack_b != NULL)
		item_b = stack_b->item_1st;
	i = 0;
	while (item_b != NULL && is_turk_cost_valid(turk_cost, i))
	{
		if (change_target_a(item_b->value,
				turk_cost->target_a[i], first_item_a) == true)
		{
			turk_cost->target_a[i] = first_item_a;
			turk_cost->rotate_cost[i] = 0;
		}
		else if (0 <= turk_cost->rotate_cost[i]
			&& turk_cost->rotate_cost[i] < (int)length_a / 2)
			turk_cost->rotate_cost[i] += 1;
		else if (length_a % 2 == 1
			&& turk_cost->rotate_cost[i] == (int)length_a / 2)
			turk_cost->rotate_cost[i] *= -1;
		item_b = item_b->next;
		i += 1;
	}
}

// time : O(n)
// space: O(1)
void	reverse_turk_cost(t_turk_costs *turk_cost,
	const t_intlist *stack_b, size_t length_a)
{
	size_t		i;
	t_intnode	*item_b;

	item_b = NULL;
	if (stack_b != NULL)
		item_b = stack_b->item_1st;
	i = 0;
	while (item_b != NULL && is_turk_cost_valid(turk_cost, i))
	{
		if (turk_cost->rotate_cost[i] == 0)
			turk_cost->rotate_cost[i] = -1;
		else if ((turk_cost->rotate_cost[i] == -1 * (int)length_a / 2 + 1
				&& length_a % 2 == 0)
			|| (turk_cost->rotate_cost[i] == -1 * (int)length_a / 2
				&& length_a % 2 == 1))
			turk_cost->rotate_cost[i] = (int)length_a / 2;
		else
			turk_cost->rotate_cost[i] -= 1;
		item_b = item_b->next;
		i += 1;
	}
}
