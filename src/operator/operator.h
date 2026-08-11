/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 11:20:55 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/11 12:08:27 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATOR_H
# define OPERATOR_H

# include "../input/input.h"

typedef enum e_operator
{
	E_SWAP,
	E_PUSH,
	E_ROTATE,
	E_RROTATE,
}	t_operator;

typedef enum e_target
{
	E_A,
	E_B,
	E_AB,
}	t_target;

// act.c
void	act_swap(t_intlist *src);
void	act_rotate(t_intlist *src);
void	act_rrotate(t_intlist *src);
void	act_push(t_intlist *src, t_intlist *dst);

// action.c
size_t	action_swap(t_2intlist *src, int show, t_target target);
size_t	action_rotate(t_2intlist *src, int show, t_target target);
size_t	action_rrotate(t_2intlist *src, int show, t_target target);
size_t	action_push(t_2intlist *src, int show, t_target target);

// operator.c
size_t	write_available_operator(t_2intlist *dst,
			t_target target, int show, t_operator operator);
char	operate_2intlist(t_2intlist *dst,
			t_target target, t_operator operator,
			void (*operator_action)(t_intlist *dst));

// utils.c
bool	is_intlist_n_more(const t_intlist *src, size_t length);
bool	is_2intlist_n_more(const t_2intlist *src, size_t min_a, size_t min_b);
bool	is_operator_available(t_operator operator, const t_intlist *dst);
void	write_operator(t_target target, t_operator operator, int show);

#endif
