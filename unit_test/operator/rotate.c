/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 12:19:39 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/11 12:19:40 by phsottat         ###   ########.fr       */
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
		{"13", "11", "42", "21", "09"},
		{"03", "78", "17", "00", "14"},
		{"03", "68", "18", "30", "00"},
		{"03", "38", "19", "50", "20"},
		{"03", "28", "13", "16", "10"}
	};
	// int			intarr[][5] = {
	// 	{32, 07, 80, 10, 13},
	// 	{82, 03, 10, 17, 13},
	// 	{10, 42, 28, 16, 13},
	// 	{11, 42, 21, 9, 13},
	// 	{78, 17, 00, 14, 3},
	// 	{68, 18, 30, 00, 3},
	// 	{38, 19, 50, 20, 3},
	// 	{28, 13, 16, 10, 3}
	// };
	int			intarr[][5] = {
		{07, 80, 10, 13, 32},
		{03, 10, 17, 13, 82},
		{42, 28, 16, 13, 10},
		{42, 21, 9 , 13, 11},
		{17, 00, 14, 3 , 78},
		{18, 30, 00, 3 , 68},
		{19, 50, 20, 3 , 38},
		{13, 16, 10, 3 , 28}
	};


	score = 0;
	i = 0;
	while (i < max_score)
	{
		dst = strarr_to_intarr((const char **)strarr[i], col);
		int_list = load_2intlist(dst, col);
		operate_2intlist(&int_list, E_A, E_ROTATE, act_rotate);
		operate_2intlist(&int_list, E_A, E_ROTATE, act_rotate);
		if ((int_list.b).length == 0
			&& is_intarr_and_list_same(intarr[i], int_list.a.item_1st, col, true) == true
			&& is_intarr_and_list_same(intarr[i], int_list.a.item_last, col, false) == true)
			score += 1;
		free(dst);
		free_2intlist(&int_list);
		i += 1;
	}
	write_total_score(score, max_score);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/operator/rotate.out
*/
