#include"turk_sort.h"

// time : O(n)
// space: O(1)
void	pop_turk_cost(int first_item_a, t_turk_costs *turk_cost, t_intlist *stack_b, size_t length_a)
{
	size_t		i;
	t_intnode	*item_b;

	item_b = NULL;
	if (stack_b != NULL)
		item_b = stack_b->item_1st;
	i = 0;
	while (item_b != NULL && is_turk_cost_valid(turk_cost, i))
	{
		if ((item_b->value >= turk_cost->target_a[i] && turk_cost->target_a[i] >= first_item_a)
			|| (item_b->value <= first_item_a && ((item_b->value > turk_cost->target_a[i])
				|| (item_b->value <= turk_cost->target_a[i] && first_item_a < turk_cost->target_a[i]))))
		{
			turk_cost->target_a[i] = first_item_a;
			turk_cost->rotate_cost[i] = 0;
		}
		else if (0 <= turk_cost->rotate_cost[i]
			&& turk_cost->rotate_cost[i] < (int)length_a / 2)
			turk_cost->rotate_cost[i] += 1;
		else if (turk_cost->rotate_cost[i] == (int)length_a / 2)
			turk_cost->rotate_cost[i] *= -1;
		item_b = item_b->next;
		i += 1;
	}
}

// time : O(n)
// space: O(1)
void	reverse_turk_cost(t_turk_costs *turk_cost, t_intlist *stack_b, size_t length_a)
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
		else if ((turk_cost->rotate_cost[i] == -1 * (int)length_a / 2 + 1 && length_a % 2 == 0)
			|| (turk_cost->rotate_cost[i] == -1 * (int)length_a / 2 && length_a % 2 == 1))
			turk_cost->rotate_cost[i] = (int)length_a / 2;
		else
			turk_cost->rotate_cost[i] -= 1;
		item_b = item_b->next;
		i += 1;
	}
}