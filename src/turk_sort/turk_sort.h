#ifndef TURK_SORT_H
# define TURK_SORT_H

#include"../operator/operator.h"

typedef struct t_turk_costs t_turk_costs;

typedef struct t_turk_costs
{
	int		*target_a;
	size_t	*target_rotate;
	size_t	*rotate_cost;
	size_t	*total_cost;
	size_t	length;
	size_t	capacity;
}	t_turk_costs;

/*


Reference
*	https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0
*/

#endif
