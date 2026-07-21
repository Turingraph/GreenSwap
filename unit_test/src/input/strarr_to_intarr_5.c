#include "input.h"

int	main(void)
{
	size_t		col = 5;
	size_t		score;
	size_t		max_score = 8;
	size_t		i;
	int			*dst;
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
		{3, 3, 19, 5, 2},
		{3, 2, 13, 16, 10}
	};

	score = 0;
	i = 0;
	while (i < max_score)
	{
		dst = strarr_to_intarr(strarr[i], col);
		if (compare_intarr(dst, intarr[i], col) == 0)
			score += 1;
		free(dst);
		i += 1;
	}
	write_total_score(score, max_score);
}

