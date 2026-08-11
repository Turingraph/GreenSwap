/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort_06.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 12:22:13 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/11 12:22:14 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"turk_sort.h"

int	main(void)
{
	size_t			col = 6;
	size_t			score = 0;
	size_t			max_score = 8;
	size_t			i = 0;
	t_2intlist		intlist;
	int				intarr[][6] = {
		{0,	3,	1,	5,	4,	2},
		{97,	98,	54, 101,	2,	20},
		{11,	33,	19,	 101, 51,	18},
		{42,	95,	68,	 101, 23,	76},
		{17,	69,	41,	 101, 73,	69},
		{86,	53,	8,	 101, 67,	11},
		{1,	2,	1,	2,	4,	5},
		{1,	2,	3,	6,	5,	4}
	};
	int				*temp_intarr;
	int				*sorted_intarr;
	t_turk_costs	turk_cost;

	while (i < max_score)
	{
		temp_intarr = clone_intarr(intarr[i], col);
		sorted_intarr = merge_sort(temp_intarr, col);
		intlist = load_2intlist(intarr[i], col);
		turk_cost = debug_turk_sort(&intlist, -2, 0);
		if (is_intarr_and_list_same(sorted_intarr, intlist.a.item_1st, col, true) == true)
			score += 1;
		else
		{
			ft_putnbr_fd(i, 1, "0123456789", 1);
			write(1, " is wrong.\n", 12);
			write_intlist(intlist.a.item_1st, true, "stack_a: ");
			write_intlist(intlist.b.item_1st, true, "stack_b: ");
			write_intarr(turk_cost.target_a, turk_cost.length, "target_a: ");
			write_intarr(turk_cost.rotate_cost, turk_cost.length, "rotate_cost: ");
		}
		free_2intlist(&intlist);
		free(temp_intarr);
		free(sorted_intarr);
		free_turk_cost(&turk_cost);
		i += 1;
	}
	write_total_score(score, max_score);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/turk_sort/turk_sort_06.out
*/
