# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/10 02:09:58 by matcardo          #+#    #+#              #
#    Updated: 2022/09/14 16:16:11 by matcardo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= pipex

SRCS			= $(wildcard src/*.c)
SRCS_BONUS		= $(wildcard src_bonus/*.c)
OBJS			= ${SRCS:src/%.c=objs/%.o}
OBJS_BONUS		= ${SRCS_BONUS:src_bonus/%.c=objs_bonus/%.o}
HEADER			= src/pipex.h
HEADER_BONUS	= src_bonus/pipex_bonus.h
OBJS_DIR		= objs/
OBJS_DIR_BONUS	= objs_bonus/

RM				= rm -fr
CC				= gcc
FLAGS			= -Wall -Wextra -Werror

LIBFT			= ./libraries/libft/libft.a

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS) $(LIBFT)
			$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(OBJS_DIR):
			mkdir $(OBJS_DIR)

objs/%.o: src/%.c
			${CC} ${FLAGS} -c $< -o ${<:src/%.c=objs/%.o}

$(LIBFT):
			make -C ./libraries/libft

bonus: $(OBJS_DIR_BONUS) $(OBJS_BONUS) $(LIBFT)
			$(RM) $(NAME)
			$(CC) $(FLAGS) -o $(NAME) $(OBJS_BONUS) $(LIBFT)

$(OBJS_DIR_BONUS):
			mkdir $(OBJS_DIR_BONUS)

objs_bonus/%.o: src_bonus/%.c
			${CC} ${FLAGS} -c $< -o ${<:src_bonus/%.c=objs_bonus/%.o}

norm:
			norminette ${SRCS} ${HEADER} ${SRCS_BONUS} ${HEADER_BONUS} 

clean:
			make -C ./libraries/libft clean
			$(RM) $(OBJS_DIR)
			$(RM) $(OBJS_DIR_BONUS)

fclean:	clean
			make -C ./libraries/libft fclean
			$(RM) $(NAME)

re:			fclean all

rebonus:	fclean bonus

.PHONY:		all clean fclean re bonus rebonus
