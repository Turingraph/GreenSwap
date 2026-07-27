#ifndef TEST_HELPER_H
# define TEST_HELPER_H

#include "../../src/input/input.h"

// int.c
size_t	ft_putnbr_fd(int n, int fd, const char *base, size_t digits);
void	write_total_score(size_t score, size_t max_score);
int		compare_intarr(const int *str_1, const int *str_2, size_t n);
bool	compare_intarr_with_list(const int *intarr, const t_int_node *intlist, size_t length, bool future_is_wild);

// intarr.c
void	write_intlist(t_int_node *dst, bool is_future);
void	write_intarr(int *dst, size_t length);
bool	is_intarr_sort(const int *dst, size_t length, int ascending);
bool	is_intlist_sort(const t_int_node *dst, int ascending);

// merge_sort.c
int		*merge_sort(int *src, size_t length);

#endif
