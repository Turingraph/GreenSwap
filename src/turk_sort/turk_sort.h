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
t_turk_costs	load_turk_cost(t_green_swap *src);

// rotate_arr.c
int				*shift_by1_arr(int *dst, size_t length);
int				*rotate_arr(int *src, size_t length, size_t rotate_effect);
int				*rrotate_arr(int *src, size_t length, size_t rotate_effect);

// rotate_list.c
int				rotate_green_swap(size_t target_b, t_green_swap *dst, t_turk_costs *turk_cost, int show);

// sort.c
void			turk_sort(t_green_swap *src, int show);

// update.c
void			update_target_a(t_turk_costs *turk_cost, t_int_list *list_b, int dekmia);
void			update_rotate_cost(t_turk_costs *turk_cost, size_t rotate);
void			update_rrotate_cost(t_turk_costs *turk_cost, size_t rotate);
size_t			pod_of_greed(t_turk_costs *dst);

//utils.c
int				f_abs(int dst);
int				f_max(int a, int b);
bool			is_turk_cost_valid(t_turk_costs *dst, size_t index);
void			sort_two(t_green_swap *dst, int show);
void			sort_three(t_green_swap *dst, int show);

/*
Reference
*	https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0
*/

#endif
