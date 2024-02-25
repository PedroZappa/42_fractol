# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 09:27:39 by passunca          #+#    #+#              #
#    Updated: 2024/02/14 14:41:44 by passunca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==============================================================================#
#                                  MAKE CONFIG                                 #
#==============================================================================#

SHELL := zsh

#==============================================================================#
#                                     NAMES                                    #
#==============================================================================#

USER			= passunca
NAME			= fractol
UNAME 			= $(shell uname)

### Message Vars
_SUCCESS 		= [$(GRN)SUCCESS$(D)]
_INFO 			= [$(BLU)INFO$(D)]
_NORM 			= [$(YEL)Norminette$(D)]
_NORM_SUCCESS 	= $(GRN)\tOK:$(D)
_NORM_INFO 		= $(BLU)File no:$(D)

#==============================================================================#
#                                    PATHS                                     #
#==============================================================================#

SRC_PATH	= src
INC_PATH	= inc
BUILD_PATH	= .build
LIBFT_PATH	= $(INC_PATH)/libft
MLX_PATH 	= $(INC_PATH)/mlx

### Files
SRC			= $(addprefix $(SRC_PATH)/, main.c ft_help.c ft_sets.c ft_kill.c \
			  ft_render.c ft_math.c ft_mlx.c ft_args.c ft_utils.c ft_ui.c \
			  ft_sets_newton.c ft_events_mouse.c ft_events_keys.c ft_color.c)

OBJS		= $(SRC:$(SRC_PATH)/%.c=$(BUILD_PATH)/%.o)
DEPS		= $(OBJS:.o=.d)

### Archives
LIBFT_ARC	= $(LIBFT_PATH)/libft.a
MLX_ARC		= $(MLX_PATH)/libmlx.a

#==============================================================================#
#                              COMPILER & FLAGS                                #
#==============================================================================#

CC		= cc

CFLAGS		= -Wall -Werror -Wextra
CFLAGS		+= -g
CFLAGS		+= -lm
CFLAGS 		+= -O3
# Enables fastm memory error detection
FSANITIZE := -fsanitize=address

ifeq ($(shell uname), Linux)
	MLXFLAGS		+= -lXext -lX11
else
	MLXFLAGS		+= -L./inc/mlx -framework OpenGL -framework AppKit
endif

#==============================================================================#
#                                COMMANDS                                      #
#==============================================================================#

AR			= ar rcs
RM			= rm -rf
MKDIR_P		= mkdir -p

MAKE		= make -C

#==============================================================================#
#                                  RULES                                       #
#==============================================================================#

##@ Fract'ol Compilation Rules 🏗

all: deps $(NAME)		## Compile Fract'ol

$(BUILD_PATH)/%.o: $(SRC_PATH)/%.c
	@echo -n "$(MAG)█$(D)"
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_PATH):
	$(MKDIR_P) $(BUILD_PATH)

$(NAME): $(BUILD_PATH) $(OBJS) $(LIBFT_ARC) $(MLX_ARC)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_ARC) $(MLX_ARC) $(MLXFLAGS) -o $(NAME)

$(LIBFT_ARC):
	$(MAKE) $(LIBFT_PATH) extra
	@printf "$(D)$(B)$(BLU)\nlibft compiled\n\n$(D)"

$(MLX_ARC):
	$(MAKE) $(MLX_PATH)
	@printf "$(D)$(B)$(BLU)\nmlx compiled\n\n$(D)"

deps:			## Download/Update libft & mlx
	@if test ! -d "$(LIBFT_PATH)"; then make get_libft; \
		else echo "$(YEL)[libft]$(D) folder found"; fi
	@if test ! -d "$(MLX_PATH)"; then make get_mlx; \
		else echo "$(YEL)[mlx]$(D) folder found"; fi
	@echo " $(RED)$(D) [$(GRN)Nothing to be done!$(D)]"

-include $(DEPS)

get_mlx: compile_mlx	## Get MLX module
	@echo "[$(CYA)Getting MLX submodule$(D)]"
	git clone git@github.com:42Paris/minilibx-linux.git $(MLX_PATH)
	@echo "[$(GRN)MLX submodule successfully downloaded$(D)]"

compile_mlx:	## Compile MLX module
	$(MAKE) $(MLX_PATH) > /dev/null 2>&1 || true
	@printf "[$(B)$(CYA)$(MLX_ARC) successfully compiled$(D)]\n"

get_libft:		## Get Libft module
	@echo "[$(CYA)Getting Libft submodule$(D)]"
	git clone git@github.com:PedroZappa/libft.git $(LIBFT_PATH)
	@echo "[$(GRN)Libft submodule successfully downloaded$(D)]"

update_modules:	## Update modules
	@echo "[$(CYA)Updating submodules$(D)]"
	git submodule init
	git submodule update --recursive --remote
	@echo "[$(GRN)Submodules successfully updated$(D)]"

##@ Test, Debug & Leak Check Rules 󰃢

valgrind: 		## Check for leaks w/ valgrind
	@valgrind -q --leak-check=full --show-leak-kinds=all ./$(NAME)

norm: 		## Run norminette test
	@printf "${_NORM}\n"
	@printf "${_NORM_INFO} "
	@norminette $(SRC_PATH) | wc -l
	@norminette $(SRC_PATH)
	@printf "${_NORM_SUCCESS} "
	@norminette $(SRC_PATH) | grep -wc "OK"


##@ Clean-up Rules 󰃢

clean: 			## Remove object files
	@echo "[$(RED)Cleaning $(NAME) objects 󰃢$(D)]"
	$(RM) $(OBJS)
	@echo "[$(RED)Cleaning Libft objects 󰃢$(D)]"
	$(MAKE) $(LIBFT_PATH) clean
	@echo "[$(RED)Removing $(BUILD_PATH) 󰃢$(D)]"
	$(RM) $(BUILD_PATH)
	@echo "==> $(GRN)Object files successfully removed!$(D)\n"

fclean: clean	## Remove archives & executables
	@echo "[$(RED)Cleaning executable 󰃢$(D)]"
	$(RM) $(NAME)
	$(MAKE) $(LIBFT_PATH) fclean
	@echo "==> $(GRN)$(NAME) Successfully removed!$(D)\n"

libclean: fclean	## Remove libft & mlx
	@echo "[$(RED)Cleaning libft 󰃢$(D)]"
	$(RM) $(LIBFT_PATH)
	@echo "==> $(GRN)libft successfully removed!$(D)\n"
	$(RM) $(MLX_PATH)
	@echo "==> $(GRN)mlx successfully removed!$(D)\n"
	$(RM) $(INC_PATH)
	@echo "==> $(GRN)inc folder successfully removed!$(D)\n"

re: fclean all	## Purge and Recompile

##@ Help 󰛵

.PHONY: help
help: 			## Display this help page
	@awk 'BEGIN {FS = ":.*##"; \
			printf "\n=> Usage:\n\tmake $(GRN)<target>$(D)\n"} \
		/^[a-zA-Z_0-9-]+:.*?##/ { \
			printf "\t$(GRN)%-15s$(D) %s\n", $$1, $$2 } \
		/^##@/ { \
			printf "\n=> %s\n", substr($$0, 5) } ' Makefile

.PHONY: deps get_mlx compile_mlx get_libft update_modules valgrind clean \
	fclean libclean re

#==============================================================================#
#                                  UTILS                                       #
#==============================================================================#

# Colors
#
# Run the following command to get list of available colors
# bash -c 'for c in {0..255}; do tput setaf $c; tput setaf $c | cat -v; echo =$c; done'
#
B  		= $(shell tput bold)
BLA		= $(shell tput setaf 0)
RED		= $(shell tput setaf 1)
GRN		= $(shell tput setaf 2)
YEL		= $(shell tput setaf 3)
BLU		= $(shell tput setaf 4)
MAG		= $(shell tput setaf 5)
CYA		= $(shell tput setaf 6)
WHI		= $(shell tput setaf 7)
GRE		= $(shell tput setaf 8)
BRED 	= $(shell tput setaf 9)
BGRN	= $(shell tput setaf 10)
BYEL	= $(shell tput setaf 11)
BBLU	= $(shell tput setaf 12)
BMAG	= $(shell tput setaf 13)
BCYA	= $(shell tput setaf 14)
BWHI	= $(shell tput setaf 15)
D 		= $(shell tput sgr0)
BEL 	= $(shell tput bel)
CLR 	= $(shell tput el 1)
