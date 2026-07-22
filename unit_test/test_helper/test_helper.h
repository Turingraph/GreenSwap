#ifndef TEST_HELPER_H
# define TEST_HELPER_H

#include "../../src/input/input.h"

// test_helper.c
void	write_future(t_int_node *dst, bool is_future);
void	write_total_score(size_t score, size_t max_score);
int		compare_intarr(const int *str_1, const int *str_2, size_t n);
bool	compare_intarr_with_list(const int *intarr, const t_int_node *intlist, size_t length, bool future_is_wild);

#endif
