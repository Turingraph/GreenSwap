/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dejavu.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 11:09:19 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/11 11:12:30 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEJAVU_H
# define DEJAVU_H

# include "../input/input.h"

// dejavu.c
bool	kagerou_day(int *events, size_t time);

// eclipse.c
char	*sieve_of_eratosthenes(size_t today, char *sieve);
size_t	wait_next_eclipse(size_t today);
size_t	the_wheel_of_fortune(int event, size_t eclipse);

#endif
