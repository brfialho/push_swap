CC= cc -Werror -Wextra -Wall -I.

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
	src/sorting/calculate_loops.c \
	src/sorting/push_radix_sort.c \
	src/sorting/push_sort_five.c \
	src/sorting/push_sort_three.c \
	src/utils/error_handler.c \
	src/utils/init_stack_b.c \
	src/utils/push_cmp_isequal.c \
	src/utils/push_cmp_isgreater.c \
	src/utils/push_lst_size.c \
	src/validation/append_node.c \
	src/validation/assign_relative_value.c \
	src/validation/check_for_repeats.c \
	src/validation/format_list.c \
	src/validation/get_list.c \
	src/validation/is_sorted.c \
	src/validation/push_atol.c \
	src/validation/split_input.c


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
	@make --no-print-directory -C $(LIBPATH) fclean
	@echo "\033[95mCleansing Push Swap"
	@sleep 0.7
	@echo -n "."
	@sleep 0.2
	@echo -n "."
	@sleep 0.2
	@echo ".\033[0m"
	@sleep 0.2
	@rm -rf $(O_DIR)
	@rm -f $(NAME)

re: fclean all

.PHONY: $(LIBFT) re fclean clean