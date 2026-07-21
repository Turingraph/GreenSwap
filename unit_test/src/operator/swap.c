#include "operator.h"

int	main(void)
{
	size_t			col = 5;
	size_t			score;
	size_t			max_score = 8;
	size_t			i;
	size_t			j;
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
	int			outarr[][5] = {
		{3, 3, 7, 8, 10},
		{8, 3, 3, 10, 17},
		{10, 3, 4, 8, 16},
		{11, 3, 4, 1, 9},
		{7, 3, 17, 0, 14},
		{6, 3, 18, 3, 0},
		{19, 3, 5, 2, 1},
		{2, 31, 13, 16, 10}
	};

	score = 0;
	i = 0;
	while (i < max_score)
	{
		j = 0;
		while (j < 2)
		{
			dst = strarr_to_intarr(strarr[i], col);
			int_list = intarr_to_green_swap(&dst, col);
			if (j % 2 == 0)
			{
				operate_green_swap(&int_list, TARGET_A, ACT_SWAP, act_swap);
				if (compare_intarr_with_list(outarr[i], &(int_list.a), col, true) == true
					&& compare_intarr_with_list(outarr[i], &(int_list.a), col, false) == true)
					score += 1;
			}
			else
			{
				operate_green_swap(&int_list, TARGET_B, ACT_SWAP, act_swap);
				if (compare_intarr_with_list(intarr[i], &(int_list.a), col, true) == true
					&& compare_intarr_with_list(intarr[i], &(int_list.a), col, false) == true)
					score += 1;
			}
			free(dst);
			free_green_swap(&int_list);
		}
		i += 1;
	}
	write_total_score(score, max_score * 2);
}

