#include"turk_sort.h"

// time : O(n)
// space: O(1)
void	update_target_a(t_turk_costs *turk_cost, t_intlist *list_b, int target_a)
{
	size_t		i;
	t_intnode	*item;

	item = NULL;
	if (list_b != NULL)
		item = list_b->item_1st;
	i = 0;
	while (is_turk_cost_valid(turk_cost, i) == true && item != NULL)
	{
		if ((target_a >= item->value && (target_a < turk_cost->target_a[i]
				|| turk_cost->target_a[i] <= item->value))
			|| (target_a <= turk_cost->target_a[i]
				&& turk_cost->target_a[i] <= item->value))
		{
			turk_cost->rotate_cost[i] = 0;
			turk_cost->target_a[i] = target_a;
		}
		item = item->next;
		i += 1;
	}
}

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

// time : O(n)
// space: O(n)
void	rotate_turk_cost(t_turk_costs *dst, size_t rotate_b, size_t rotate_a)
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
		rrotate_value(dst->rotate_cost, dst->length, rotate_a);
	}
}

// time : O(n)
// space: O(1)
void	pop_turk(t_turk_costs *dst, bool reverse, size_t length_a)
{
	size_t	i;

	if (is_turk_cost_valid(dst, 0) == true)
	{
		i = 0;
		while (i < dst->length)
		{
			if (reverse == false && length_a % 2 == 1
				&& dst->rotate_cost[i] == (int)(length_a / 2))
				dst->rotate_cost[i] *= -1;
			else if (reverse == false && dst->rotate_cost[i] >= 0)
				dst->rotate_cost[i] += 1;
			else if (reverse == true && length_a % 2 == 1
				&& dst->rotate_cost[i] == -1 * (int)(length_a / 2))
				dst->rotate_cost[i] *= -1;
			else if (reverse == true && dst->rotate_cost[i] < 0)
				dst->rotate_cost[i] -= 1;
			i += 1;
		}
		shift_arr(dst->target_a, dst->length);
		shift_arr(dst->rotate_cost, dst->length);
		dst->length -= 1;
	}
}

// time : O(n)
// space: O(n)
void	double_draw(t_2intlist *src, t_turk_costs *turk_cost, int show)
{
	size_t	cheap_trick;
	int		rotate_effect;
	bool	reverse;
	int		dekmia;

	if (is_2intlist_n_more(src, 3, 0) == true
		&& is_turk_cost_valid(turk_cost, 0) == true)
	{
		cheap_trick = pod_of_greed(turk_cost);
		rotate_effect = turk_cost->rotate_cost[cheap_trick];
		rotate_2intlist(cheap_trick, src, turk_cost, show);
		if (rotate_effect < 0)
			rotate_effect += (int)src->a.length;
		rotate_turk_cost(turk_cost, cheap_trick, (size_t)rotate_effect);
		action_push(src, show, E_B);
		reverse = false;
		dekmia = src->a.item_1st->value;
		if (src->a.item_1st->next->value >= src->a.item_1st->value)
		{
			action_rotate(src, show, E_A);
			reverse = true;
		}
		pop_turk(turk_cost, reverse, src->a.length);
		update_target_a(turk_cost, &(src->b), dekmia);
	}
}

// time : O(n^2)
// space: O(n)
void	turk_sort(t_2intlist *src, int show)
{
	t_turk_costs	turk_cost;

	turk_cost = load_turk_cost(NULL);
	if (is_2intlist_n_more(src, 3, 0) == false
		&& is_2intlist_n_more(src, 0, 0) == true)
		sort_two(src, show);
	else if (is_2intlist_n_more(src, 3, 0) == true)
		turk_cost = first_turk_sort(src, show);
	if (is_2intlist_n_more(src, 3, 0) == true
		&& is_turk_cost_valid(&turk_cost, 0) == true)
	{
		while (src->b.length > 0)
			double_draw(src, &turk_cost, show);
	}
	free_turk_cost(&turk_cost);
}
