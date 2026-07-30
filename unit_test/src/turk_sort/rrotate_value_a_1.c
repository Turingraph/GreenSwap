#include"turk_sort.h"

int	main(void)
{
	size_t		col = 6;
	size_t		score;
	size_t		max_score = 6;
	size_t		i;
	int			*dst;
	int			intarr[] = {0,	1,	2,	3,	-2,	-1};
	int			outarr[][6] = {
		{0,	1,	2,	3,	-2,	-1},
		{-1,	0,	1,	2,	3,	-2},
		{-2,	-1,	0,	1,	2,	3},
		{3,	-2,	-1,	0,	1,	2},
		{2,	3,	-2,	-1,	0,	1},
		{1,	2,	3,	-2,	-1,	0},
	};

	score = 0;
	i = 0;
	while (i < max_score)
	{
		dst = rotate_arr(intarr, col, 0);
		rotate_value(dst, col, i, col);
		if (is_2intarr_same(dst, outarr[i], col) == true)
			score += 1;
		write_intarr(dst, col);
		free(dst);
		i += 1;
	}
	write_total_score(score, max_score);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/turk_sort/rrotate_value_a_1.out
*/
