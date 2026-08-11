#include "input.h"



int	main(void)
{
	size_t		col = 3;
	size_t		score;
	size_t		max_score = 8;
	size_t		i;
	int			*dst;
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
	int			intarr[][5] = {
		{13, 32, 7, 80, 10},
		{13, 82, 3, 10, 17},
		{13, 10, 42, 82, 16},
		{13, 11, 42, 12, 9},
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
		if (is_2intarr_same(dst, intarr[i], col) == true)
			score += 1;
		free(dst);
		i += 1;
	}
	write_total_score(score, max_score);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/input/strarr_to_intarr_5.out
*/
