#include"turk_sort.h"

int	main(void)
{
	size_t		col = 2;
	size_t		score;
	size_t		max_score = 6;
	size_t		i;
	t_2intlist	dst;
	int			intarr[][2] = {
		{21,	34},
		{64,	98},
		{89,	78},
		{74,	47},
		{27,	85},
		{44,	26},
	};
	int			outarr[][2] = {
		{21,	34},
		{64,	98},
		{78,	89},
		{47,	74},
		{27,	85},
		{26,	44},
	};

	score = 0;
	i = 0;
	while (i < max_score)
	{
		dst = load_2intlist(intarr[i], col);
		sort_two(&dst, 1);
		// write_intlist(dst.a.item_1st, true);
		if (is_intlist_sort(dst.a.item_1st, 1, 0) == true
			&& is_intarr_and_list_same(outarr[i], dst.a.item_last, col, false) == true
			&& is_intarr_and_list_same(outarr[i], dst.a.item_1st, col, true) == true)
			score += 1;
		free_2intlist(&dst);
		i += 1;
	}
	write_total_score(score, max_score);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/turk_sort/sort_two.out
*/
