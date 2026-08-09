CC = cc -Wall -Wextra -Werror

re: fclean
	make all

all:
	$(MAKE) -C src all
	$(CC) -c main.c -o main.o
	$(CC) -o push_swap main.o -L. src/lib/dejavu.a src/lib/turk_sort.a

clean:
	$(MAKE) -C src clean

fclean: clean
	rm -f main.o
	rm -f push_swap

#-----------------------------------------------------------------------------------------------
# This line is for debugging mode

all_unit_test: all
	$(MAKE) -C unit_test all

clean_unit_test:
	$(MAKE) -C unit_test clean

#-----------------------------------------------------------------------------------------------

.PHONY: all clean fclean all_unit_test clean_unit_test
