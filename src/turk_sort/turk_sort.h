/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 11:46:13 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/11 12:08:52 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TURK_SORT_H
# define TURK_SORT_H

# include "../operator/operator.h"
# include "../debug/debug.h"

typedef struct t_turk_costs
{
	int		*target_a;
	int		*rotate_cost;
	size_t	length;
	size_t	capacity;
}	t_turk_costs;

// debug.c
t_turk_costs	debug_turk_sort(t_2intlist *src, int show, size_t stop);

// epilogue.c
void			epilogue_rotate_action(t_2intlist *src, int show);

// init.c
t_turk_costs	free_turk_cost(t_turk_costs *src);
t_turk_costs	load_turk_cost(t_2intlist *src);

// rotate_arr.c
int				*shift_arr(int *dst, size_t length);
int				*rotate_value(int *src, size_t length_b,
					size_t rotate_effect, size_t length_a);
int				*rrotate_value(int *src, size_t length_b,
					size_t rotate_effect, size_t length_a);
int				*rrotate_arr(int *src, size_t length, size_t rotate_effect);

// rotate_list.c
void			rotate_2intlist(size_t target_b, t_2intlist *dst,
					const t_turk_costs *turk_cost, int show);

// sort.c
size_t			pod_of_greed(const t_turk_costs *dst);
void			double_draw(t_2intlist *src,
					t_turk_costs *turk_cost, int show);
t_turk_costs	first_turk_sort(t_2intlist *src, int show);
void			turk_sort(t_2intlist *src, int show);

// update_turk_cost.c
void			rotate_turk_cost(t_turk_costs *dst, size_t rotate_b);
void			pop_turk_cost(int first_item_a, t_turk_costs *turk_cost,
					t_intlist *stack_b, size_t length_a);
void			reverse_turk_cost(t_turk_costs *turk_cost,
					const t_intlist *stack_b, size_t length_a);

// utils.c
int				f_abs(int dst);
bool			is_turk_cost_valid(const t_turk_costs *dst, size_t index);
void			sort_two(t_2intlist *dst, int show);
void			sort_three(t_2intlist *dst, int show);

/*
Reference
*	https://pure-forest.medium.com/
	push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0
*/

#endif
