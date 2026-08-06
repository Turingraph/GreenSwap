#include"turk_sort.h"

int	main(void)
{
	size_t			col = 10;
	size_t			score = 0;
	size_t			max_score = 32;
	size_t			i = 0;
	t_2intlist		intlist;
	int				intarr[][10] = {
        {488,	679,	715,	141,	415,	452,	305,	886,	124,	822},
        {728,	803,	463,	294,	141,	264,	530,	855,	686,	732},
        {820,	623,	843,	603,	326,	887,	275,	612,	818,	420},
        {943,	228,	850,	717,	218,	184,	448,	330,	810,	549},
        {684,	778,	332,	246,	236,	430,	219,	221,	840,	378},
        {988,	431,	238,	255,	977,	692,	284,	396,	544,	162},
        {518,	662,	604,	640,	680,	779,	770,	287,	546,	954},
        {436,	212,	317,	169,	780,	648,	946,	579,	656,	266},
        {226,	721,	908,	197,	905,	335,	357,	951,	454,	479},
        {476,	262,	360,	396,	238,	221,	939,	411,	914,	114},
        {642,	199,	537,	540,	911,	977,	958,	519,	279,	526},
        {711,	383,	569,	998,	938,	250,	298,	427,	794,	562},
        {814,	431,	919,	463,	849,	709,	894,	980,	808,	837},
        {296,	103,	498,	565,	723,	103,	711,	478,	343,	536},
        {922,	812,	547,	738,	496,	933,	152,	855,	603,	393},
        {348,	167,	288,	293,	466,	483,	319,	374,	380,	481},
        {464,	380,	724,	446,	981,	579,	542,	344,	776,	279},
        {279,	386,	390,	732,	418,	814,	557,	578,	995,	577},
        {702,	578,	492,	209,	647,	987,	127,	546,	815,	998},
        {681,	772,	547,	395,	802,	283,	837,	792,	256,	156},
        {794,	987,	887,	102,	517,	889,	673,	261,	171,	725},
        {369,	891,	650,	834,	116,	653,	845,	988,	932,	196},
        {342,	548,	238,	196,	207,	784,	621,	998,	455,	467},
        {677,	384,	649,	382,	780,	452,	266,	628,	893,	877},
        {557,	126,	336,	245,	740,	626,	246,	997,	380,	285},
        {776,	752,	585,	434,	837,	162,	227,	545,	477,	960},
        {139,	424,	350,	140,	501,	777,	691,	692,	656,	149},
        {136,	457,	101,	917,	620,	419,	855,	538,	930,	129},
        {276,	637,	837,	144,	618,	471,	382,	774,	976,	706},
        {315,	403,	505,	980,	409,	642,	486,	647,	696,	233},
        {453,	644,	937,	506,	770,	275,	157,	503,	512,	532},
        {902,	489,	369,	609,	495,	295,	691,	610,	429,	582},
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
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/turk_sort/turk_sort_10.out
*/
