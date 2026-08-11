/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort_06_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 12:22:04 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/11 12:22:05 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"turk_sort.h"

int	main(void)
{
	size_t			col = 6;
	t_2intlist		intlist;
	int				intarr[] = {97,	98,	54, 101,	2,	20};
	int				*sorted_intarr;
	t_turk_costs	turk_cost;
	int				*temp_intarr;

	temp_intarr = clone_intarr(intarr, col);
	sorted_intarr = merge_sort(temp_intarr, col);
	intlist = load_2intlist(intarr, col);
	turk_cost = debug_turk_sort(&intlist, -2, 0);
	if (is_intarr_and_list_same(sorted_intarr, intlist.a.item_1st, intlist.a.length, true) == true)
		write(1, "Correct\n", 9);
	else
	{
		write_intlist(intlist.a.item_1st, true, "stack_a: ");
		write_intlist(intlist.b.item_1st, true, "stack_b: ");
		write_intarr(turk_cost.target_a, turk_cost.length, "target_a: ");
		write_intarr(turk_cost.rotate_cost, turk_cost.length, "rotate_cost: ");
	}
	free_2intlist(&intlist);
	free(temp_intarr);
	free(sorted_intarr);
	free_turk_cost(&turk_cost);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/turk_sort/turk_sort_06_b.out
*/
