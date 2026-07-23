#include "operator.h"

int	main(void)
{
	size_t			col = 5;
	size_t			score;
	size_t			max_score = 8;
	size_t			i;
	int				*dst;
	t_green_swap	int_list;
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
	int			intarr[][5] = {
		{10, 13, 32, 07, 80},
		{17, 13, 82, 03, 10},
		{16, 13, 10, 42, 28},
		{9, 13, 11, 42, 21},
		{14, 3, 78, 17, 00},
		{00, 3, 68, 18, 30},
		{20, 3, 38, 19, 50},
		{10, 3, 28, 13, 16}
	};

	score = 0;
	i = 0;
	while (i < max_score)
	{
		dst = strarr_to_intarr((const char **)strarr[i], col);
		int_list = intarr_to_green_swap(dst, col);
		operate_green_swap(&int_list, TARGET_A, E_ROTATE, act_rrotate);
		if ((int_list.b).length == 0
			&& compare_intarr_with_list(intarr[i], int_list.a.item_1st, col, true) == true
			&& compare_intarr_with_list(intarr[i], int_list.a.item_last, col, false) == true)
			score += 1;
		free(dst);
		free_green_swap(&int_list);
		i += 1;
	}
	write_total_score(score, max_score);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/operator/rrotate.out
*/
