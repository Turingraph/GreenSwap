#include"turk_sort.h"

int	main(void)
{
	size_t			col = 1;
	size_t			score = 0;
	size_t			max_score = 6;
	size_t			i = 0;
	t_2intlist		intlist;
	int				intarr[][1] = {
		{	2},
		{	2},
		{	51},
		{	23},
		{	73},
		{67},
	};
	int				*temp_intarr;
	int				*sorted_intarr;

	while (i < max_score)
	{
		temp_intarr = clone_intarr(intarr[i], col);
		sorted_intarr = merge_sort(temp_intarr, col);
		intlist = load_2intlist(intarr[i], col);
		turk_sort(&intlist, -2);//, i + 80042);
		if (is_intarr_and_list_same(sorted_intarr, intlist.a.item_1st, col, true) == true)
			score += 1;
		else
		{
			ft_putnbr_fd(i, 1, "0123456789", 1);
			write(1, " is wrong.\n", 12);
			write_intlist(intlist.a.item_1st, true, "stack_a: ");
			write_intlist(intlist.b.item_1st, true, "stack_b: ");
            write_intarr(temp_intarr, col, "farr: ");
            write_intarr(sorted_intarr, col, "arr: ");
		}
		free_2intlist(&intlist);
		free(temp_intarr);
		free(sorted_intarr);
		i += 1;
	}
	write_total_score(score, max_score);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/turk_sort/turk_sort_01.out
*/
