########################################################################################################################
#                                                      VARIABLES                                                       #
########################################################################################################################\

AUTHOR				=	maximart
NAME				=	push_swap
HEADER				=	$(INC_DIR)push_swap.h
CC 					= 	cc
CFLAGS 				= 	-Wall -Wextra -Werror
AR					=	ar rcs
RM					=	rm -f

SRC_F				=	algorithm \
						chained_list \
						check_args \
						check_error \
						fill_data \
						ft_sort \
						get_data \
						main \
						operations_in_stack \
						push \
						quick_sort \
						rev_rotate \
						rotate \
						sort_three \
						stack_is_sorted \
						stack_utils \
						swap

SRC					=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_F)))
OBJ 				= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_F)))

########################################################################################################################
#                                                      DIRECTORY                                                       #
########################################################################################################################

SRC_DIR				=	./
OBJ_DIR				=	obj/
INC_DIR				=	./

########################################################################################################################
#                                                         LIB                                                          #
########################################################################################################################

LIBFT_DIR			=	libft/
LIBFT				=	$(LIBFT_DIR)libft.a

########################################################################################################################
#                                                       TARGETS                                                        #
########################################################################################################################

all:					.print_header $(LIBFT) $(NAME)

clean:					.print_header
							@printf "%$(SPACEMENT)b%b" "$(BLUE)[$(OBJ_DIR)]:" "$(GREEN)[✓]$(DEF_COLOR)\n"
							@rm -rf $(OBJ_DIR)
							@printf "$(RED)=> Deleted!$(DEF_COLOR)\n"
							@printf "\n"
							@printf "%$(SPACEMENT)b%b" "$(BLUE)[$(LIBFT_DIR)$(OBJ_DIR)]:" "$(GREEN)[✓]$(DEF_COLOR)\n"
							@$(MAKE) --silent -C $(LIBFT_DIR) clean
							@printf "$(RED)=> Deleted!\n$(DEF_COLOR)\n"

fclean: 				clean
							@printf "%$(SPACEMENT)b%b" "$(BLUE)[$(NAME)]:" "$(GREEN)[✓]$(DEF_COLOR)\n"
							@$(RM) $(NAME)
							@printf "$(RED)=> Deleted!$(DEF_COLOR)\n"
							@printf "\n"
							@printf "%$(SPACEMENT)b%b" "$(BLUE)[$(LIBFT)]:"  "$(GREEN)[✓]$(DEF_COLOR)\n"
							@$(MAKE) --silent -C $(LIBFT_DIR) fclean
							@printf "$(RED)=> Deleted!$(DEF_COLOR)\n"
							$(call SEPARATOR)

make_libft:
							@$(MAKE) --silent -C $(LIBFT_DIR)

re: 					.print_header fclean $(LIBFT) $(NAME)

.print_header:
							$(call DISPLAY_TITLE)
							$(call SEPARATOR)
							$(call BUILD)
							$(call SEPARATOR)

.PHONY: 				all clean fclean make_libft re

########################################################################################################################
#                                                       COMMANDS                                                       #
########################################################################################################################

$(NAME):				$(LIBFT) $(OBJ)
							@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $@

$(LIBFT):				make_libft

$(OBJ_DIR)%.o: 			$(SRC_DIR)%.c $(HEADER)
							@mkdir -p $(OBJ_DIR)
							@$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_DIR)$(INC_DIR) -c $< -o $@
							$(call PROGRESS_BAR_PERCENTAGE)
							$(if $(filter $(COMPILED_SRCS),$(SRCS_TO_COMPILE)),$(call SEPARATOR))

########################################################################################################################
#                                                       COLOURS                                                        #
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

########################################################################################################################
#                                                       DISPLAY                                                        #
########################################################################################################################

SPACEMENT			=	-40
COMPILED_SRCS		=	0
FRAMES				=	⠋ ⠙ ⠹ ⠸ ⠼ ⠴ ⠦ ⠧ ⠇ ⠏
SLEEP_FRAME			=	0.001

SRCS_TO_COMPILE		=	$(shell find -maxdepth 1 -newer $(NAME) -name '*.c' 2>/dev/null | wc -l)
ifeq ($(SRCS_TO_COMPILE),0)
	SRCS_TO_COMPILE =	$(words $(SRC_F))
endif

define PROGRESS_BAR_PERCENTAGE
						$(eval COMPILED_SRCS := $(shell expr $(COMPILED_SRCS) + 1))
						@if [ $(COMPILED_SRCS) -eq 1 ]; then \
							printf "$(BLUE)[$(NAME)]:$(DEF_COLOR)\n"; \
						fi
						@percentage=$$(echo "scale=0; $(COMPILED_SRCS) * 100 / $(SRCS_TO_COMPILE)" | bc); \
						for frame in $(FRAMES); do \
							printf "\r$$frame Compiling... [%d/%d] %d%%" $(COMPILED_SRCS) $(SRCS_TO_COMPILE) $$percentage; \
							sleep $(SLEEP_FRAME); \
						done; \
						if [ $(COMPILED_SRCS) -eq $(SRCS_TO_COMPILE) ]; then \
							printf "%-42b%b" "\r$(GREEN)Compilation finished [$(COMPILED_SRCS)/$(SRCS_TO_COMPILE)]" "$(GREEN)[✓]$(DEF_COLOR)\n"; \
						fi
endef

#TITLE ASCII ART - SLANT
define	DISPLAY_TITLE
						@echo "$(RED)        ____  __  _______ __  __            ______       _____    ____ "
						@echo "$(ORANGE)       / __ \\/ / / / ___// / / /           / ___/ |     / /   |  / __ \\"
						@echo "$(YELLOW)      / /_/ / / / /\\__ \\/ /_/ /            \\\\__ \\| | /| / / /| | / /_/ /"
						@echo "$(GREEN)     / ____/ /_/ /___/ / __  /            ___/ /| |/ |/ / ___ |/ ____/ "
						@echo "$(BLUE)    /_/    \\____//____/_/ /_/   ______   /____/ |__/|__/_/  |_/_/      "
						@echo "$(PURPLE)                               /_____/                                 $(DEF_COLOR)"
						@printf "\n"
endef

define	SEPARATOR
						@printf "\n"
						@echo "$(ORANGE)--------------------------------------------------------------------------$(DEF_COLOR)";
						@printf "\n"
endef

define	BUILD
						@printf "%-47b%b" "$(GREEN)AUTHOR:$(DEF_COLOR)" "$(AUTHOR)\n";
						@printf "%-47b%b" "$(GREEN)NAME:$(DEF_COLOR)" "$(NAME)\n";
						@printf "%-47b%b" "$(GREEN)CC:$(DEF_COLOR)" "$(CC)\n";
						@printf "%-47b%b" "$(GREEN)FLAGS:$(DEF_COLOR)" "$(CFLAGS)\n";
endef