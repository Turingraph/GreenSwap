#-----------------------------------------------------------------------------------------------
# *** define testing file ***
CC = cc -Wall -Wextra -Werror
remove_slash = $(patsubst %/,%,$1)

SRC_input = $(wildcard input/*.c)
SRC_dejavu = $(wildcard dejavu/*.c)
SRC_operator = $(wildcard operator/*.c)

OBJ_input = $(patsubst %.c, obj/%.o, $(SRC_input))
OBJ_dejavu = $(patsubst %.c, obj/%.o, $(SRC_dejavu)) $(OBJ_input)
OBJ_operator = $(patsubst %.c, obj/%.o, $(SRC_operator)) $(OBJ_input)

SRC = $(wildcard */*.c)
OUT = $(patsubst %.c, out/%.out, $(SRC))

#-----------------------------------------------------------------------------------------------
# *** create testing file ***
all: $(OUT)

# for case where out/%.out = out/input/intarr_to_chapter_1.c
# $@ = out/input/intarr_to_chapter_1.c
# $(dir $@)) = out/input/
# $(call remove_slash, $(dir $@))) = out/input
# $(notdir $(call remove_slash, $(dir $@)))) = input
$(OUT): out/%.out: obj/%.o
	@mkdir -p $(@D)
	@echo $^
	$(CC) -o $@ $^ -L. ../src/lib/debug.a ../src/lib/$(basename $(notdir $(call remove_slash, $(dir $@)).c)).a

#-----------------------------------------------------------------------------------------------
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
	rm -r -f out/

# Lol, both Makefile tutorial and Suisei already cover .PHONY
# https://youtu.be/N029UUlH1Dc?si=8PragRfDm3MzFOBc
.PHONY: all clean
