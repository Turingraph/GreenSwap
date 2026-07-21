#include "duplicate_check.h"

int	main(void)
{
	size_t		score;
	size_t		max_score = 8;
	size_t		i;
	bool		toumei_answer = true;
	int			intarr[][2] = {
		{8, 10},
		{10, 17},
		{8, 16},
		{1, 9},
		{0, 14},
		{3, 0},
		{5, 2},
		{16, 10}
	};

	score = 0;
	i = 0;
	while (i < max_score)
	{
		if (kagerou_day(intarr[i], 2) == toumei_answer)
			score += 1;
		i += 1;
	}
	write_total_score(score, max_score);
}
