/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 11:20:04 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/11 12:05:37 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operator.h"

// time : O(1)
// space: O(1)
size_t	action_swap(t_2intlist *src, int show, t_target target)
{
	write_available_operator(src, target, show, E_SWAP);
	operate_2intlist(src, target, E_SWAP, act_swap);
	return (1);
}

// time : O(1)
// space: O(1)
size_t	action_rotate(t_2intlist *src, int show, t_target target)
{
	write_available_operator(src, target, show, E_ROTATE);
	operate_2intlist(src, target, E_ROTATE, act_rotate);
	return (1);
}

// time : O(1)
// space: O(1)
size_t	action_rrotate(t_2intlist *src, int show, t_target target)
{
	write_available_operator(src, target, show, E_RROTATE);
	operate_2intlist(src, target, E_RROTATE, act_rrotate);
	return (1);
}

// time : O(1)
// space: O(1)
size_t	action_push(t_2intlist *src, int show, t_target target)
{
	write_available_operator(src, target, show, E_PUSH);
	operate_2intlist(src, target, E_PUSH, NULL);
	return (1);
}
