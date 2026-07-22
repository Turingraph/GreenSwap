#ifndef OPERATOR_H
# define OPERATOR_H

#include"../input/input.h"

typedef enum e_operator e_operator;

enum e_operator
{
	E_SWAP,
	E_PUSH,
	E_ROTATE,
	E_RROTATE,
};

typedef enum e_target e_target;

enum e_target
{
	TARGET_A,
	TARGET_B,
	TARGET_AB,
};

// act.c
void	act_swap(t_int_list *src);
void	act_rotate(t_int_list *src);
void	act_rrotate(t_int_list *src);
void	act_push(t_int_list *src, t_int_list *dst);

// operator.c
size_t	write_available_operator(t_green_swap *dst, e_target target, int show, e_operator operator);
char	operate_green_swap(t_green_swap *dst, e_target target, e_operator operator, void (*operator_action)(t_int_list *dst));

// utils.c
bool	is_1_or_more(t_int_list *src);
bool	is_2_or_more(t_int_list *src);
bool	is_operator_available(e_operator operator, t_int_list *dst);
void	write_operator(e_target target, e_operator operator, int show);

#endif
