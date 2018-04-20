NAME = libft.a

# directories
SRC_DIR = srcs/
INC_DIR = includes/
OBJ_DIR = obj/

ACCESS_DIR		= access/
BITS_DIR		= bits/
CASE_DIR		= case/
FT_PRINTF_DIR	= ft_printf/
GNL_DIR			= gnl/
LST_DIR			= lst/
MATH_DIR		= math/
MEM_DIR			= mem/
PUT_DIR			= put/
STR_DIR			= str/
WCHAR_DIR		= wchar/

CFLAGS = -Wall -Wextra -Werror

SRC := $(wildcard $(SRC_DIR)$(ACCESS_DIR)*.c)
SRC += $(wildcard $(SRC_DIR)$(BITS_DIR)*.c)
SRC += $(wildcard $(SRC_DIR)$(CASE_DIR)*.c)
SRC += $(wildcard $(SRC_DIR)$(FT_PRINTF_DIR)*.c)
SRC += $(wildcard $(SRC_DIR)$(GNL_DIR)*.c)
SRC += $(wildcard $(SRC_DIR)$(LST_DIR)*.c)
SRC += $(wildcard $(SRC_DIR)$(MATH_DIR)*.c)
SRC += $(wildcard $(SRC_DIR)$(MEM_DIR)*.c)
SRC += $(wildcard $(SRC_DIR)$(PUT_DIR)*.c)
SRC += $(wildcard $(SRC_DIR)$(STR_DIR)*.c)
SRC += $(wildcard $(SRC_DIR)$(WCHAR_DIR)*.c)
OBJ := $(notdir $(SRC))
OBJ := $(patsubst %, $(OBJ_DIR)%, $(OBJ:.c=.o))

.PHONY: all clean fclean re

all: 
	@make $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "Library libft created"

$(OBJ_DIR)%.o: $(SRC_DIR)*/%.c
	@mkdir -p $(OBJ_DIR)
	@echo "Compiling $<"
	@gcc -Wall -Wextra -Werror -I $(INC_DIR) -c $< -o $@ 2> temp.log || touch temp.error
	@if test -s temp.log; then echo "Error in $<\n" && cat temp.log; fi;
	@rm -f temp.error temp.log

clean:
	@if [ -d "./$(OBJ_DIR)" ]; then\
		rm -rf $(OBJ_DIR);\
		echo "Object folder removed";\
	fi;

fclean: clean
	@if test -e $(NAME); then\
		/bin/rm -f $(NAME);\
		echo "Library libft removed";\
	fi;

re: fclean all
