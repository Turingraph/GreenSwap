/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 12:21:23 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/11 12:21:24 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"turk_sort.h"

int	main(void)
{
	size_t			col = 2;
	size_t			score = 0;
	size_t			max_score = 6;
	size_t			i = 0;
	t_2intlist		intlist;
	int				intarr[][2] = {
		{29,		2},
		{98,		2},
		{33,		51},
		{95,		23},
		{69,		73},
		{53,	67},
	};
	int				*temp_intarr;
	int				*sorted_intarr;

	while (i < max_score)
	{
		temp_intarr = clone_intarr(intarr[i], col);
		sorted_intarr = merge_sort(temp_intarr, col);
		intlist = load_2intlist(intarr[i], col);
		turk_sort(&intlist, -2);//, i + 80042);
		if (is_intarr_and_list_same(sorted_intarr, intlist.a.item_1st, col, true) == true)
			score += 1;
		else
		{
			ft_putnbr_fd(i, 1, "0123456789", 1);
			write(1, " is wrong.\n", 12);
			write_intlist(intlist.a.item_1st, true, "stack_a: ");
			write_intlist(intlist.b.item_1st, true, "stack_b: ");
		}
		free_2intlist(&intlist);
		free(temp_intarr);
		free(sorted_intarr);
		i += 1;
	}
	write_total_score(score, max_score);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/turk_sort/turk_sort_02.out
*/
