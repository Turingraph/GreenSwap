#include"turk_sort.h"

int	main(int len, char **str)
{
	size_t			col = 100;
	t_2intlist		intlist;
	int				intarr[] = {
		86,	16,	63,	95,	54,	91,	41,	48,	8,	24,	94,	26,	22,	30,	29,	73,	77,	47,	40,	70,	92,	53,	97,	87,	34,	74,	83,	18,	59,	36,	37,	75,	27,	56,	76,	62,	93,	5,	25,	71,	12,	96,	60,	64,	13,	66,	72,	11,	82,	98,	50,	65,	80,	33,	23,	10,	85,	81,	14,	68,	78,	43,	51,	44,	46,	69,	19,	99,	61,	52,	35,	3,	32,	31,	2,	20,	90,	39,	1,	88,	9,	6,	0,	57,	45,	7,	15,	67,	28,	84,	21,	38,	79,	17,	89,	58,	55,	4,	49,	42,	};
	int				*temp_intarr;
	int				*sorted_intarr;
	t_turk_costs	turk_cost;
	int				stop;
	bool			is_int;

	stop = 0;
	if (len > 1)
	{
		is_int = true;
		stop = f_atoi(str[1], &is_int, "0123456789", 0);
		if (is_int == false)
			stop = 0;
	}
	temp_intarr = clone_intarr(intarr, col);
	sorted_intarr = merge_sort(temp_intarr, col);
	intlist = load_2intlist(intarr, col);
	turk_cost = debug_turk_sort(&intlist, 1, (size_t)stop);
	if (is_intarr_and_list_same(sorted_intarr, intlist.a.item_1st, col, true) == true)
		write(1, "Correct\n", 9);
	else
	{
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
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/turk_sort/turk_sort_100_00.out | wc -l
*/
