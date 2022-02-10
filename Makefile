# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/31 16:49:31 by elvmarti          #+#    #+#              #
#    Updated: 2022/02/10 17:07:13 by elvmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

HEADER = push_swap.h

SRCS = srcs/main.c \
		srcs/print_str.c \
		srcs/ps_lists.c \
		srcs/ps_lists2.c \
		srcs/rule_sx.c \
		srcs/rule_px.c \
		srcs/rule_rx.c \
		srcs/rule_rrx.c \
		srcs/sort_small.c \
		srcs/sort_big.c \
		srcs/min_max_num.c \
		srcs/chunks.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra -O3#-g3 -fsanitize=address

RM = rm -f

LIBFTPATH = ./libft/

LIBFTNAME = libft.a

LIBFT = $(LIBFTPATH)$(LIBFTNAME)

$(NAME): $(OBJS) $(LIBFT)
		@echo $(PURPLE)- Compiling - $(RESET)
		$(CC) ${CFLAGS} ${OBJS} -I $(HEADER) -L. ${LIBFT} -o ${NAME}

$(LIBFT):		
		@echo $(PURPLE)- Libft -$(RESET)
		make re -C $(LIBFTPATH)

all: $(NAME)

clean:
		@echo $(PURPLE)- Cleaning -$(RED)
		$(RM) $(OBJS) $(LIBFTPATH)*.o

fclean: clean
		$(RM) $(NAME) $(LIBFT)

re: fclean all

#Colors
BLACK		:="\033[0;30m"
RED			:="\033[0;31m"
GREEN		:="\033[0;32m"
BROWN		:="\033[0;33m"
BLUE		:="\033[0;34m"
PURPLE		:="\033[0;35m"
CYAN		:="\033[0;36m"
LIGHT_GRAY	:="\033[0;37m"
DARK_GRAY	:="\033[1;30m"
LIGHT_RED	:="\033[1;31m"
LIGHT_GREEN	:="\033[1;32m"
YELLOW		:="\033[1;33m"
LIGHT_BLUE	:="\033[1;34m"
LIGHT_PURPLE:="\033[1;35m"
LIGHT_CYAN	:="\033[1;36m"
WHITE		:="\033[1;37m"
RESET		:="\x1b[0m"

# VALGRIND
#         --leak-check=full \ Each individual leak will be shown in detail
#         --show-leak-kinds=all \ Show all of "definite, indirect, possible, reachable" leak kinds in the "full" report.
#         --track-origins=yes \ Favor useful output over speed. This tracks the origins of uninitialized values, which could be very useful for memory errors. Consider turning off if Valgrind is unacceptably slow.
#         --verbose \ Can tell you about unusual behavior of your program. Repeat for more verbosity.
#         --log-file=valgrind-out.txt \ Write to a file. Useful when output exceeds terminal space.
#         ./executable exampleParam1
# @valgrind --leak-check=full --track-origins=yes --log-file=./resources/info/valgrind-out.txt ./cub3D resources/maps/map01.cub --save || true
						
.PHONY: all clean fclean re
