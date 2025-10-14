CC= cc -Werror -Wextra -Wall

SRC= main.c \
	src/operations/pa.c \
	src/operations/pb.c \
	src/operations/ra.c \
	src/operations/rb.c \
	src/operations/rr.c \
	src/operations/rra.c \
	src/operations/rrb.c \
	src/operations/rrr.c \
	src/operations/sa.c \
	src/operations/sb.c \
	src/operations/ss.c \
	src/append_node.c \
	src/assign_relative_value.c \
	src/calculate_loops.c \
	src/check_for_repeats.c \
	src/error_handler.c \
	src/format_list.c \
	src/get_list.c \
	src/init_stack_b.c \
	src/is_sorted.c \
	src/push_atol.c \
	src/push_cmp_isequal.c \
	src/push_cmp_isgreater.c \
	src/push_copy_content.c \
	src/push_lst_size.c \
	src/push_radix_sort.c \
	src/push_sort_three.c \
	src/push_sort_five.c \
	src/split_input.c


O_DIR= obj/
OBJ= $(SRC:%.c=$(O_DIR)%.o)

NAME= push_swap

LIBFT= libft/libft.a
LIBPATH= libft/

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(LIBFT) -o $(NAME)
	@echo -n "\033[32m\nSuccessfully Generated \033[0mPush Swap \n\n"

$(O_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	@echo "\033[95mCompiling\033[0m $(notdir $<)"
	@sleep 0.0001
	@$(CC) -c $< -o $@

$(LIBFT):
	@make --no-print-directory -C $(LIBPATH) printf

clean:
	@echo "\033[95mCleansing Push Swap Objects"
	@sleep 0.7
	@echo -n "."
	@sleep 0.2
	@echo -n "."
	@sleep 0.2
	@echo ".\033[0m"
	@sleep 0.2
	@make --no-print-directory -C $(LIBPATH) clean
	@rm -rf $(O_DIR)

fclean:
	@echo "\033[95mCleansing Push Swap"
	@sleep 0.7
	@echo -n "."
	@sleep 0.2
	@echo -n "."
	@sleep 0.2
	@echo ".\033[0m"
	@sleep 0.2
	@make --no-print-directory -C $(LIBPATH) fclean
	@rm -rf $(O_DIR)
	@rm -f $(S_NAME) $(C_NAME)

re: fclean all

.PHONY: $(LIBFT) re fclean clean