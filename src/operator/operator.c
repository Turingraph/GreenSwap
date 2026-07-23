#include"operator.h"

// time : O(1)
// space: O(1)
size_t	write_available_operator(t_green_swap *dst, e_target target, int show, e_operator operator)
{
	if (dst == NULL)
		return (0);
	if (is_operator_available(operator, &(dst->b)) == true
		&& is_operator_available(operator, &(dst->a)) == true && target == TARGET_AB)
	{
		write_operator(target, operator, show);
		return (1);
	}
	else if (target != TARGET_B && is_operator_available(operator, &(dst->a)) == true)
	{
		write_operator(TARGET_A, operator, show);
		return (1);
	}
	else if (target != TARGET_A && is_operator_available(operator, &(dst->b)) == true)
	{
		write_operator(TARGET_B, operator, show);
		return (1);
	}
	return (0);
}

// time : O(1)
// space: O(1)
char	operate_green_swap(t_green_swap *dst, e_target target, e_operator operator, void (*operator_action)(t_int_list *dst))
{
	if (dst == NULL || (operator_action == NULL && operator != E_PUSH))
		return (0);
	else if (operator_action == NULL && operator == E_PUSH)
	{
		if (target == TARGET_AB)
			return (0);
		if (target == TARGET_A && is_1_or_more(&(dst->a)) == true)
			act_push(&(dst->a), &(dst->b));
		if (target == TARGET_B && is_1_or_more(&(dst->b)) == true)
			act_push(&(dst->b), &(dst->a));
	}
	else if (is_operator_available(operator, &(dst->b)) == true
		&& is_operator_available(operator, &(dst->a)) == true && target == TARGET_AB)
	{
		operator_action(&(dst->a));
		operator_action(&(dst->b));
	}
	else if (target != TARGET_B && is_operator_available(operator, &(dst->a)) == true)
		operator_action(&(dst->a));
	else if (target != TARGET_A && is_operator_available(operator, &(dst->b)) == true)
		operator_action(&(dst->b));
	return (1);
}
