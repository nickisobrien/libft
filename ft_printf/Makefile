C = clang

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

DIR_S = srcs

DIR_O = temporary

HEADER = include

SOURCES = handle_float.c handle_invalid_converter.c handle_ptr.c handle_char.c handle_hex.c handle_int.c handle_octal.c handle_string.c handle_wchar.c handle_wstring.c ft_printf.c init.c mid_handlers.c parsers.c helpers.c ns_helpers.c

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p temporary
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)

fclean: clean
	@rm -f $(NAME)

re: fclean all