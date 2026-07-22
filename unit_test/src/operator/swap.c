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
		{32, 13, 07, 80, 10},
		{82, 13, 03, 10, 17},
		{10, 13, 42, 28, 16},
		{11, 13, 42, 21, 9},
		{78, 3, 17, 00, 14},
		{68, 3, 18, 30, 00},
		{38, 3, 19, 50, 20},
		{28, 3, 13, 16, 10}
	};

	score = 0;
	i = 0;
	while (i < max_score)
	{
		j = 0;
		while (j < 2)
		{
			dst = strarr_to_intarr((const char **)strarr[i], col);
			int_list = intarr_to_green_swap(dst, col);
			if (j % 2 == 0)
			{
				write_future(int_list.a.item_1st, true);
				operate_green_swap(&int_list, TARGET_A, E_SWAP, act_swap);
				if (compare_intarr_with_list(intarr[i], int_list.a.item_1st, col, true) == true
					&& compare_intarr_with_list(intarr[i], int_list.a.item_1st, col, false) == true)
					score += 1;
			}
			else
			{
				operate_green_swap(&int_list, TARGET_B, E_SWAP, act_swap);
				if ((int_list.b).length == 0
					&& compare_intarr_with_list(intarr[i], int_list.a.item_1st, col, true) == true
					&& compare_intarr_with_list(intarr[i], int_list.a.item_1st, col, false) == true)
					score += 1;
			}
			free(dst);
			free_green_swap(&int_list);
			j += 1;
		}
		i += 1;
	}
	write_total_score(score, max_score * 2);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/operator/swap.out
*/
