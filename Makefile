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

SHELL := bash

#==============================================================================#
#                                     NAMES                                    #
#==============================================================================#

USER			= passunca
NAME			= fractol
UNAME 			= $(shell uname)

### Message Vars
_NAME	 		= [$(MAG)fract'ol$(D)]
_LIBFT	 		= [$(MAG)libft$(D)]
_MLX	 		= [$(MAG)mlx$(D)]
_SUCCESS 		= [$(GRN)SUCCESS$(D)]
_INFO 			= [$(BLU)INFO$(D)]
_NORM 			= [$(MAG)Norminette$(D)]
_NORM_SUCCESS 	= $(GRN)=== OK:$(D)
_NORM_INFO 		= $(BLU)File no:$(D)
_NORM_ERR 		= $(RED)=== KO:$(D)

#==============================================================================#
#                                    PATHS                                     #
#==============================================================================#

SRC_PATH	= src
LIBS_PATH	= lib
BUILD_PATH	= .build
LIBFT_PATH	= $(LIBS_PATH)/libft
MLX_PATH 	= $(LIBS_PATH)/mlx

### Files
SRC			= $(addprefix $(SRC_PATH)/, main.c ft_usage.c ft_sets.c ft_kill.c \
			  ft_render.c ft_math.c ft_init.c ft_args.c ft_utils.c ft_ui.c \
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

bonus: all			## Compile fractol with bonus features
	@echo "[Compiled $(MAG)fractol$(D) $(YEL)with bonus!$(D)] $(_SUCCESS) $(YEL)🖔$(D)"

$(BUILD_PATH)/%.o: $(SRC_PATH)/%.c
	@echo -n "$(MAG)█$(D)"
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_PATH):
	@echo "[$(BCYA)Setting up$(D) $(BUILD_PATH) path]"
	$(MKDIR_P) $(BUILD_PATH)

$(NAME): $(BUILD_PATH) $(LIBFT_ARC) $(MLX_ARC) $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_ARC) $(MLX_ARC) $(MLXFLAGS) -o $(NAME)
	@echo "* Compiling $(_NAME) executable : $(_SUCCESS) $(YEL)🖔$(D)"

$(LIBFT_ARC):
	@echo "[$(BCYA)Building$(D) $(_LIBFT) $(BCYA)module$(D)]"
	$(MAKE) $(LIBFT_PATH) extra

$(MLX_ARC):
	@echo "[$(BCYA)Building$(D) $(_MLX) $(BCYA)module$(D)]"
	$(MAKE) $(MLX_PATH)

deps:			## Download/Update libft & mlx
	@echo "[$(BCYA)Getting$(D) $(_NAME) $(BCYA)dependencies$(D)]"
	@if test ! -d "$(LIBFT_PATH)"; then make get_libft; \
		else echo "$(YEL)[libft]$(D) folder found"; fi
	@if test ! -d "$(MLX_PATH)"; then make get_mlx; \
		else echo "$(YEL)[mlx]$(D) folder found"; fi
	@echo " $(RED)$(D) [$(GRN)Nothing to be done!$(D)] $(YEL)🖔$(D)"

-include $(DEPS)

get_mlx: 
	@echo "[$(BCYA)Getting$(D) $(_MLX) $(BCYA)submodule$(D)]"
	git clone git@github.com:42Paris/minilibx-linux.git $(MLX_PATH)
	@echo "* $(_MLX) submodule download : $(_SUCCESS) $(YEL)🖔$(D)"

get_libft:
	@echo "[$(BCYA)Getting$(D) $(_LIBFT) $(BCYA)submodule$(D)]"
	git clone git@github.com:PedroZappa/42_libft.git $(LIBFT_PATH)
	@echo "* $(_LIBFT) submodule download : $(_SUCCESS) $(YEL)🖔$(D)"

update_modules:
	@echo "* $(BCYA)Updating submodules$(D)"
	git submodule init
	git submodule update --recursive --remote
	@echo "* Submodules update : $(_SUCCESS) $(YEL)🖔$(D)"

##@ Test, Debug & Leak Check Rules 󰃢

norm: ## Run norminette test
	@printf "${_NORM}\n"
	@ls $(SRC_PATH) | wc -l > norm_ls.txt
	@printf "$(_NORM_INFO) $$(cat norm_ls.txt)\n"
	@printf "$(_NORM_SUCCESS) "
	@norminette $(SRC_PATH) | grep -wc "OK" > norm.txt; \
	if [ $$? -eq 1 ]; then \
		echo "0" > norm.txt; \
	fi
	@printf "$$(cat norm.txt)\n"
	@if ! diff -q norm_ls.txt norm.txt > /dev/null; then \
		printf "$(_NORM_ERR) "; \
		norminette $(SRC_PATH) | grep -v "OK" > norm_err.txt; \
		cat norm_err.txt | grep -wc "Error:" > norm_errn.txt; \
		printf "$$(cat norm_errn.txt)"; \
		printf "$$(cat norm_err.txt)"; \
	else \
		printf "[$(YEL)Everything is OK$(D)]\n"; \
	fi

valgrind: 		## Check for leaks w/ valgrind
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) mandelbrot 42


##@ Clean-up Rules 󰃢

clean: 			## Remove object files
	@echo "* Cleaning $(_NAME) objects 󰃢"
	$(RM) $(OBJS)
	@echo "* $(YEL)Cleaning $(_LIBFT) objects$(D) 󰃢"
	$(MAKE) $(LIBFT_PATH) clean
	@echo "* $(YEL)Removing $(BUILD_PATH)$(D) 󰃢"
	$(RM) $(BUILD_PATH)
	@echo "* $(YEL)Removing $(BUILD_PATH)$(D) : $(_SUCCESS)"
	$(RM) norm.txt norm_ls.txt norm_err.txt norm_errn.txt
	@echo "* $(YEL)Removing Norminette temp files:$(D) $(_SUCCESS)"

fclean: clean	## Remove archives & executables
	@echo "[$(RED)Cleaning executable 󰃢$(D)]"
	$(RM) $(NAME)
	$(MAKE) $(LIBFT_PATH) fclean
	@echo "* $(_NAME) removed!"

libclean: fclean	## Remove libft & mlx
	@echo "[$(RED)Cleaning libft 󰃢$(D)]"
	$(RM) $(LIBFT_PATH)
	@echo "* $(_LIBFT) removed : $(_SUCCESS)"
	$(RM) $(MLX_PATH)
	@echo "* $(_MLX) removed : $(_SUCCESS)"
	$(RM) $(LIBS_PATH)
	@echo "* [$(MAG)$(LIBS_PATH)$(D)] folder removed : $(_SUCCESS)"

re: fclean all	## Purge and Recompile
	@echo "* $(_NAME) Recompiled : $(_SUCCESS)$(D) $(YEL)🖔$(D)"

##@ Help 󰛵

.PHONY: help
help: 			## Display this help page
	@awk 'BEGIN {FS = ":.*##"; \
			printf "\n=> Usage:\n\tmake $(GRN)<target>$(D)\n"} \
		/^[a-zA-Z_0-9-]+:.*?##/ { \
			printf "\t$(GRN)%-15s$(D) %s\n", $$1, $$2 } \
		/^##@/ { \
			printf "\n=> %s\n", substr($$0, 5) } ' Makefile
## Tweaked from source:
### https://www.padok.fr/en/blog/beautiful-makefile-awk

.PHONY: deps get_mlx get_libft update_modules norm valgrind clean \
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
