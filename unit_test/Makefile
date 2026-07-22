#-----------------------------------------------------------------------------------------------
# *** define testing file ***
CC = cc -Wall -Wextra -Werror
remove_slash = $(patsubst %/,%,$1)
get_obj_files = $(filter %.o, $1)
get_lib_a_files = $(filter %.a, $^)

SRC_input = $(wildcard input/*.c)
SRC_duplicate_check = $(wildcard duplicate_check/*.c)
SRC_operator = $(wildcard operator/*.c)

OBJ_input = $(patsubst %.c, obj/%.o, $(SRC_input))
OBJ_duplicate_check = $(patsubst %.c, obj/%.o, $(SRC_duplicate_check)) $(OBJ_input)
OBJ_operator = $(patsubst %.c, obj/%.o, $(SRC_operator)) $(OBJ_input)

SRC = $(wildcard src/*/*.c)
OUT = $(patsubst src/%.c, out/%.out, $(SRC))

#-----------------------------------------------------------------------------------------------
# *** define library ***
OBJ_HELPER_input = $(wildcard ../src/obj/input/*.c)
TEST_HELPER_SRC = $(wildcard test_helper/*.c)
TEST_HELPER_OBJ = $(patsubst %.c, obj/%.o, $(TEST_HELPER_SRC)) $(OBJ_HELPER_input)
TEST_HELPER_LIB = lib/test_helper.a

#-----------------------------------------------------------------------------------------------
# *** create testing file ***
all: $(OUT)
	@echo $^

# for case where out/%.out = out/input/intarr_to_chapter_1.c
# $@ = out/input/intarr_to_chapter_1.c
# $(dir $@)) = out/input/
# $(call remove_slash, $(dir $@))) = out/input
# $(notdir $(call remove_slash, $(dir $@)))) = input
$(OUT): out/%.out: obj/%.o $(TEST_HELPER_LIB)
	@mkdir -p $(@D)
	$(CC) -o $@ $(call get_obj_files, $^) -L. $(call get_lib_a_files, $^) ../src/lib/$(basename $(notdir $(call remove_slash, $(dir $@)).c)).a

#-----------------------------------------------------------------------------------------------
# *** create library ***
$(TEST_HELPER_LIB): $(TEST_HELPER_OBJ)
	@mkdir -p $(@D)
	ar rcs $@ $^

obj/test_helper/%.o: test_helper/%.c
	@mkdir -p $(@D)
	$(CC) -c $< -o $@

#-----------------------------------------------------------------------------------------------
# *** create object files. ***
# https://stackoverflow.com/questions/1950926/create-directories-using-make-file
obj/%.o: src/%.c
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
