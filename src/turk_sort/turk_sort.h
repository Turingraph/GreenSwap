#ifndef TURK_SORT_H
# define TURK_SORT_H

#include"../operator/operator.h"

typedef struct t_turk_costs t_turk_costs;

typedef struct t_turk_costs
{
	int		*target_a;
	int		*rotate_cost;
	size_t	length;
	size_t	capacity;
}	t_turk_costs;

// init.c
void			free_turk_cost(t_turk_costs *src);
t_turk_costs	load_turk_cost(t_2intlist *src);

// pod_of_greed.c
size_t			pod_of_greed(t_turk_costs *dst);

// push_turk_cost.c
void			pop_turk_cost(int first_item_a, t_turk_costs *turk_cost, t_intlist *stack_b, size_t length_a);
void			reverse_turk_cost(t_turk_costs *turk_cost, t_intlist *stack_b, size_t length_a);

// rotate_arr.c
int				*shift_arr(int *dst, size_t length);
int				*rotate_arr(int *src, size_t length, size_t rotate_effect);
int				*rrotate_arr(int *src, size_t length, size_t rotate_effect);
int				*rotate_value(int *src, size_t length_b, size_t rotate_effect, size_t length_a);
int				*rrotate_value(int *src, size_t length_b, size_t rotate_effect, size_t length_a);

// rotate_list.c
int				rotate_2intlist(size_t target_b, t_2intlist *dst, const t_turk_costs *turk_cost, int show);

// sort.c
void			pop_turk(t_turk_costs *dst, bool reverse, size_t length_a);
void			update_target_a(t_turk_costs *turk_cost,
	t_intlist *list_b, int target_a, bool reverse);
void			rotate_turk_cost(t_turk_costs *dst, size_t rotate_b);
t_turk_costs	first_turk_sort(t_2intlist *src, int show);
void			double_draw(t_2intlist *src, t_turk_costs *turk_cost, int show);
void			turk_sort(t_2intlist *src, int show);

// utils.c
int				f_abs(int dst);
int				f_max(int a, int b);
bool			is_turk_cost_valid(const t_turk_costs *dst, size_t index);
void			sort_two(t_2intlist *dst, int show);
void			sort_three(t_2intlist *dst, int show);

/*
Reference
*	https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0
*/

#endif
