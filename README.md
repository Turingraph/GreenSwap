# Description

This Git repository is Push Swap program which sorted stacks of unique integer according to Push Swap rules. You can read about the rules for more details from this Website (https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0).

# Instruction

In order to use this Git repository, you can
1.	`make all`
2.	`./push_swap "1 2 3" | ./checker_linux "1 2 3"` for any other number inputs beside `"1 2 3"`
3.	The program will display error, if the input numbers aren't number, greater than 2147483647, less than -2147483648, and/or are duplicated.
4.	You can `make fclean` to delete all of the build files, and `make re` to remake the build files.
5.	Lastly, you can execute the files from `unit_test/` to check if each functions from `src/` works expectedly.

# Resource

1.	How to implement Hash Table ?
*	https://www.geeksforgeeks.org/dsa/sieve-of-eratosthenes/#sieve-of-eratosthenes-onloglogn-time-and-on-space
*	https://www.geeksforgeeks.org/dsa/mid-square-hashing/
*	https://stackoverflow.com/questions/11871245/knuth-multiplicative-hash
2.	How to implement Turk Sort ?
*	https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0
3.	Push Swap Tester
*	https://github.com/LeoFu9487/push_swap_tester
*	https://github.com/gemartin99/Push-Swap-Tester
4.	Makefile tips
*	https://stackoverflow.com/questions/68292501/secondary-expansion-in-a-makefile-is-causing-unnecessary-targets-to-be-run
*	https://stackoverflow.com/questions/1950926/create-directories-using-make-file
*	https://askubuntu.com/questions/802996/how-to-remove-directory-with-all-of-its-contents
*	https://makefiletutorial-com.translate.goog/?_x_tr_sl=en&_x_tr_tl=th&_x_tr_hl=th&_x_tr_pto=tc#the-call-function
*	https://ftp.gnu.org/old-gnu/Manuals/make-3.79.1/html_node/make_79.html

To Do List
1.  fix unit_test/operator/
2.  implement turk sort.
