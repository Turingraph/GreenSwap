/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort_09.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 12:23:31 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/11 12:23:32 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"turk_sort.h"

int	main(void)
{
	size_t			col = 9;
	size_t			score = 0;
	size_t			max_score = 33;
	size_t			i = 0;
	t_2intlist		intlist;
	int				intarr[][9] = {
{920,	167,	502,	563,	628,	811,	205,	341,	291},
{692,	136,	132,	234,	296,	957,	450,	497,	470},
{556,	144,	605,	120,	498,	411,	956,	894,	287},
{799,	551,	980,	158,	513,	344,	861,	981,	698},
{153,	737,	577,	343,	205,	551,	757,	433,	413},
{611,	958,	400,	503,	412,	933,	115,	629,	620},
{650,	186,	581,	471,	297,	678,	354,	442,	746},
{299,	587,	745,	601,	852,	806,	364,	282,	625},
{741,	387,	584,	469,	452,	424,	151,	904,	683},
{832,	614,	444,	187,	408,	480,	196,	304,	101},
{611,	767,	352,	490,	482,	179,	746,	214,	154},
{296,	106,	276,	142,	179,	921,	666,	845,	217},
{457,	603,	157,	664,	319,	127,	115,	229,	424},
{266,	853,	620,	737,	392,	759,	525,	199,	895},
{906,	439,	129,	336,	291,	191,	962,	340,	120},
{347,	143,	265,	386,	642,	360,	797,	910,	388},
{288,	481,	255,	718,	288,	552,	317,	964,	472},
{386,	261,	851,	856,	382,	197,	524,	228,	894},
{342,	867,	227,	575,	930,	290,	691,	580,	442},
{245,	450,	901,	602,	159,	720,	623,	960,	988},
{420,	571,	809,	194,	744,	325,	363,	644,	829},
{907,	184,	975,	816,	519,	835,	782,	168,	551},
{484,	315,	609,	879,	116,	563,	424,	588,	702},
{763,	166,	505,	689,	747,	824,	393,	500,	493},
{386,	980,	314,	674,	468,	371,	144,	550,	377},
{100,	369,	429,	224,	480,	908,	857,	436,	800},
{451,	100,	432,	132,	647,	652,	675,	695,	199},
{879,	498,	214,	252,	392,	756,	249,	395,	624},
{752,	917,	766,	959,	495,	176,	111,	854,	472},
{363,	165,	100,	517,	413,	876,	617,	628,	836},
{225,	803,	545,	818,	790,	715,	848,	255,	653},
{398,	240,	918,	628,	989,	900,	840,	810,	593},
{275,	379,	366,	634,	191,	734,	579,	404,	798}
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
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/turk_sort/turk_sort_09.out
*/
