#include"turk_sort.h"

// time : O(n)
// space: O(n)
void	reset_turk_cost(t_turk_costs *turk_cost, int rotate_effect, int dekmia)
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
			new_target_a = rrotate_arr(turk_cost->target_a,
				turk_cost->length, (size_t)rotate_effect);
			new_rotate_cost = rrotate_arr(turk_cost->rotate_cost,
				turk_cost->length, (size_t)rotate_effect);
		}
		else
		{
			new_target_a = rotate_arr(turk_cost->target_a,
				turk_cost->length, (size_t)rotate_effect);
			new_rotate_cost = rotate_arr(turk_cost->rotate_cost,
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
void	double_draw(t_double_int_list *src, t_turk_costs *turk_cost, int show)
{
	size_t	cheap_trick;

	if (is_both_stack_n_more(src, 3, 1) == true
		&& is_turk_cost_valid(turk_cost, 0) == true)
	{
		cheap_trick = pod_of_greed(turk_cost);
		rotate_green_swap(cheap_trick, src, turk_cost, show);
		write_available_operator(src, E_A, show, E_PUSH);
		operate_green_swap(src, E_A, E_PUSH, act_push);
		if (src->a.item_1st->value > src->a.item_1st->next->value)
		{
			write_available_operator(src, E_A, show, E_ROTATE);
			operate_green_swap(src, E_A, E_ROTATE, act_rotate);
		}
		reset_turk_cost(turk_cost, turk_cost->rotate_cost[cheap_trick], src->a.item_1st->value);
	}
}

// time : O(n)
// space: O(n)
t_turk_costs	first_turk_sort(t_double_int_list *src, int show)
{
	t_turk_costs	dst;
	size_t			i;

	dst = load_turk_cost(NULL);
	if (is_both_stack_n_more(src, 3, 0) == true)
	{
		while (src->a.length > 3)
		{
			write_available_operator(src, E_B, show, E_PUSH);
			operate_green_swap(src, E_B, E_PUSH, act_push);
		}
		sort_three(src, show);
		if (src->b.length == 0)
			return (dst);
		dst = load_turk_cost(src);
	}
	else if (is_both_stack_n_more(src, 2, 0) == true)
		sort_two(&src, show);
	return (dst);
}

// time : O(n^2)
// space: O(n)
void	turk_sort(t_double_int_list *src, int show)
{
	t_turk_costs	turk_cost;

	turk_cost = load_turk_cost(NULL);
	if (is_both_stack_n_more(src, 3, 0) == false
		&& is_both_stack_n_more(src, 0, 0) == true)
		sort_two(src, show);
	else if (is_both_stack_n_more(src, 3, 0) == true)
		turk_cost = first_turk_sort(src, show);
	if (is_both_stack_n_more(src, 3, 0) == true
		&& is_turk_cost_valid(&turk_cost, 0) == true)
	{
		while (src->b.length > 0)
			double_draw(src, &turk_cost, show);
	}
	free_turk_cost(&turk_cost);
}
