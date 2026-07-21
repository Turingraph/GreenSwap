CC = cc -Wall -Wextra -Werror

HELPER_SRC = $(wildcard test_helpers/*.c)
HELPER_OBJ = $(patsubst %.c, obj/%.o, $(HELPER_SRC))

SRC_HELPER_input = $(wildcard ../src/utils/libft/*.c)
OBJ_HELPER_input = $(patsubst ../src/%.c, ../src/obj/%.o, $(SRC_HELPER_input))

SRC_input = $(wildcard input/*.c)
SRC_duplicate_check = $(wildcard duplicate_check/*.c)
SRC_operator = $(wildcard operator/*.c)

OBJ_input = $(patsubst %.c, obj/%.o, $(SRC_input))
OBJ_duplicate_check = $(patsubst %.c, obj/%.o, $(SRC_duplicate_check)) $(OBJ_input)
OBJ_operator = $(patsubst %.c, obj/%.o, $(SRC_operator)) $(OBJ_input)

OUT_ALL = $(patsubst src/%.c, out/%.out, $(SRC_input) $(SRC_duplicate_check) $(SRC_operator))

#-----------------------------------------------------------------------------------------------
# *** create library ***
all: $(OUT_ALL)
	@echo $^

$(OUT_ALL): out/%.out: lib/test_helpers.a obj/%.o
	@mkdir -p $(@D)
	$(CC) -o $@ $(call get_obj_files, $^) -L. $(call get_lib_a_files, $^) ../src/lib/$(basename $(notdir $(call remove_slash, $(dir $@)).c)).a

lib/test_helper.a: $(HELPER_OBJ)
	@mkdir -p $(@D)
	ar rcs $@ $^ $(OBJ_HELPER_input) $(OBJ_HELPER_get_next_line)

obj/test_helpers/%.o: test_helpers/%.c
	@mkdir -p $(@D)
	$(CC) -c $< -o $@

obj/%.o: src/%.c
	@mkdir -p $(@D)
	$(CC) -c $< -o $@

#-----------------------------------------------------------------------------------------------
# *** clean ***
clean:
	rm -r -f out/
	rm -r -f lib/
	rm -r -f obj/

.PHONY: all clean
