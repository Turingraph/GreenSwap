/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 11:58:05 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/11 12:10:22 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_TEST_H
# define INPUT_TEST_H

# include "../../src/input/input.h"
# include "../../src/debug/debug.h"

typedef struct t_atoi_tester
{
	char	*min_input;
	char	*max_input;
	bool	is_eq_or_less;
	bool	is_number;
}	t_atoi_tester;

typedef struct t_putnbr_tester
{
	int			input_n;
	size_t		input_digits;
	const char	*input_base;
	size_t		expected_length;
}	t_putnbr_tester;

typedef struct t_split_tester
{
	const char	*input_str;
	const char	*input_space;
	size_t		expected_length;
	const char	**expected_output;
}	t_split_tester;

#endif
