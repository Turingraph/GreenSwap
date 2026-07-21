#include "input.h"

int	main(void)
{
	size_t		col = 1;
	size_t		score;
	size_t		max_score = 8;
	size_t		i;
	int			*dst;
	t_chapter	*intlist;
	char			strarr[][1] = {
		{"10"},
		{ "17"},
		{ "16"},
		{ "9"},
		{ "14"},
		{ "0"},
		{ "2"},
		{"10"}
	};
	int			intarr[][1] = {
		{10},
		{17},
		{16},
		{9},
		{14},
		{0},
		{2},
		{ 10}
	};

	score = 0;
	i = 0;
	while (i < max_score)
	{
		dst = strarr_to_intarr(strarr[i], col);
		intlist = intarr_to_chapter(dst, col);
		if (compare_intarr_with_list(intarr[i], intlist, col, true) == true
			&& compare_intarr_with_list(intarr[i], intlist, col, false) == true)
			score += 1;
		free(dst);
		memento_mori(intlist);
		i += 1;
	}
	write_total_score(score, max_score);
}
