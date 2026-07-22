#include "input.h"

int	main(void)
{
	size_t		col = 5;
	size_t		score;
	size_t		max_score = 8;
	size_t		i;
	int			*dst;
	t_int_list	intlist;
	char			*strarr[][5] = {
		{"13", "32", "07", "80", "10"},
		{"13", "81", "03", "10", "17"},
		{"13", "10", "42", "28", "16"},
		{"13", "11", "42", "21", "9"},
		{"03", "78", "17", "00", "14"},
		{"03", "68", "18", "30", "00"},
		{"03", "38", "19", "50", "20"},
		{"03", "28", "13", "16", "10"}
	};
	int			intarr[][5] = {
		{13, 32, 7, 80, 10},
		{13, 81, 3, 10, 17},
		{13, 10, 42, 28, 16},
		{13, 11, 42, 21, 9},
		{3, 78, 17, 00, 14},
		{3, 68, 18, 30, 0},
		{3, 38, 19, 50, 20},
		{3, 28, 13, 16, 10}
	};

	score = 0;
	i = 0;
	while (i < max_score)
	{
		dst = strarr_to_intarr((const char **)strarr[i], col);
		intlist = intarr_to_intlist(dst, col);
		if (compare_intarr_with_list(intarr[i], intlist.item_1st, col, true) == true
			&& compare_intarr_with_list(intarr[i], intlist.item_last, col, false) == true)
			score += 1;
		else
		{
			write(1, ">>> ", 4);
			ft_putnbr_fd(i, 1, "0123456789", 1);
			write(1, "\n", 1);
		}
		free(dst);
		free_int_list(&intlist);
		i += 1;
	}
	write_total_score(score, max_score);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/input/intarr_to_int_node_5.out
*/
