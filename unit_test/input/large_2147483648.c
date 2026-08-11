/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_2147483648.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 12:11:15 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/11 12:11:16 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

int	main(void)
{
	size_t		col = 3;
	int			*dst;
	t_intlist	intlist;
	char		*strarr[] = {"-2147483648", "-2147483647", "-2147483646"};
	int			intarr[] = {-2147483648, -2147483647, -2147483646};

	dst = strarr_to_intarr((const char **)strarr, col);
	intlist = load_intlist(dst, col);
	if (is_intarr_and_list_same(intarr, intlist.item_1st, col, true) == true
		&& is_intarr_and_list_same(intarr, intlist.item_last, col, false) == true)
		write(1, "Correct\n", 9);
	else
	{
		write_intlist(intlist.item_1st, true, "output: ");
	}
	free(dst);
	free_intlist(&intlist);
}

/*

valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/input/large_2147483648.out
*/
