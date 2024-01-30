# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 09:27:39 by passunca          #+#    #+#              #
#    Updated: 2024/01/30 11:18:58 by passunca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==============================================================================#
#                                NAMES & PATHS                                  #
#==============================================================================#

NAME		=	fractol

SRC_PATH	= src
LIBFT_PATH = ./libft

SRC			= $(addprefix $(SRC_PATH)/ )

OBJS		= $(SRC:.c=.o)

#==============================================================================#
#                            FLAGS & CMDS                                      # 
#==============================================================================#

CC		= cc

CFLAGS	= -Wall -Werror -Wextra -g -03
MLXFLAGS = -lX11 -lXext -lm

INC		= -I.

AR		= ar rcs
RM		= rm -rf

MAKE	= make -C

#==============================================================================#
#                                  LIBS                                        # 
#==============================================================================#





#==============================================================================#
#                                  RULES                                       # 
#==============================================================================#

##@ Help 󰛵

.PHONY: help
help: 			## Display this help page
	@awk 'BEGIN {FS = ":.*##"; \
			printf "\n=> Usage:\n\tmake $(GRN)<target>$(NC)\n"} \
		/^[a-zA-Z_0-9-]+:.*?##/ { \
			printf "\t$(GRN)%-15s$(NC) %s\n", $$1, $$2 } \
		/^##@/ { \
			printf "\n=> %s\n", substr($$0, 5) } ' Makefile

##@ Fract'ol Compilation Rules 🏗

all: $(NAME)

.PHONY: fractol
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(INC) -o $@ $^


.PHONY: deps
deps:			## Check if libft & mlx folder exist
	if [ -d "libft" ]; then echo "libft folder found"; else make get_libft; fi
	if [ -d "mlx" ]; then echo "mlx folder found"; else make get_mlx; fi

.PHONY: get_mlx
get_mlx:		## Get MLX submodule
	git clone git@github.com:42Paris/minilibx-linux.git mlx
	git submodule --init
	git submodule update --recursive --remote

.PHONY: get_libft
get_libft:		## Get Libft submodule
	git clone git@github.com:PedroZappa/libft.git
	git submodule --init
	git submodule update --recursive --remote

##@ Clean-up Rules 󰃢

.PHONY: clean
clean:
	@$(RM) $(OBJS)

.PHONY: fclean
fclean: clean
	@$(RM) $(NAME)

.PHONY: re
re: fclean all

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
GRN		= $(shell tput setaf 10)
BYEL	= $(shell tput setaf 11)
BBLU	= $(shell tput setaf 12)
BMAG	= $(shell tput setaf 13)
BCYA	= $(shell tput setaf 14)
BWHI	= $(shell tput setaf 15)
D 		= $(shell tput sgr0)
BEL 	= $(shell tput bel)
CLR 	= $(shell tput el 1)


# Loading Bar Function
define	progress_bar
	i=0
	while [[ $$i -le $(words $(SRCS)) ]] ; do \
		printf " " ; \
		((i = i + 1)) ; \
	done
	printf "$(B)]\r[$(GRE)"
endef
