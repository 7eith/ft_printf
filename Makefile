# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/11/13 17:33:58 by amonteli     #+#   ##    ##    #+#        #
#    Updated: 2019/12/02 15:08:38 by amonteli    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME		=		libftprintf.a

HEADERS		=		includes/

SRCS 		=		srcs/ft_printf.c	\
					srcs/checker.c		\
					srcs/parser.c		\
					srcs/ft_strreplace.c\

FLAGS 		= 		-Wall -Wextra -Werror -g

OBJ			= 		$(SRCS:.c=.o)

LIB 		= 		libft/libft.a

all			: 		$(NAME)

$(LIB)		:
		@make -C libft

$(NAME): $(LIB) $(OBJ)
		@cp libft/libft.a $(NAME)
		@ar rcs $(NAME) $(OBJ) $(LIB)
		@echo "\033[90m[\033[32mft_printf\033[90m]\033[32m Successfully compiled ft_printf.\033[0m"

%.o: %.c
		@$(CC) -I $(HEADERS) -o $@ -c $< $(FLAGS)

clean		:
		@/bin/rm -f $(OBJS)
		@make clean -C libft
		@echo "\033[90m[\033[91mft_printf\033[90m]\033[31m Deleted *.o\033[0m"

fclean		:		clean
		@/bin/rm -f $(NAME)
		@make fclean -C libft
		@echo "\033[90m[\033[91mft_printf\033[90m]\033[31m Deleted $(NAME)\033[0m"

re			:		fclean all

run			:		all
		@gcc -Wall -Werror -Wextra -g libftprintf.a main.c -o printf
		@clear
		@./printf

norme		:
		@norminette srcs/*.c
		@echo "\033[91m============ LIBFT ============\033[0m"
		@norminette libft/*.c libft/*.h
