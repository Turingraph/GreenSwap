/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_int_node_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 12:11:24 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/11 12:11:25 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

int	main(void)
{
	size_t		col = 1;
	size_t		score;
	size_t		max_score = 8;
	size_t		i;
	int			*dst;
	t_intlist	intlist;
	char			*strarr[][1] = {
		{"10"},
		{ "17"},
		{ "16"},
		{ "09"},
		{ "14"},
		{ "00"},
		{ "02"},
		{"10"}
	};
	int			intarr[][1] = {
		{10},
		{17},
		{16},
		{9},
		{14},
		{0},
		{2},
		{ 10}
	};

	score = 0;
	i = 0;
	while (i < max_score)
	{
		dst = strarr_to_intarr((const char **)strarr[i], col);
		intlist = load_intlist(dst, col);
		if (is_intarr_and_list_same(intarr[i], intlist.item_1st, col, true) == true
			&& is_intarr_and_list_same(intarr[i], intlist.item_last, col, false) == true)
			score += 1;
		else
		{
			write(1, ">>> ", 4);
			ft_putnbr_fd(i, 1, "0123456789", 1);
			write(1, "\n", 1);
		}
		free(dst);
		free_intlist(&intlist);
		i += 1;
	}
	write_total_score(score, max_score);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/input/load_int_node_1.out
*/
