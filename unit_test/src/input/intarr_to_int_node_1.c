#include "input.h"

int	main(void)
{
	size_t		col = 1;
	size_t		score;
	size_t		max_score = 8;
	size_t		i;
	int			*dst;
	t_int_list	intlist;
	char			*strarr[][1] = {
		{"10"},
		{ "17"},
		{ "16"},
		{ "09"},
		{ "14"},
		{ "00"},
		{ "02"},
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
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/input/intarr_to_int_node_1.out
*/
