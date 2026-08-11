/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 11:38:05 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/11 11:56:26 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "turk_sort.h"

// time : O(n)
// space: O(1)
void	single_rotate_1st(size_t target_b, t_2intlist *dst,
	const t_turk_costs *turk_cost, int show)
{
	size_t	i;

	if (dst != NULL && is_turk_cost_valid(turk_cost, target_b) == true)
	{
		i = 0;
		while (i < target_b)
			i += action_rotate(dst, show, E_B);
		i = 0;
		while ((int)i < f_abs((int)turk_cost->rotate_cost[target_b]))
			i += action_rrotate(dst, show, E_A);
	}
}

// time : O(n)
// space: O(1)
void	single_rotate_2nd(size_t target_b, t_2intlist *dst,
	const t_turk_costs *turk_cost, int show)
{
	size_t	i;

	if (dst != NULL && is_turk_cost_valid(turk_cost, target_b) == true)
	{
		i = 0;
		while (i < target_b)
			i += action_rrotate(dst, show, E_B);
		i = 0;
		while ((int)i < f_abs(
				(int)turk_cost->rotate_cost[turk_cost->length - target_b]))
			i += action_rotate(dst, show, E_A);
	}
}

// time : O(n)
// space: O(1)
void	double_rotate_1st(size_t target_b, t_2intlist *dst,
	const t_turk_costs *turk_cost, int show)
{
	size_t	i;
	size_t	j;

	if (dst != NULL && is_turk_cost_valid(turk_cost, target_b) == true)
	{
		i = 0;
		j = 0;
		while (i < target_b && j < (size_t)f_abs(
				(int)turk_cost->rotate_cost[target_b]))
		{
			i += action_rotate(dst, show, E_AB);
			j += 1;
		}
		while (i < target_b)
			i += action_rotate(dst, show, E_B);
		while (j < (size_t)f_abs((int)turk_cost->rotate_cost[target_b]))
			j += (int)action_rotate(dst, show, E_A);
	}
}

// time : O(n)
// space: O(1)
void	double_rotate_2nd(size_t target_b, t_2intlist *dst,
	const t_turk_costs *turk_cost, int show)
{
	size_t	i;
	size_t	j;

	if (dst != NULL && is_turk_cost_valid(turk_cost, target_b) == true)
	{
		i = 0;
		j = 0;
		while (i < target_b && j < (size_t)(f_abs(
				(int)turk_cost->rotate_cost[turk_cost->length - target_b])))
		{
			i += action_rrotate(dst, show, E_AB);
			j += 1;
		}
		while (i < target_b)
			i += action_rrotate(dst, show, E_B);
		while (j < (size_t)(f_abs(
				(int)turk_cost->rotate_cost[turk_cost->length - target_b])))
			j += action_rrotate(dst, show, E_A);
	}
}

// time : O(n)
// space: O(1)
void	rotate_2intlist(size_t target_b, t_2intlist *dst,
	const t_turk_costs *turk_cost, int show)
{
	if (dst != NULL && is_turk_cost_valid(turk_cost, target_b) == true
		&& turk_cost->length == dst->b.length)
	{
		if (target_b <= dst->b.length / 2
			&& turk_cost->rotate_cost[target_b] >= 0)
			double_rotate_1st(target_b, dst, turk_cost, show);
		else if (target_b <= dst->b.length / 2
			&& turk_cost->rotate_cost[target_b] < 0)
			single_rotate_1st(target_b, dst, turk_cost, show);
		else if (target_b > dst->b.length / 2
			&& turk_cost->rotate_cost[target_b] >= 0)
			single_rotate_2nd(dst->b.length - target_b,
				dst, turk_cost, show);
		else if (target_b > dst->b.length / 2
			&& turk_cost->rotate_cost[target_b] < 0)
			double_rotate_2nd(dst->b.length - target_b,
				dst, turk_cost, show);
	}
}
