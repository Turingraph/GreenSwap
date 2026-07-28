#include"turk_sort.h"

// time : O(n)
// space: O(n)
void	reset_turk_cost(t_turk_costs *turk_cost, int rotate_effect)
{
	int	*new_target_a;
	int	*new_rotate_cost;

	if (is_turk_cost_valid(turk_cost, 0) == true)
	{
		shift_by1_arr(turk_cost->rotate_cost, turk_cost->length);
		shift_by1_arr(turk_cost->target_a, turk_cost->length);
		turk_cost->length -= 1;
		if (rotate_effect >= 0)
		{
			new_target_a = rotate_arr(turk_cost->target_a,
					turk_cost->length, (size_t)rotate_effect);
			new_rotate_cost = rotate_arr(turk_cost->rotate_cost,
					turk_cost->length, (size_t)rotate_effect);
		}
		else
		{
			new_target_a = rrotate_arr(turk_cost->target_a,
					turk_cost->length, (size_t)rotate_effect);
			new_rotate_cost = rrotate_arr(turk_cost->rotate_cost,
					turk_cost->length, (size_t)rotate_effect);
		}
		free(turk_cost->target_a);
		free(turk_cost->rotate_cost);
		turk_cost->target_a = new_target_a;
		turk_cost->rotate_cost = new_rotate_cost;
		turk_cost->capacity = turk_cost->length;
	}
}

// time : O(n)
// space: O(n)
void	double_draw(t_2intlist *src, t_turk_costs *turk_cost, int show)
{
	size_t	cheap_trick;
	int		rotate_effect;
	int		*new_rotate_arr;
	int		*new_target_arr;
	int		dekmia;

	if (is_2intlist_n_more(src, 3, 0) == true
		&& is_turk_cost_valid(turk_cost, 0) == true)
	{
		cheap_trick = pod_of_greed(turk_cost);
		rotate_effect = turk_cost->rotate_cost[cheap_trick];
		rotate_2intlist(cheap_trick, src, turk_cost, show);
		if (rotate_effect >= 0)
		{
			new_rotate_arr = rrotate_arr(turk_cost->rotate_cost,
					turk_cost->length, (size_t)rotate_effect);
			new_target_arr = rrotate_arr(turk_cost->target_a,
					turk_cost->length, (size_t)rotate_effect);
		}
		else
		{
			new_rotate_arr = rotate_arr(turk_cost->rotate_cost,
					turk_cost->length, (size_t)rotate_effect);
			new_target_arr = rotate_arr(turk_cost->target_a,
					turk_cost->length, (size_t)rotate_effect);
		}
		turk_cost->capacity = turk_cost->length;
		free(turk_cost->rotate_cost);
		free(turk_cost->target_a);
		turk_cost->rotate_cost = new_rotate_arr;
		turk_cost->target_a = new_target_arr;
		write_available_operator(src, E_B, show, E_PUSH);
		operate_double_intlist(src, E_B, E_PUSH, NULL);
		dekmia = src->a.item_1st->value;
		if (src->a.item_1st->next->value >= src->a.item_1st->value)
		{
			write_available_operator(src, E_A, show, E_ROTATE);
			operate_double_intlist(src, E_A, E_ROTATE, act_rotate);
			push_rotate_arr(turk_cost->rotate_cost, turk_cost->length, true);
		}
		else
			push_rotate_arr(turk_cost->rotate_cost, turk_cost->length, false);
		shift_by1_arr(turk_cost->rotate_cost, turk_cost->length);
		shift_by1_arr(turk_cost->target_a, turk_cost->length);
		update_target_a(turk_cost, &(src->b), dekmia);
		turk_cost->length -= 1;
	}
}


































/*
void	double_draw(t_2intlist *src, t_turk_costs *turk_cost, int show)
{
	size_t	cheap_trick;
	int		target_a;
	int		rotate_a;

	if (is_2intlist_n_more(src, 3, 1) == true
		&& is_turk_cost_valid(turk_cost, 0) == true)
	{
		cheap_trick = pod_of_greed(turk_cost);
		rotate_a = turk_cost->rotate_cost[cheap_trick];
		rotate_2intlist(cheap_trick, src, turk_cost, show);
		intarr_mod(turk_cost->rotate_cost, turk_cost->length, rotate_a, src->a.length);
		write_available_operator(src, E_B, show, E_PUSH);
		operate_double_intlist(src, E_B, E_PUSH, NULL);
		target_a = src->a.item_1st->value;
		if (src->a.item_1st->value > src->a.item_1st->next->value)
		{
			write_available_operator(src, E_A, show, E_ROTATE);
			operate_double_intlist(src, E_A, E_ROTATE, act_rotate);
			rotate_a -= 1;
			push_rotate_arr(turk_cost->rotate_cost, turk_cost->length, true);
		}
		else
			push_rotate_arr(turk_cost->rotate_cost, turk_cost->length, false);
		if (rotate_a < (int)(src->a.length / 2) * -1)
			rotate_a = src->a.length / 2 - 1;
		reset_turk_cost(turk_cost, turk_cost->rotate_cost[cheap_trick]);
		update_target_a(turk_cost, &(src->b), target_a);
	}
}
*/

// time : O(n)
// space: O(n)
t_turk_costs	first_turk_sort(t_2intlist *src, int show)
{
	t_turk_costs	dst;

	dst = load_turk_cost(NULL);
	if (is_2intlist_n_more(src, 3, 0) == true)
	{
		while (src->a.length > 3)
		{
			write_available_operator(src, E_A, show, E_PUSH);
			operate_double_intlist(src, E_A, E_PUSH, NULL);
		}
		sort_three(src, show);
		if (src->b.length == 0)
			return (dst);
		dst = load_turk_cost(src);
	}
	else if (is_2intlist_n_more(src, 2, 0) == true)
		sort_two(src, show);
	return (dst);
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

/*
0
0,	1,	2,	3,	4,	5
0,	1,	2,	3,	4,	5
0,	1,	2,	3,	4,	5

+1
1,	2,	3,	4,	5,	0
0,	1,	2,	3,	4,	5
5,	0,	1,	2,	3,	4

+2
2,	3,	4,	5,	0,	1
0,	1,	2,	3,	4,	5
4,	5,	0,	1,	2,	3

+3
3,	4,	5,	0,	1,	2
0,	1,	2,	3,	4,	5
3,	4,	5,	0,	1,	2

-2
4,	5,	0,	1,	2,	3
0,	1,	2,	3,	4,	5
2,	3,	4,	5,	0,	1

-1
5,	0,	1,	2,	3,	4
0,	1,	2,	3,	4,	5
1,	2,	3,	4,	5,	0

0,	1,	2,	3,	4,	5
0,	1,	2,	3,	4,	5
0,	1,	2,	3,	4,	5
*/
