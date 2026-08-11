/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 12:20:59 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/11 12:21:00 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"turk_sort.h"

int	main(void)
{
	size_t		col = 3;
	size_t		score;
	size_t		max_score = 6;
	size_t		i;
	t_2intlist	dst;
	int			intarr[][15] = {
		{21,	34,	71},
		{64,	98,	12},
		{89,	78,	69},
		{74,	47,	70},
		{27,	85,	14},
		{44,	26,	10},
	};
	int			outarr[][15] = {
		{21,	34,	71},
		{12,	64,	98},
		{69,	78,	89},
		{47,	70,	74},
		{14,	27,	85},
		{10,	26,	44},
	};

	score = 0;
	i = 0;
	while (i < max_score)
	{
		dst = load_2intlist(intarr[i], col);
		sort_three(&dst, 1);
		if (is_intlist_sort(dst.a.item_1st, 1, 0) == true
			&& is_intarr_and_list_same(outarr[i], dst.a.item_last, col, false) == true
			&& is_intarr_and_list_same(outarr[i], dst.a.item_1st, col, true) == true)
			score += 1;
		free_2intlist(&dst);
		i += 1;
	}
	write_total_score(score, max_score);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/turk_sort/sort_three.out
*/
