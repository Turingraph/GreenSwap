#include"turk_sort.h"

int	main(void)
{
	size_t			col = 7;
	size_t			score = 0;
	size_t			max_score = 14;
	size_t			i = 0;
	t_2intlist		intlist;
	int				intarr[][7] = {
		{43,	30,	74	,52,	98,	11	,11,},
		{75,	79,	18	,95,	86,	2	,34,},
		{94,	69,	64	,71,	18,	72	,16,},
		{55,	19,	16	,97,	82,	96	,31,},
		{92,	98,	7	,50,	71,	61	,27,},
		{93,	54,	35	,16,	59,	44	,94,},
		{78,	21,	10	,94,	59,	17	,69,},
		{24,	53,	2	,63,	14,	77	,52,},
		{89,	97,	11	,40,	93,	96	,13,},
		{63,	76,	6	,56,	32,	42	,10,},
		{98,	64,	50	,99,	17,	79	,38,},
		{31,	31,	15	,92,	96,	28,	9,},
		{61,	91,	29	,18,	98,	77	,57,},
		{58,	27,	87	,12,	13,	88	,90,},
	};
	int				*temp_intarr;
	int				*sorted_intarr;
	t_turk_costs	turk_cost;

	while (i < max_score)
	{
		temp_intarr = clone_intarr(intarr[i], col);
		sorted_intarr = merge_sort(temp_intarr, col);
		intlist = load_2intlist(intarr[i], col);
		turk_cost = debug_turk_sort(&intlist, -2, 0);
		if (is_intarr_and_list_same(sorted_intarr, intlist.a.item_1st, col, true) == true)
			score += 1;
		else
		{
			ft_putnbr_fd(i, 1, "0123456789", 1);
			write(1, " is wrong.\n", 12);
			write(1, "partial_progress: ", 19);
			ft_putnbr_fd(intlist.a.length, 1, "0123456789", 1);
			write(1, "\n", 1);
			write_intlist(intlist.a.item_1st, true, "stack_a: ");
			write_intlist(intlist.b.item_1st, true, "stack_b: ");
			write_intarr(turk_cost.target_a, turk_cost.length, "target_a: ");
			write_intarr(turk_cost.rotate_cost, turk_cost.length, "rotate_cost: ");
		}
		free_2intlist(&intlist);
		free(temp_intarr);
		free(sorted_intarr);
		free_turk_cost(&turk_cost);
		i += 1;
	}
	write_total_score(score, max_score);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/turk_sort/turk_sort_07_debug.out
*/
