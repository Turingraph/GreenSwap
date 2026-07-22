CC = cc -Wall -Wextra -Werror

.SECONDEXPANSION:

LIBRARY = $(patsubst %, lib/%.a, input duplicate_check operator)

SRC_input = $(wildcard input/*.c)
SRC_duplicate_check = $(wildcard duplicate_check/*.c)
SRC_operator = $(wildcard operator/*.c)

OBJ_input = $(patsubst %.c, obj/%.o, $(SRC_input))
OBJ_duplicate_check = $(patsubst %.c, obj/%.o, $(SRC_duplicate_check)) $(OBJ_input)
OBJ_operator = $(patsubst %.c, obj/%.o, $(SRC_operator)) $(OBJ_input)


#-----------------------------------------------------------------------------------------------
# *** create library ***

.PRECIOUS: $(OBJ_input)

all: $(LIBRARY)

# This line works for every library in $(LIBRARY) list, but I use lib/input.a as a simple example.
# $@ = lib/input.a
# $$(basename $$@) = lib/input
# $$(notdir $$(basename $$@)) = input
# OBJ_$$(notdir $$(basename $$@)) = BIN_input
# $$(OBJ_$$(notdir $$(basename $$@))) = $(BIN_input)
lib/%.a: $$(OBJ_$$(notdir $$(basename $$@)))
	@mkdir -p $(@D)
	ar rcs $@ $^

# *** create object files. ***
# https://stackoverflow.com/questions/1950926/create-directories-using-make-file
obj/%.o: %.c
	@mkdir -p $(@D)
	$(CC) -c $< -o $@

#-----------------------------------------------------------------------------------------------
# *** clean ***
# https://askubuntu.com/questions/802996/how-to-remove-directory-with-all-of-its-contents
clean:
	rm -r -f lib/
	rm -r -f obj/

# Lol, both Makefile tutorial and Suisei already cover .PHONY
# https://youtu.be/N029UUlH1Dc?si=8PragRfDm3MzFOBc
.PHONY: all clean
