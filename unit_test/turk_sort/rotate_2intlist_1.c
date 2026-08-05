#include"turk_sort.h"


int	main(void)
{
	size_t			col = 6;
	size_t			score;
	size_t			score_0;
	size_t			score_1;
	size_t			score_2;
	size_t			score_3;
	size_t			score_4;
	size_t			max_score = 6;
	size_t			i;
	size_t			cheap_trick;
	t_2intlist		intlist;
	// int				rotate_effect;
	bool			check_0;
	t_turk_costs	turk_cost;
	int				intarr[][10] = {
		{64,	42,	95,	21,	31,	60,	19,	11,	54,	74},
		{89,	87,	15,	80,	98,	63,	98,	11,	54,	74},
		{74,	70,	93,	88,	20,	15,	78,	11,	54,	74},
		{21,	13,	17,	79,	90,	73,	57,	11,	54,	74},
		{27,	39,	70,	83,	10,	12,	95,	11,	54,	74},
		{44,	50,	19,	40,	15,	42,	96,	11,	54,	74},
	};
	int				stack_a_0[3] = {11, 54, 74};
	int				stack_b_0[][7] = {
		{19,	60,	31,	21,	95,	42,	64},
		{98,	63,	98,	80,	15,	87,	89},
		{78,	15,	20,	88,	93,	70,	74},
		{57,	73,	90,	79,	17,	13,	21},
		{95,	12,	10,	83,	70,	39,	27},
		{96,	42,	15,	40,	19,	50,	44},
	};
	int				target_0[][7] = {
		{54,	74,	54,	54,	11,	54,	74},
		{11,	74,	11,	11,	54,	11,	11},
		{11,	54,	54,	11,	11,	74,	74},
		{74,	74,	11,	11,	54,	54,	54},
		{11,	54,	11,	11,	74,	54,	54},
		{11,	54,	54,	54,	54,	54,	54},
	};
	int				rotate_cost_0[][7] = {
		{1,	-1,	1,	1,	0,	1,	-1},
		{0,	-1,	0,	0,	1,	0,	0},
		{0,	1,	1,	0,	0,	-1,	-1},
		{-1,	-1,	0,	0,	1,	1,	1},
		{0,	1,	0,	0,	-1,	1,	1},
		{0,	1,	1,	1,	1,	1,	1},
	};
	// size_t			pod_or_greed_0 = 0;
	bool			check_1;
	int				stack_a_1[][3] = {
		{54,	74,	11},
		{11,	54,	74},
		{11,	54,	74},
		{74,	11,	54},
		{11,	54,	74},
		{11,	54,	74},
	};
	int				stack_b_1[][7] = {
		{19,	60,	31,	21,	95,	42,	64},
		{98,	63,	98,	80,	15,	87,	89},
		{78,	15,	20,	88,	93,	70,	74},
		{57,	73,	90,	79,	17,	13,	21},
		{95,	12,	10,	83,	70,	39,	27},
		{96,	42,	15,	40,	19,	50,	44},
	};
	int				target_1[][7] = {
		{54,	74,	54,	54,	11,	54,	74},
		{11,	74,	11,	11,	54,	11,	11},
		{11,	54,	54,	11,	11,	74,	74},
		{74,	74,	11,	11,	54,	54,	54},
		{11,	54,	11,	11,	74,	54,	54},
		{11,	54,	54,	54,	54,	54,	54},
	};
	int				rotate_cost_1[][7] = {
		{0,	1,	0,	0,	-1,	0,	1},
		{0,	-1,	0,	0,	1,	0,	0},
		{0,	1,	1,	0,	0,	-1,	-1},
		{0,	0,	1,	1,	-1,	-1,	-1},
		{0,	1,	0,	0,	-1,	1,	1},
		{0,	1,	1,	1,	1,	1,	1},
	};
	bool			check_2;
	int				stack_a_2[][4] = {
		{19,	54,	74,	11},
		{98,	11,	54,	74},
		{78,	11,	54,	74},
		{57,	74,	11,	54},
		{95,	11,	54,	74},
		{96,	11,	54,	74},
	};
	int				stack_b_2[][6] = {
		{60,	31,	21,	95,	42,	64},
		{63,	98,	80,	15,	87,	89},
		{15,	20,	88,	93,	70,	74},
		{73,	90,	79,	17,	13,	21},
		{12,	10,	83,	70,	39,	27},
		{42,	15,	40,	19,	50,	44},
	};
	int				target_2[][6] = {
		{74,	54,	54,	11,	54,	74},
		{74,	98,	98,	54,	98,	98},
		{54,	54,	11,	11,	74,	74},
		{74,	11,	11,	54,	54,	54},
		{54,	11,	95,	74,	54,	54},
		{54,	54,	54,	54,	54,	54},
	};
	int				rotate_cost_2[][6] = {
		{2,	1,	1,	-1,	1,	2},
		{-1,	0,	0,	2,	0,	0},
		{2,	2,	1,	1,	-1,	-1},
		{1,	2,	2,	-1,	-1,	-1},
		{2,	1,	0,	-1,	2,	2},
		{2,	2,	2,	2,	2,	2},
	};
	bool			check_3;
	// bool			reverse_3[] = {
	// 	false,
	// 	true,
	// 	true,
	// 	false,
	// 	true,
	// 	true
	// };
	int				stack_a_3[][4] = {
		{19,	54,	74,	11},
		{11,	54,	74,	98},
		{11,	54,	74,	78},
		{57,	74,	11,	54},
		{11,	54,	74,	95},
		{11,	54,	74,	96},
	};
	int				stack_b_3[][6] = {
		{60,	31,	21,	95,	42,	64},
		{63,	98,	80,	15,	87,	89},
		{15,	20,	88,	93,	70,	74},
		{73,	90,	79,	17,	13,	21},
		{12,	10,	83,	70,	39,	27},
		{42,	15,	40,	19,	50,	44},
	};
	int				target_3[][6] = {
		{74,	54,	54,	11,	54,	74},
		{74,	98,	98,	54,	98,	98},
		{54,	54,	11,	11,	74,	74},
		{74,	11,	11,	54,	54,	54},
		{54,	11,	95,	74,	54,	54},
		{54,	54,	54,	54,	54,	54},
	};
	int				rotate_cost_3[][6] = {
		{2,	1,	1,	-1,	1,	2},
		{2,	-1,	-1,	1,	-1,	-1},
		{1,	1,	0,	0,	2,	2},
		{1,	2,	2,	-1,	-1,	-1},
		{1,	0,	-1,	2,	1,	1},
		{1,	1,	1,	1,	1,	1},
	};
	// size_t			pod_or_greed_1 = 0;
	bool			check_4;
	int				stack_a_4[][4] = {
		{74,	11,	19,	54},
		{74,	98,	11,	54},
		{54,	74,	78,	11},
		{74,	11,	54,	57},
		{54,	74,	95,	11},
		{54,	74,	96,	11},
	};
	int				stack_b_4[][6] = {
		{60,	31,	21,	95,	42,	64},
		{63,	98,	80,	15,	87,	89},
		{15,	20,	88,	93,	70,	74},
		{73,	90,	79,	17,	13,	21},
		{12,	10,	83,	70,	39,	27},
		{42,	15,	40,	19,	50,	44},
	};
	int				target_4[][6] = {
		{74,	54,	54,	11,	54,	74},
		{74,	98,	98,	54,	98,	98},
		{54,	54,	11,	11,	74,	74},
		{74,	11,	11,	54,	54,	54},
		{54,	11,	95,	74,	54,	54},
		{54,	54,	54,	54,	54,	54},
	};
	int				rotate_cost_4[][6] = {
		{0,	-1,	-1,	1,	-1,	0},
		{0,	1,	1,	-1,	1,	1},
		{0,	0,	-1,	-1,	1,	1},
		{0,	1,	1,	2,	2,	2},
		{0,	-1,	2,	1,	0,	0},
		{0,	0,	0,	0,	0,	0},
	};
	bool			check_5;
	int				stack_a_5[][5] = {
		{60,	74,	11,	19,	54},
		{63,	74,	98,	11,	54},
		{15,	54,	74,	78,	11},
		{73,	74,	11,	54,	57},
		{12,	54,	74,	95,	11},
		{42,	54,	74,	96,	11},
	};
	int				stack_b_5[][5] = {
		{31,	21,	95,	42,	64},
		{98,	80,	15,	87,	89},
		{20,	88,	93,	70,	74},
		{90,	79,	17,	13,	21},
		{10,	83,	70,	39,	27},
		{15,	40,	19,	50,	44},
	};
	int				target_5[][5] = {
		{54,	54,	11,	54,	74},
		{98,	98,	54,	98,	98},
		{54,	11,	11,	74,	74},
		{11,	11,	54,	54,	54},
		{11,	95,	74,	54,	54},
		{42,	42,	42,	54,	54}
	};
	int				rotate_cost_5[][5] = {
		{-1,	-1,	2,	-1,	1},
		{2,	2,	-1,	2,	2},
		{1,	-1,	-1,	2,	2},
		{2,	2,	-2,	-2,	-2},
		{-1,	-2,	2,	1,	1},
		{0,	0,	0,	1,	1}
	};

	score = 0;
	score_0 = 0;
	score_1 = 0;
	score_2 = 0;
	score_3 = 0;
	score_4 = 0;
	i = 0;
	while (i < max_score)
	{
		check_0 = false;
		check_1 = false;
		check_2 = false;
		check_3 = false;
		check_4 = false;
		check_5 = false;
		intlist = load_2intlist(intarr[i], col + 1 + 3);
		turk_cost = first_turk_sort(&intlist, -2);
		if (turk_cost.length == intlist.b.length
			&& is_intarr_and_list_same(stack_a_0, intlist.a.item_1st, intlist.a.length, true) == true
			&& is_intarr_and_list_same(stack_b_0[i], intlist.b.item_1st, turk_cost.length, true) == true
			&& is_2intarr_same(turk_cost.target_a, target_0[i], turk_cost.length) == true
			&& is_2intarr_same(turk_cost.rotate_cost, rotate_cost_0[i], turk_cost.length) == true)
			check_0 = true;
		cheap_trick = pod_of_greed(&turk_cost);
		rotate_2intlist(cheap_trick, &intlist, (const t_turk_costs *)&turk_cost, -2);
		rotate_turk_cost(&turk_cost, cheap_trick);
		if (turk_cost.rotate_cost[cheap_trick] >= 0)
			rotate_value(turk_cost.rotate_cost, turk_cost.length,
				turk_cost.rotate_cost[cheap_trick], intlist.a.length);
		else
			rotate_value(turk_cost.rotate_cost, turk_cost.length,
				turk_cost.length + turk_cost.rotate_cost[cheap_trick],
				intlist.a.length);
		if (turk_cost.length == intlist.b.length && cheap_trick == 0
			&& is_intarr_and_list_same(stack_a_1[i], intlist.a.item_1st, intlist.a.length, true) == true
			&& is_intarr_and_list_same(stack_b_1[i], intlist.b.item_1st, turk_cost.length, true) == true
			&& is_2intarr_same(turk_cost.target_a, target_1[i], turk_cost.length) == true
			&& is_2intarr_same(turk_cost.rotate_cost, rotate_cost_1[i], turk_cost.length) == true)
			check_1 = true;
		action_push(&intlist, -2, E_B);
		shift_arr(turk_cost.target_a, turk_cost.length);
		shift_arr(turk_cost.rotate_cost, turk_cost.length);
		turk_cost.length -= 1;
		pop_turk_cost(intlist.a.item_1st->value, &turk_cost, &(intlist.b), intlist.a.length);
		if (intlist.a.length == 4 && intlist.b.length == 6 && turk_cost.length == 6
			&& is_intarr_and_list_same(stack_a_2[i], intlist.a.item_1st, 4, true) == true
			&& is_intarr_and_list_same(stack_b_2[i], intlist.b.item_1st, 6, true) == true
			&& is_2intarr_same(turk_cost.target_a, target_2[i], 6) == true
			&& is_2intarr_same(turk_cost.rotate_cost, rotate_cost_2[i], 6) == true)
			check_2 = true;
		if (intlist.a.item_1st->next->value < intlist.a.item_1st->value)
		{
			action_rotate(&intlist, -2, E_A);
			reverse_turk_cost(&turk_cost, &(intlist.b), intlist.a.length);
		}
		if (intlist.a.length == 4 && intlist.b.length == 6 && turk_cost.length == 6
			&& is_intarr_and_list_same(stack_a_3[i], intlist.a.item_1st, 4, true) == true
			&& is_intarr_and_list_same(stack_b_3[i], intlist.b.item_1st, 6, true) == true
			&& is_2intarr_same(turk_cost.target_a, target_3[i], 6) == true
			&& is_2intarr_same(turk_cost.rotate_cost, rotate_cost_3[i], 6) == true)
			check_3 = true;
		// if (i == 0 || i == 1)
		// {
		// 	write(1, "Warning: ", 10);
		// 	ft_putnbr_fd(i, 1, "0123456789", 1);
		// 	write(1, " is wrong.\n", 12);
		// 	write_intlist(intlist.a.item_1st, true);
		// }
		cheap_trick = pod_of_greed(&turk_cost);
		rotate_2intlist(cheap_trick, &intlist, (const t_turk_costs *)&turk_cost, -2);
		rotate_turk_cost(&turk_cost, cheap_trick);
		if (turk_cost.rotate_cost[cheap_trick] >= 0)
			rotate_value(turk_cost.rotate_cost, turk_cost.length,
				turk_cost.rotate_cost[cheap_trick], intlist.a.length);
		else
			rotate_value(turk_cost.rotate_cost, turk_cost.length,
				turk_cost.length + turk_cost.rotate_cost[cheap_trick],
				intlist.a.length);
		if (turk_cost.length == 6
			&& is_intarr_and_list_same(stack_a_4[i], intlist.a.item_1st, 4, true) == true
			&& is_intarr_and_list_same(stack_b_4[i], intlist.b.item_1st, 6, true) == true
			&& is_2intarr_same(turk_cost.target_a, target_4[i], 6) == true
			&& is_2intarr_same(turk_cost.rotate_cost, rotate_cost_4[i], 6) == true)
			check_4 = true;
		action_push(&intlist, -2, E_B);
		shift_arr(turk_cost.target_a, turk_cost.length);
		shift_arr(turk_cost.rotate_cost, turk_cost.length);
		turk_cost.length -= 1;
		pop_turk_cost(intlist.a.item_1st->value, &turk_cost, &(intlist.b), intlist.a.length);
		if (turk_cost.length == 5 && intlist.a.length == 5 && intlist.b.length == 5
			&& is_intarr_and_list_same(stack_a_5[i], intlist.a.item_1st, 5, true) == true
			&& is_intarr_and_list_same(stack_b_5[i], intlist.b.item_1st, 5, true) == true
			&& is_2intarr_same(turk_cost.target_a, target_5[i], 5) == true
			&& is_2intarr_same(turk_cost.rotate_cost, rotate_cost_5[i], 5) == true)
			check_5 = true;
		else
		{
			write(1, "Warning: ", 10);
			ft_putnbr_fd(i, 1, "0123456789", 1);
			write(1, " is wrong.\n", 12);
			// write(1, "cheap_trick = 0 = ", 19);
			// ft_putnbr_fd(cheap_trick, 1, "0123456789", 1);
			// write(1, "\n", 1);
			// write(1, "::: 2 == ", 10);
			// ft_putnbr_fd(rotate_effect, 1, "0123456789", 1);
			// write(1, "\n", 1);
			// ft_putnbr_fd(turk_cost.rotate_cost[cheap_trick], 1, "0123456789", 1);
			// write(1, "\n", 1);
			// write_intarr(turk_cost.target_a, turk_cost.length);
			// write_intarr(target_5[i], turk_cost.length);
			write_intarr(turk_cost.rotate_cost, turk_cost.length, "predict_rotate: ");
			write_intarr(rotate_cost_5[i], turk_cost.length, "expect_rotate: ");
			// write_intarr(stack_a_5[i], intlist.a.length);
			// write_intlist(intlist.a.item_1st, true);
			// write_intarr(stack_b_5[i], intlist.b.length);
			// write_intlist(intlist.b.item_1st, true);
		}
		if (check_0 == true && check_1 == true && check_2 == true && check_3 == true && check_4 == true && check_5 == true)
			score += 1;
		if (check_0 == true)
			score_0 += 1;
		if (check_1 == true)
			score_1 += 1;
		if (check_2 == true)
			score_2 += 1;
		if (check_3 == true)
			score_3 += 1;
		if (check_4 == true)
			score_4 += 1;
		free_turk_cost(&turk_cost);
		free_2intlist(&intlist);
		i += 1;
	}
	write_total_score(score, max_score);
	write_total_score(score_0, max_score);
	write_total_score(score_1, max_score);
	write_total_score(score_2, max_score);
	write_total_score(score_3, max_score);
	write_total_score(score_4, max_score);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/turk_sort/rotate_2intlist_1.out
*/
