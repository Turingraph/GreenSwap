/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_2147483648.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 11:57:55 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/11 11:57:56 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dejavu.h"

int	main(void)
{
	size_t		col = 3;
	int			intarr[] = {-2147483648, -2147483647, -2147483646};

	if (kagerou_day(intarr, col) == false)
		write(1, "Correct\n", 9);
	else
		write(1, "vicious circle\n", 16);
}

/*

valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/dejavu/large_2147483648.out
*/
