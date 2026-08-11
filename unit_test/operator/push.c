/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 12:19:29 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/11 12:19:30 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operator.h"

int	main(void)
{
	size_t			col = 5;
	size_t			score;
	size_t			max_score = 8;
	size_t			i;
	int				*dst;
	t_2intlist	int_list;
	char			*strarr[][5] = {
		{"13", "32", "07", "80", "10"},
		{"13", "82", "03", "10", "17"},
		{"13", "10", "42", "28", "16"},
		{"13", "11", "42", "21", "9"},
		{"03", "78", "17", "00", "14"},
		{"03", "68", "18", "30", "00"},
		{"03", "38", "19", "50", "20"},
		{"03", "28", "13", "16", "10"}
	};
	int			outarr_a[][5] = {
		{80, 10},
		{10, 17},
		{ 28, 16},
		{ 21, 9},
		{00, 14},
		{30, 0},
		{50, 20},
		{16, 10}
	};
	int			outarr_b[][5] = {
		{13, 7 , 32},
		{13, 3 , 82},
		{13, 42, 10},
		{13, 42, 11},
		{3,  17, 78},
		{3,  18, 68},
		{3,  19, 38},
		{3,  13, 28}
	};

	score = 0;
	i = 0;
	while (i < max_score)
	{
		dst = strarr_to_intarr((const char **)strarr[i], col);
		int_list = load_2intlist(dst, col);
		operate_2intlist(&int_list, E_A, E_PUSH, NULL);
		operate_2intlist(&int_list, E_A, E_PUSH, NULL);
		operate_2intlist(&int_list, E_A, E_PUSH, NULL);
		operate_2intlist(&int_list, E_B, E_ROTATE, act_rotate);
		operate_2intlist(&int_list, E_B, E_ROTATE, act_rotate);
		if (is_intarr_and_list_same(outarr_a[i], int_list.a.item_1st, 2, true) == true
			&& is_intarr_and_list_same(outarr_a[i], int_list.a.item_last, 2, false) == true
			&& is_intarr_and_list_same(outarr_b[i], int_list.b.item_1st, 3, true) == true)
			// && compare_intarr_with_list(outarr_b[i], int_list.b.item_last, 3, false) == true)
			score += 1;
		else
		{
			write(1, ">>> ", 4);
			ft_putnbr_fd(i, 1, "0123456789", 1);
			write(1, "\n", 1);
		}
		free(dst);
		free_2intlist(&int_list);
		i += 1;
	}
	write_total_score(score, max_score);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/operator/push.out
*/
