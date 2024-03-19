# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 17:56:10 by raveriss          #+#    #+#              #
#    Updated: 2023/03/24 10:14:55 by raveriss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### INCLUDES ###

INCLUDES	= push_swap.h
INCLUDES_B	= push_swap_bonus.h get_next_line.h

### SOURCES ###

SRC = push_swap.c \
	init.c \
	instruc_swap_or_push.c \
	instruc_rev_or_rot.c \
	instruc_dual.c \
	sorting_simple.c \
	optimization.c \
	sorting_quartile.c \
	init_edit_rot_rev_cmd.c \

SRC_B = checker.c \
	checker_utils.c \
	get_next_line.c \
	get_next_line_utils.c \
	instruc_swa_or_pus_bonus.c \
	instruc_rev_or_rot_bonus.c \
	instruc_dual_bonus.c \

SOURCES		= $(addprefix $(SRCFLDR), $(SRC))
SOURCES_B	= $(addprefix $(SRCFLDR_B), $(SRC_B))

OBJECTS		= $(addprefix $(SRCFLDR), $(OBJS))
OBJECTS_B	= $(addprefix $(SRCFLDR_B), $(OBJS_B))

### FOLDER PATH ###

SRCFLDR = 	sources/
SRCFLDR_B =	sources_bonus/

### MACROS ###

NAME 	= push_swap
NAME_B	= checker

OBJS	= $(SOURCES:.c=.o)
OBJS_B	= $(SOURCES_B:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

### RULES ###

$(NAME): $(OBJS) $(INCLUDES) Makefile
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
$(NAME_B): $(OBJS_B) $(INCLUDES_B)
	$(CC) $(CFLAGS) $(OBJS_B) -o $(NAME_B)

all : $(NAME) $(NAME_B)

bonus : $(NAME_B)

.objects/%.o: %.c
	${CC} ${CFLAGS} -c $<

clean:
	rm -f $(OBJS) $(OBJS_B)

fclean:
	rm -f $(OBJS) $(OBJS_B) $(NAME) $(NAME_B)

re: fclean all

.PHONY: all clean fclean re bonus
