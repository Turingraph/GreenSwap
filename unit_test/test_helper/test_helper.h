#ifndef TEST_HELPER_H
# define TEST_HELPER_H

#include "../../src/input/input.h"

// intarr.c
void	write_intlist(t_intnode *dst, bool is_future);
// void	write_intarr(int *dst, size_t length);
bool	is_intarr_sort(const int *dst, size_t length, int ascending);
bool	is_intlist_sort(const t_intnode *dst, int ascending);
int		*copy_reverse_intarr(int *dst, const int *src, size_t length);

// merge_sort.c
int		*merge_sort(int *src, size_t length);

#endif
