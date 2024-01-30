# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 09:27:39 by passunca          #+#    #+#              #
#    Updated: 2024/01/30 10:37:36 by passunca         ###   ########.fr        #
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

CFLAGS	= -Wall -Werror -Wextra -g
CFLAGS 	+= -03

INC		= -I.

AR		= ar rcs
RM		= rm -rf


#==============================================================================#
#                                  LIBS                                        # 
#==============================================================================#



#==============================================================================#
#                                  RULES                                       # 
#==============================================================================#

.o:.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@





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
