#ifndef INPUT_H
# define INPUT_H

#include"stdlib.h"
#include"stdbool.h"
#include"unistd.h"

typedef struct t_intnode t_intnode;

typedef struct t_intnode
{
	int					value;
	struct t_intnode	*next;
	struct t_intnode	*prev;
}	t_intnode;

typedef struct t_intlist t_intlist;

typedef struct t_intlist
{
	struct t_intnode	*item_1st;
	struct t_intnode	*item_last;
	size_t				length;
}	t_intlist;

typedef struct t_2intlist t_2intlist;

typedef struct t_2intlist
{
	struct t_intlist	a;
	struct t_intlist	b;
}	t_2intlist;

// atoi.c
size_t				f_strlen(const char *str);
int					f_atoi(const char *src, bool *is_int, const char *base, size_t digits);

// init.c
t_intnode			*init_intnode(int src);
void				free_intnode(t_intnode *src);
void				free_intlist(t_intlist *src);
void				free_2intlist(t_2intlist *src);

// int.c
size_t	ft_putnbr_fd(int n, int fd, const char *base, size_t digits);
void	write_total_score(size_t score, size_t max_score);
bool	is_2intarr_same(const int *str_1, const int *str_2, size_t n);
bool	is_intarr_and_list_same(const int *intarr, const t_intnode *intlist, size_t length, bool future_is_wild);
void	write_intarr(int *dst, size_t length);

// load.c
void				free_2d_arr(void **arr, size_t len);
char				**copy_strarr(const char **src, size_t length);
int					*strarr_to_intarr(const char **src, size_t length);
t_intnode			*load_intnode(const int *src, size_t length);
t_intlist			load_intlist(const int *src, size_t length);
t_2intlist			load_2intlist(const int *src, size_t length);

#endif
