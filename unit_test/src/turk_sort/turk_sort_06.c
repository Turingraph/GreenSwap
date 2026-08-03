#include"turk_sort.h"

/*
Fix turk_sort_06.c
*/

int	main(void)
{
	size_t			col = 6;
	size_t			score = 0;
	size_t			max_score = 6;
	size_t			i = 0;
	t_2intlist		intlist;
	int				intarr[][6] = {
		{0,	3,	1,	5,	4,	2},
		{97,	98,	54, 101,	2,	20},
		{11,	33,	19,	 101, 51,	18},
		{42,	95,	68,	 101, 23,	76},
		{17,	69,	41,	 101, 73,	69},
		{86,	53,	8,	 101, 67,	11},
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
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/turk_sort/turk_sort_06.out
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/turk_sort/turk_sort_06.out
*/

/*
1
1

// with epilogue_rotate_action
2 is wrong.
>>> 18, 11, 19, 33, 51, 
>>> 
5 is wrong.
>>> 8, 86, 11, 53, 67, 
>>> 

// without epilogue_rotate_action
0 is wrong.
>>> 65, 70, 2, 29, 51, 
>>> 
1 is wrong.
>>> 97, 98, 2, 20, 54, 
>>> 
2 is wrong.
>>> 11, 19, 33, 51, 18, 
>>> 
3 is wrong.
>>> 42, 68, 76, 95, 23, 
>>> 
5 is wrong.
>>> 11, 53, 67, 8, 86, 
>>> 
*/
