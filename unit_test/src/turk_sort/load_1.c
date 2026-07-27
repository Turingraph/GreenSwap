#include"turk_sort.h"


int	main(void)
{
	size_t			col = 15;
	size_t			score;
	size_t			max_score = 6;
	size_t			i;
	size_t			j;
	t_2intlist		intlist;
	t_turk_costs	turk_cost;
	bool			check;
	int				intarr[][18] = {
		{64,	98,	12,	10,	73,	56,	39,	40,	53,	42,	95,	21,	31,	60,	19,	11,	54,	74},
		{89,	78,	69,	42,	24,	59,	81,	96,	19,	87,	15,	80,	98,	63,	98,	11,	54,	74},
		{74,	47,	70,	27,	96,	79,	20,	97,	93,	70,	93,	88,	20,	15,	78,	11,	54,	74},
		{21,	34,	71,	59,	61,	41,	72,	80,	36,	13,	17,	79,	90,	73,	57,	11,	54,	74},
		{27,	85,	14,	88,	95,	33,	68,	68,	52,	39,	70,	83,	10,	12,	95,	11,	54,	74},
		{44,	26,	10,	47,	54,	24,	12,	32,	57,	50,	19,	40,	15,	42,	96,	11,	54,	74},
	};
	int				target_a[][15] = {
		{54, 74, 54, 54, 11, 54, 54, 54, 54, 74, 74, 11, 54, 11, 74}, 
		{11, 54, 11, 11, 54, 11, 54, 11, 11, 54, 54, 54, 74, 11, 11}, 
		{11, 54, 54, 11, 11, 74, 11, 11, 54, 11, 11, 54, 74, 54, 74}, 
		{74, 74, 11, 11, 54, 54, 54, 11, 74, 54, 74, 74, 74, 54, 54}, 
		{11, 54, 11, 11, 74, 54, 54, 74, 74, 54, 11, 11, 54, 11, 54}, 
		{11, 54, 54, 54, 54, 54, 74, 54, 54, 54, 54, 54, 11, 54, 54},
	};
	int				rotate_cost[][15] = {
		{1, -1, 1, 1, 0, 1, 1, 1, 1, -1, -1, 0, 1, 0, -1, },
		{0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, -1, 0, 0, },
		{0, 1, 1, 0, 0, -1, 0, 0, 1, 0, 0, 1, -1, 1, -1, },
		{-1, -1, 0, 0, 1, 1, 1, 0, -1, 1, -1, -1, -1, 1, 1, },
		{0, 1, 0, 0, -1, 1, 1, -1, -1, 1, 0, 0, 1, 0, 1, },
		{0, 1, 1, 1, 1, 1, -1, 1, 1, 1, 1, 1, 0, 1, 1,},
	};

	check = false;
	score = 0;
	i = 0;
	while (i < max_score)
	{
		j = 0;
		intlist = load_2intlist(intarr[i], col + 3);
		while (intlist.a.length > 3)
		{
			j += write_available_operator(&intlist, E_A, -2, E_PUSH);
			operate_double_intlist(&intlist, E_A, E_PUSH, NULL);
		}
		turk_cost = load_turk_cost(&intlist);
		if (
			turk_cost.length == intlist.b.length && j == col && intlist.b.length == j
			&& is_2intarr_same(turk_cost.target_a, target_a[i], turk_cost.length) == true)
			check = true;
		// write_intarr(turk_cost.target_a, turk_cost.length);
		// write_intarr(target_a[i], turk_cost.length);
		if (check == true
			|| is_2intarr_same(turk_cost.rotate_cost, rotate_cost[i], turk_cost.length) == true)
			score += 1;
		free_turk_cost(&turk_cost);
		free_2intlist(&intlist);
		i += 1;
	}
	write_total_score(score, max_score);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/turk_sort/load_1.out
*/
