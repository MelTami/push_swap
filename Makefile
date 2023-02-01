# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 21:02:27 by mvavasso          #+#    #+#              #
#    Updated: 2023/02/01 14:21:03 by mvavasso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap

CFLAGS			= -Wall -Werror -Wextra

RM				= rm -rf
			
PATH_INCLUDES	= ./includes/
PATH_OBJS		= ./objects/
PATH_SRCS		= ./sources/
PATH_LIBFT		= ./libft

SRCS			= $(addprefix $(PATH_SRCS), \
					main.c \
					ft_error.c \
					ft_check.c \
					stack.c)
LFLAGS			= -L $(PATH_LIBFT) -lft
OBJS 			= $(patsubst $(PATH_SRCS)%.c, $(PATH_OBJS)%.o, $(SRCS))
INCLUDES		= -I $(PATH_INCLUDES)

all:	$(NAME)

$(NAME): $(OBJS)
	@ make -C $(PATH_LIBFT)
	@ clang $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME)
	@ echo -e '\033[0;32m[SUCCESS]\033[0m Compilation done!'

$(PATH_OBJS)%.o: $(PATH_SRCS)%.c
	@ mkdir -p $(PATH_OBJS)
	@ clang $(CFLAGS) $(INCLUDES) -c $< -o $@
	
clean:
	@ $(RM) $(PATH_OBJS)
	@ make clean -C $(PATH_LIBFT)
	@ echo -e '\033[0;33mObjects removed\033[0m'

fclean:	clean
	@ $(RM) $(NAME)
	@ make fclean -C $(PATH_LIBFT)
	@ echo -e '\033[0;33mEverything is clean\033[0m'

re:		fclean all

.PHONY: all clean fclean re