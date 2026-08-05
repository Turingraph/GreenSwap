#ifndef DEBUG_H
# define DEBUG_H

#include"../input/input.h"

// arr.c
bool	is_intarr_sort(const int *src, size_t length, int ascending);
int		*clone_intarr(const int *src, size_t length);
void	write_intarr(int *src, size_t length, char *str);
bool	is_2intarr_same(const int *str_1, const int *str_2, size_t n);

// int.c
size_t	ft_putnbr_fd(int n, int fd, const char *base, size_t digits);
void	write_total_score(size_t score, size_t max_score);

// list.c
void	write_intlist(t_intnode *src, bool is_future, char *str);
bool	is_intlist_sort(const t_intnode *src, int ascending, size_t tolerate);
bool	is_intarr_and_list_same(const int *intarr, const t_intnode *intlist, size_t length, bool future_is_wild);

// merge_sort.c
int		*merge_sort(int *src, size_t length);

#endif
