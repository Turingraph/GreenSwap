#include"turk_sort.h"


int	main(void)
{
	size_t			col = 6;
	size_t			score;
	size_t			max_score = 6;
	size_t			i;
	t_2intlist		intlist;
	t_turk_costs	turk_cost;
	int				intarr[][10] = {
		{64,	42,	95,	21,	31,	60,	19,	11,	54,	74},
		{89,	87,	15,	80,	98,	63,	98,	11,	54,	74},
		{74,	70,	93,	88,	20,	15,	78,	11,	54,	74},
		{21,	13,	17,	79,	90,	73,	57,	11,	54,	74},
		{27,	39,	70,	83,	10,	12,	95,	11,	54,	74},
		{44,	50,	19,	40,	15,	42,	96,	11,	54,	74},
	};
	// int				target_a[][7] = {
	// 	{54,	74,	54,	54,	11,	54,	74},
	// 	{11,	74,	11,	11,	54,	11,	11},
	// 	{11,	54,	54,	11,	11,	74,	74},
	// 	{74,	74,	11,	11,	54,	54,	54},
	// 	{11,	54,	11,	11,	74,	54,	54},
	// 	{11,	54,	54,	54,	54,	54,	54},
	// };
	// int				rotate_cost[][7] = {
	// 	{1,	-1,	1,	1,	0,	1,	-1},
	// 	{0,	-1,	0,	0,	1,	0,	0},
	// 	{0,	1,	1,	0,	0,	-1,	-1},
	// 	{-1,	-1,	0,	0,	1,	1,	1},
	// 	{0,	1,	0,	0,	-1,	1,	1},
	// 	{0,	1,	1,	1,	1,	1,	1},
	// };
	int				target_a[][6] = {
		{74,	54,	54,	11,	54,	74},
		{74,	98,	98,	54,	98,	98},
		{54,	54,	11,	11,	74,	74},
		{74,	11,	11,	54,	54,	54},
		{54,	11,	11,	74,	54,	54},
		{54,	54,	54,	54,	54,	54},
	};
	int				rotate_cost[][6] = {
		{-2,	1,	1,	-1,	1,	-1},
		{-2,	-1,	-1,	1,	-1,	-1},
		{1,	1,	0,	0,	-2,	-2},
		{1,	-2,	-2,	-1,	-1,	-1},
		{1,	0,	0,	-2,	1,	1,},
		{1,	1,	1,	1,	1,	1},
	};


	score = 0;
	i = 0;
	while (i < max_score)
	{
		intlist = load_2intlist(intarr[i], col + 1 + 3);
		turk_cost = first_turk_sort(&intlist, -2);
		write_intarr(turk_cost.target_a, turk_cost.length);
		double_draw(&intlist, &turk_cost, -2);
		write_intarr(turk_cost.target_a, turk_cost.length);
		if (turk_cost.length == intlist.b.length
			&& is_2intarr_same(turk_cost.target_a, target_a[i], turk_cost.length) == true
			&& is_2intarr_same(turk_cost.rotate_cost, rotate_cost[i], turk_cost.length) == true)
			score += 1;
		else
		{
			write(1, ">>> title: ", 12);
			ft_putnbr_fd(i, 1, "0123456789", 1);
			write(1, "\n", 1);
			// write_intlist(intlist.b.item_1st, true);
			write_intarr(turk_cost.target_a, turk_cost.length);
			write_intarr(target_a[i], turk_cost.length);
		}
		free_turk_cost(&turk_cost);
		free_2intlist(&intlist);
		i += 1;
	}
	write_total_score(score, max_score);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/turk_sort/double_draw_1.out
*/
