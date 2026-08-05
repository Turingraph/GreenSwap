#include"turk_sort.h"

int	main(void)
{
	size_t			col = 8;
	size_t			score = 0;
	size_t			max_score = 32;
	size_t			i = 0;
	t_2intlist		intlist;
	int				intarr[][8] = {
		{52	,18	,38	,73	,73	,32	,76,	67},	// 00
		{58	,10	,69	,66	,1	,93	,92,	40},	// 01
		{52	,43	,55	,41	,94	,19	,60,	73},	// 02
		{50	,6	,69	,39	,25	,67	,71,	86},	// 03
		{3	,27	,70	,99	,3	,91	,39,	79},	// 04
		{9	,59	,79	,11	,71	,34	,31,	31},	// 05
		{94	,4	,18	,11	,51	,91	,69,	51},	// 06
		{17	,34	,57	,46	,85	,76	,76,	64},	// 07
		{98	,31	,28	,12	,25	,68	,77,	83},	// 08
		{10	,15	,58	,21	,17	,65	,61,	54},	// 09
		{77	,59	,45	,44	,92	,34	,38,	71},	// 10
		{76	,1	,83	,21	,4	,56	,87,	96},	// 11
		{73	,47	,77	,72	,15	,41	,25,	35},	// 12
		{66	,11	,39	,25	,63	,31	,81,	60},	// 13
		{25	,26	,38	,42	,35	,54	,62,	15},	// 14
		{32	,26	,50	,15	,73	,16	,12,	45},	// 15
		{68	,59	,82	,36	,73	,66	,22,	36},	// 16
		{17	,45	,77	,37	,33	,45	,37,	3},		// 17
		{9	,86	,91	,6	,2	,31	,92,	38},	// 18
		{85	,24	,73	,41	,65	,9	,70,	2},		// 19
		{82	,40	,58	,7	,56	,4	,78,	72},	// 20
		{20	,84	,74	,97	,33	,37	,85,	22},	// 21
		{24	,83	,73	,22	,63	,25	,83,	35},	// 22
		{82	,10	,79	,59	,81	,7	,11,	89},	// 23
		{25	,38	,97	,5	,45	,95	,1	,36},		// 24
		{1,2,3,4,5,6,7,8},						// 25
		{1,2,1,2,1,2,1,2},						// 26
		{1,2,3,1,2,3,4,5},						// 27
		{9,8,7,6,5,4,3,2},						// 28
		{4,5,1,2,1,2,3,1},						// 29
		{4,5,6,3,2,1,0,1},						// 30
		{1,2,3,4,8,7,6,5},						// 31
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
Wrong but partial_progress = 8 / 8
1.	4
2.	16
3.	24
4.	27
5.	29

Wrong and get fewer than 8 / 8 score
1.	6	(6)
2.	8	(7)
3.	21	(7)

*/

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/turk_sort/turk_sort_08.out
*/
