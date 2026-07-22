#include "operator.h"

	// int			intarr[][5] = {
	// 	{13, 32, 7, 80, 10},
	// 	{13, 82, 3, 10, 17},
	// 	{13, 10, 42, 82, 16},
	// 	{13, 11, 42, 12, 9},
	// 	{3, 78, 17, 00, 14},
	// 	{3, 68, 18, 30, 0},
	// 	{3, 38, 19, 50, 20},
	// 	{3, 28, 13, 16, 10}
	// };

int	main(void)
{
	size_t			col = 5;
	size_t			score;
	size_t			max_score = 8;
	size_t			i;
	int				*dst;
	t_green_swap	int_list;
	char			strarr[][5][3] = {
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
		{ 82, 16},
		{ 12, 9},
		{00, 14},
		{30, 0},
		{50, 20},
		{16, 10}
	};
	int			outarr_b[][5] = {
		{13, 32, 7},
		{13, 82, 3},
		{13, 10, 42},
		{13, 11, 42},
		{3, 78, 17},
		{3, 68, 18 },
		{3, 38, 19},
		{3, 28, 13 }
	};

	score = 0;
	i = 0;
	while (i < max_score)
	{
		dst = strarr_to_intarr((const char **)strarr[i], col);
		int_list = intarr_to_green_swap(dst, col);
		operate_green_swap(&int_list, TARGET_A, E_ROTATE, NULL);
		operate_green_swap(&int_list, TARGET_A, E_ROTATE, NULL);
		operate_green_swap(&int_list, TARGET_A, E_ROTATE, NULL);
		operate_green_swap(&int_list, TARGET_B, E_ROTATE, act_rotate);
		operate_green_swap(&int_list, TARGET_B, E_ROTATE, act_rotate);
		if (compare_intarr_with_list(outarr_a[i], int_list.a.item_1st, col, true) == true
			&& compare_intarr_with_list(outarr_a[i], int_list.a.item_1st, col, false) == true
			&& compare_intarr_with_list(outarr_b[i], int_list.b.item_1st, col, true) == true
			&& compare_intarr_with_list(outarr_b[i], int_list.b.item_1st, col, false) == true)
			score += 1;
		free(dst);
		free_green_swap(&int_list);
		i += 1;
	}
	write_total_score(score, max_score);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/operator/push.out
*/
