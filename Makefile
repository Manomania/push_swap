########################################################################################################################
#                                                      VARIABLES                                                       #
########################################################################################################################\

NAME				=	push_swap
HEADER				=	push_swap.h
CC 					= 	gcc
CFLAGS 				= 	-Wall -Wextra -Werror -g3
AR					=	ar rcs
RM					=	rm -f

SRC_F				=	main \
						chained_list \
						check_args \
						stack_utils \
						sort_three \
						sort_stack \
						push \
						swap \
						rotate \
						rev_rotate


SRC					=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_F)))
OBJ 				= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_F)))

########################################################################################################################
#                                                      DIRECTORY                                                       #
########################################################################################################################

SRC_DIR				=	src/
OBJ_DIR				=	obj/
INC_DIR				=	.

########################################################################################################################
#                                                         LIB                                                          #
########################################################################################################################

LIBFT_DIR			=	super_libft/
LIBFT				=	$(LIBFT_DIR)libft.a

########################################################################################################################
#                                                      TARGETS                                                         #
########################################################################################################################

all:					$(LIBFT) $(NAME)

clean:
								@echo "$(RED)[$(OBJ_DIR)]:$(DEF_COLOR)"
								@rm -rf $(OBJ_DIR)
								@echo "$(GREEN)=> Deleted!\n$(DEF_COLOR)"
								@echo "$(RED)[$(LIBFT_DIR)$(OBJ_DIR)]:$(DEF_COLOR)"
								@$(MAKE) --silent -C $(LIBFT_DIR) clean
								@echo "$(GREEN)=> Deleted!\n$(DEF_COLOR)"

fclean: 				clean
								@echo "$(RED)[$(NAME)]:$(DEF_COLOR)"
								@$(RM) $(NAME)
								@echo "$(GREEN)=> Deleted!\n$(DEF_COLOR)"
								@echo "$(RED)[$(LIBFT)]:$(DEF_COLOR)"
								@$(MAKE) --silent -C $(LIBFT_DIR) fclean
								@echo "$(GREEN)=> Deleted!\n$(DEF_COLOR)"

re: 					fclean all

.PHONY: 				all bonus clean fclean re

########################################################################################################################
#                                                       COMMANDS                                                       #
########################################################################################################################

$(NAME):				$(LIBFT) $(OBJ)
							@echo "$(YELLOW)[$(NAME)]:$(DEF_COLOR)"
							@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $@
							@echo "$(GREEN)=> Success!\n$(DEF_COLOR)"

$(LIBFT):
							@$(MAKE) --silent -C $(LIBFT_DIR)

$(OBJ_DIR)%.o: 			$(SRC_DIR)%.c $(HEADER)
							@mkdir -p $(OBJ_DIR)
							@$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_DIR)include/ -c $< -o $@

########################################################################################################################
#                                                      COLOURS                                                         #
########################################################################################################################

DEF_COLOR			=	\033[0;39m
ORANGE				=	\033[0;33m
GRAY				=	\033[0;90m
RED					=	\033[0;91m
GREEN				=	\033[1;92m
YELLOW				=	\033[1;93m
BLUE				=	\033[0;94m
MAGENTA				=	\033[0;95m
CYAN				=	\033[0;96m
WHITE				=	\033[0;97m
