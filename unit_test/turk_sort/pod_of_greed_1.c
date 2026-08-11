/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pod_of_greed_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 12:20:26 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/11 12:20:27 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"turk_sort.h"


int	main(void)
{
	size_t			col = 15;
	size_t			score;
	size_t			max_score = 6;
	size_t			i;
	size_t			chosen_pod;
	size_t			cheap_trick = 0;
	t_2intlist		intlist;
	t_turk_costs	turk_cost;
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
		{11, 74, 11, 11, 54, 11, 54, 11, 11, 74, 54, 54, 74, 11, 11}, 
		{11, 54, 54, 11, 11, 74, 11, 11, 54, 11, 11, 54, 74, 54, 74}, 
		{74,	74,	11,	11,	54,	54,	54,	11,	74,	54,	74,	74,	74,	54,	54}, 
		{11, 54, 11, 11, 74, 54, 54, 74, 74, 54, 11, 11, 54, 11, 54}, 
		{11, 54, 54, 54, 54, 54, 74, 54, 54, 54, 54, 54, 11, 54, 54},
	};
	int				rotate_cost[][15] = {
		{1, -1, 1, 1, 0, 1, 1, 1, 1, -1, -1, 0, 1, 0, -1, },
		{0, -1, 0, 0, 1, 0, 1, 0, 0, -1, 1, 1, -1, 0, 0}, 
		{0, 1, 1, 0, 0, -1, 0, 0, 1, 0, 0, 1, -1, 1, -1, },
		{-1, -1,	0,	0,	1,	1,	1,	0,	-1,	1,	-1,	-1,	-1,	1,	1}, 
		{0, 1, 0, 0, -1, 1, 1, -1, -1, 1, 0, 0, 1, 0, 1, },
		{0, 1, 1, 1, 1, 1, -1, 1, 1, 1, 1, 1, 0, 1, 1,},
	};

	score = 0;
	i = 0;
	while (i < max_score)
	{
		ft_putnbr_fd((int)i, 1, "0123456789", 1);
		write(1, "\n", 1);
		intlist = load_2intlist(intarr[i], col + 3);
		turk_cost = first_turk_sort(&intlist, -2);
		chosen_pod = pod_of_greed(&turk_cost);
		if (turk_cost.length == intlist.b.length && chosen_pod == cheap_trick
			&& is_2intarr_same(turk_cost.target_a, target_a[i], turk_cost.length) == true
			&& is_2intarr_same(turk_cost.rotate_cost, rotate_cost[i], turk_cost.length) == true)
			score += 1;
		else
			write(1, " is bad.", 9);
		ft_putnbr_fd(i, 1, "0123456789", 1);
		// write_intarr()
		write_intlist(intlist.b.item_1st, true, "stack_b: ");
		write(1, "\n", 1);
		free_turk_cost(&turk_cost);
		free_2intlist(&intlist);
		i += 1;
	}
	write_total_score(score, max_score);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/turk_sort/pod_of_greed_1.out
*/
