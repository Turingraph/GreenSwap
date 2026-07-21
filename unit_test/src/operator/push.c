#include "operator.h"

int	main(void)
{
	size_t			col = 5;
	size_t			score;
	size_t			max_score = 8;
	size_t			i;
	int				*dst;
	t_green_swap	int_list;
	char			strarr[][5] = {
		{"3", "3", "7", "8", "10"},
		{"3", "8", "3", "10", "17"},
		{"3", "10", "4", "8", "16"},
		{"3", "11", "4", "1", "9"},
		{"3", "7", "17", "0", "14"},
		{"3", "6", "18", "3", "0"},
		{"3", "3", "19", "5", "2"},
		{"3", "2", "13", "16", "10"}
	};
	int			intarr[][5] = {
		{3, 3, 7, 8, 10},
		{3, 8, 3, 10, 17},
		{3, 10, 4, 8, 16},
		{3, 11, 4, 1, 9},
		{3, 7, 17, 0, 14},
		{3, 6, 18, 3, 0},
		{3, 19, 5, 2, 1},
		{31, 2, 13, 16, 10}
	};
	int			outarr_a[][5] = {
		{8, 10},
		{10, 17},
		{ 8, 16},
		{ 1, 9},
		{ 0, 14},
		{ 3, 0},
		{ 2, 1},
		{ 16, 10}
	};
	int			outarr_b[][5] = {
		{3, 3, 7},
		{3, 8, 3},
		{3, 10, 4},
		{3, 11, 4},
		{3, 7, 17},
		{3, 6, 18},
		{3, 19, 5},
		{31, 2, 13}
	};

	score = 0;
	i = 0;
	while (i < max_score)
	{
		dst = strarr_to_intarr(strarr[i], col);
		int_list = intarr_to_green_swap(&dst, col);
		operate_green_swap(&int_list, TARGET_A, ACT_ROTATE, NULL);
		operate_green_swap(&int_list, TARGET_A, ACT_ROTATE, NULL);
		operate_green_swap(&int_list, TARGET_A, ACT_ROTATE, NULL);
		operate_green_swap(&int_list, TARGET_B, ACT_ROTATE, act_rotate);
		operate_green_swap(&int_list, TARGET_B, ACT_ROTATE, act_rotate);
		if (compare_intarr_with_list(outarr_a[i], &(int_list.a), col, true) == true
			&& compare_intarr_with_list(outarr_a[i], &(int_list.a), col, false) == true
			&& compare_intarr_with_list(outarr_b[i], &(int_list.b), col, true) == true
			&& compare_intarr_with_list(outarr_b[i], &(int_list.b), col, false) == true)
			score += 1;
		free(dst);
		free_green_swap(&int_list);
		i += 1;
	}
	write_total_score(score, max_score);
}

