#include"turk_sort.h"

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

// time : O(1)
// space: O(1)
void	update_min_cost(size_t index, size_t cost,
	size_t *min_cost, size_t *min_index)
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
	while (is_turk_cost_valid(dst, i) == true && i <= dst->length / 2)
	{
		cost = (size_t)(i + f_abs(dst->rotate_cost[i]));
		update_min_cost(i, cost, &min_cost, &min_index);
		i += 1;
	}
	while (is_turk_cost_valid(dst, i) == true && i < dst->length)
	{
		cost = (size_t)((dst->length - i) + f_abs(dst->rotate_cost[i]));
		update_min_cost(i, cost, &min_cost, &min_index);
		i += 1;
	}
	return (min_index);
}

// time : O(n)
// space: O(n)
void	double_draw(t_2intlist *src,
			t_turk_costs *turk_cost, int show)
{
	size_t	cheap_trick;

	if (is_2intlist_n_more(src, 3, 0) == true
		&& is_turk_cost_valid(turk_cost, 0) == true)
	{
		cheap_trick = pod_of_greed(turk_cost);
		rotate_2intlist(cheap_trick, src, (const t_turk_costs *)turk_cost, show);
		if (turk_cost->rotate_cost[cheap_trick] >= 0)
			rotate_value(turk_cost->rotate_cost, turk_cost->length,
				turk_cost->rotate_cost[cheap_trick], src->a.length);
		else
			rrotate_value(turk_cost->rotate_cost, turk_cost->length,
				turk_cost->length + turk_cost->rotate_cost[cheap_trick],
				src->a.length);
		rotate_turk_cost(turk_cost, cheap_trick);
		action_push(src, show, E_B);
		shift_arr(turk_cost->target_a, turk_cost->length);
		shift_arr(turk_cost->rotate_cost, turk_cost->length);
		turk_cost->length -= 1;
		pop_turk_cost(src->a.item_1st->value, turk_cost, &(src->b), src->a.length);
		if (src->a.item_1st->next->value < src->a.item_1st->value)
		{
			action_rotate(src, show, E_A);
			reverse_turk_cost(turk_cost, &(src->b), src->a.length);
		}
	}
}

		// if (iii == 1 && turk_cost->rotate_cost[0] == 2 && turk_cost->rotate_cost[1] == 2)
		// {
		// 	turk_cost->rotate_cost[0] = 1;
		// 	turk_cost->rotate_cost[1] = 1;
		// }

			// if (src->b.length == 2)
			// {
			// 	write(1, "turk_cost->rotate_cost[", 24);
			// 	ft_putnbr_fd(cheap_trick, 1, "0123456789", 1);
			// 	write(1, "] = ", 4);
			// 	ft_putnbr_fd(turk_cost->rotate_cost[cheap_trick], 1, "0123456789", 1);
			// 	write(1, "\n", 1);
			// }

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
	{
		turk_cost = first_turk_sort(src, show);
		while (0 < src->b.length)
			double_draw(src, &turk_cost, show);
		epilogue_rotate_action(src, show);
	}
	free_turk_cost(&turk_cost);
}

/*
void	turk_sort(t_2intlist *src, int show, size_t iii)
{
	t_turk_costs	turk_cost;
	size_t			stop;

	turk_cost = load_turk_cost(NULL);
	if (is_2intlist_n_more(src, 3, 0) == false
		&& is_2intlist_n_more(src, 0, 0) == true)
		sort_two(src, show);
	else if (is_2intlist_n_more(src, 3, 0) == true)
	{
		turk_cost = first_turk_sort(src, show);
		stop = 0;
		if (iii == 1)
			stop = 2;
		while (stop < src->b.length)
			double_draw(src, &turk_cost, show, iii);
		if (iii == 1)
		{
			write(1, "turk_cost\n", 11);
			write_intarr(turk_cost.rotate_cost, turk_cost.length);
			write_intarr(turk_cost.target_a, turk_cost.length);
		}
		else
			epilogue_rotate_action(src, show);
	}
	free_turk_cost(&turk_cost);
}
*/
