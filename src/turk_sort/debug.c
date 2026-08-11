/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 11:53:35 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/11 12:43:16 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "turk_sort.h"

/*
// time : O(n)
// space: O(n)
void	debug_double_draw(t_2intlist *src,
			t_turk_costs *turk_cost, int show, size_t iii)
{
	size_t	cheap_trick;

	if (is_2intlist_n_more(src, 3, 0) == true
		&& is_turk_cost_valid(turk_cost, 0) == true)
	{
		cheap_trick = pod_of_greed(turk_cost);
		if (src->b.length == iii)
		{
			write(1, "\nBefore Rotate\n", 16);
			write(1, "turk_cost->rotate_cost[", 24);
			ft_putnbr_fd((int)cheap_trick, 1, "0123456789", 1);
			write(1, "] = ", 4);
			ft_putnbr_fd(turk_cost->rotate_cost[cheap_trick],
					1, "0123456789", 1);
			write(1, "\n", 1);
			write_intlist(src->a.item_1st, true, "a.item: ");
			write_intlist(src->b.item_1st, true, "b.item: ");
			write_intarr(turk_cost->target_a, turk_cost->length, "target: ");
			write_intarr(turk_cost->rotate_cost, turk_cost->length, "rotate: ");
		}
		rotate_2intlist(cheap_trick, src, turk_cost, show);
		if (turk_cost->rotate_cost[cheap_trick] >= 0)
		{
			rotate_value(turk_cost->rotate_cost, turk_cost->length,
				turk_cost->rotate_cost[cheap_trick], src->a.length);
		}
		else
		{
			// if (src->b.length == iii)
			// 	write(1, "rrotate_value\n", 15);
			rrotate_value(turk_cost->rotate_cost, turk_cost->length,
				f_abs(turk_cost->rotate_cost[cheap_trick]), src->a.length);
		}
			// write_intlist(src->a.item_1st, true, "a.item: ");
			// write_intarr(turk_cost->rotate_cost,
			// 		turk_cost->length, ">>> 01 : ");
		rotate_turk_cost(turk_cost, cheap_trick);
		if (src->b.length == iii)
		{
			write(1, "\nBefore Push\n", 14);
			write_intlist(src->a.item_1st, true, "a.item: ");
			write_intlist(src->b.item_1st, true, "b.item: ");
			write_intarr(turk_cost->target_a, turk_cost->length, "target: ");
			write_intarr(turk_cost->rotate_cost, turk_cost->length, "rotate: ");
		}
		action_push(src, show, E_B);
		shift_arr(turk_cost->target_a, turk_cost->length);
		shift_arr(turk_cost->rotate_cost, turk_cost->length);
		turk_cost->length -= 1;
		pop_turk_cost(src->a.item_1st->value,
			turk_cost, &(src->b), src->a.length);
		if (src->b.length == iii - 1)
		{
			write(1, "\nAfter Push\n", 13);
			write_intlist(src->a.item_1st, true, "a.item: ");
			write_intlist(src->b.item_1st, true, "b.item: ");
			write_intarr(turk_cost->target_a, turk_cost->length, "target: ");
			write_intarr(turk_cost->rotate_cost, turk_cost->length, "rotate: ");
		}
		if (src->a.item_1st->next->value < src->a.item_1st->value)
			reverse_turk_cost(turk_cost, &(src->b), src->a.length);
		if (src->a.item_1st->next->value < src->a.item_1st->value)
			action_rotate(src, show, E_A);
		if (src->b.length == iii - 1)
		{
			write(1, "\nWhy -4 ?\n", 11);
			write_intlist(src->a.item_1st, true, "a.item: ");
			write_intlist(src->b.item_1st, true, "b.item: ");
			write_intarr(turk_cost->target_a, turk_cost->length, "target: ");
			write_intarr(turk_cost->rotate_cost, turk_cost->length, "rotate: ");
		}
	}
}
*/

// time : O(n^2)
// space: O(n)
t_turk_costs	debug_turk_sort(t_2intlist *src, int show, size_t stop)
{
	t_turk_costs	turk_cost;

	turk_cost = load_turk_cost(NULL);
	if (is_2intlist_n_more(src, 3, 0) == false
		&& is_2intlist_n_more(src, 0, 0) == true)
		sort_two(src, show);
	else if (is_2intlist_n_more(src, 3, 0) == true)
	{
		turk_cost = first_turk_sort(src, show);
		while (stop < src->b.length
			&& is_intlist_sort(src->a.item_1st, 1, 1) == true)
			double_draw(src, &turk_cost, show);
		if (is_intlist_sort(src->a.item_1st, 1, 1) == true)
			epilogue_rotate_action(src, show);
	}
	return (turk_cost);
}
