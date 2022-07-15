# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/10 02:09:58 by matcardo          #+#    #+#              #
#    Updated: 2022/07/15 05:25:38 by matcardo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex

SRCS		= ./src/pipex.c
OBJSDIR 	= .objs
OBJS		= ${SRCS:.c=.objs/%.o}
#OBJS		= ${SRCS:.c=.o}
HEADER		= ./src/pipex.h

RM			= rm -f
CC			= gcc
FLAGS		= -Wall -Wextra -Werror

LIBFT		= ./libraries/libft/libft.a

LEAKS 		= valgrind
LEAKS_FILE	= valgrind-out.txt
LF 			= --leak-check=full \
        		--show-leak-kinds=all \
        		--track-origins=yes \
        		--verbose \
        		--log-file=$(LEAKS_FILE) \
        		./pipex

all: $(NAME)

.objs/%.o:
		$(CC) $(FLAGS) -c $< -o $@

$(OBJSDIR):
		mkdir -p $(OBJSDIR)
		
$(LIBFT):
		make -C ./libraries/libft

$(NAME): $(OBJSDIR) $(OBJS) $(LIBFT)
		$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT) -I./srcs

norm:
	norminette ${SRCS} ${HEADER}

leaks: 
	$(LEAKS) $(LF)

clean:
		make -C ./libraries/libft clean
		$(RM) $(OBJS)

fclean:	clean
		make -C ./libraries/libft fclean
		$(RM) $(NAME)

re:			fclean all

#rebonus:	fclean bonus

.PHONY:		all clean fclean re #rebonus bonus
