#include"turk_sort.h"


int	main(void)
{
	size_t			col = 18;
	size_t			score = 0;
	size_t			max_score = 6;
	size_t			i = 0;
	t_2intlist		intlist;
	int				intarr[][18] = {
		{64,	98,	12,	10,	73,	56,	39,	40,	53,	42,	95,	21,	31,	60,	19,	11,	54,	74},
		{89,	78,	69,	42,	24,	59,	81,	96,	19,	87,	15,	80,	98,	63,	98,	54,	74, 11},
		{74,	47,	70,	27,	96,	79,	20,	97,	93,	70,	93,	88,	20,	15,	78,	74, 11,	54},
		{21,	34,	71,	59,	61,	41,	72,	80,	36,	13,	17,	79,	90,	73,	57,	11,	74, 54},
		{27,	85,	14,	88,	95,	33,	68,	68,	52,	39,	70,	83,	10,	12,	95,	54,	11,	74},
		{44,	26,	10,	47,	54,	24,	12,	32,	57,	50,	19,	40,	15,	42,	96,	74,	54,	11},
	};
	int				*temp_intarr;
	int				*sorted_intarr;

	while (i < max_score)
	{
		temp_intarr = clone_intarr(intarr[i], col);
		sorted_intarr = merge_sort(temp_intarr, col);
		intlist = load_2intlist(intarr[i], col);
		turk_sort(&intlist, -2);
		if (is_intarr_and_list_same(sorted_intarr, intlist.a.item_1st, col, true) == true)
			score += 1;
		else
		{
			ft_putnbr_fd(i, 1, "0123456789", 1);
			write(1, " is wrong.\n", 12);
			write_intlist(intlist.a.item_1st, true);
			write_intlist(intlist.b.item_1st, true);
		}
		free_2intlist(&intlist);
		free(temp_intarr);
		free(sorted_intarr);
		i += 1;
	}
	write_total_score(score, max_score);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/turk_sort/turk_sort_1.out
*/

/*
12, 56, 73, 98, 
10, 60, 74, 
39, 40, 42, 53, 
11, 19, 21, 31, 54, 95,
*/

/*
42, 53, 
11, 19, 21, 31, 54, 
12, 56, 95, 
73, 98, 
10, 60, 74, 
39, 40, 64
*/
