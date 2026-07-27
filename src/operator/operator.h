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
	E_A,
	E_B,
	E_AB,
};

// act.c
void	act_swap(t_intlist *src);
void	act_rotate(t_intlist *src);
void	act_rrotate(t_intlist *src);
void	act_push(t_intlist *src, t_intlist *dst);

// operator.c
size_t	write_available_operator(t_2intlist *dst, e_target target, int show, e_operator operator);
char	operate_double_intlist(t_2intlist *dst, e_target target, e_operator operator, void (*operator_action)(t_intlist *dst));

// utils.c
bool	is_intlist_n_more(const t_intlist *src, size_t length);
bool	is_2intlist_n_more(const t_2intlist *src, size_t min_a, size_t min_b);
bool	is_operator_available(e_operator operator, const t_intlist *dst);
void	write_operator(e_target target, e_operator operator, int show);

#endif
