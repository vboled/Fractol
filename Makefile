# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gweasley <rfork@student.42.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/05 17:09:20 by rfork             #+#    #+#              #
#    Updated: 2020/01/13 20:23:37 by dovran           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#GCC = gcc -Wall -Wextra -Werror -g -MMD

SRCDIR	= ./src/
INCDIR	= ./includes/
OBJDIR	= ./obj/

GCC = gcc -g -MMD
NAME = fractol
SRCS = main.c \
		struct_work.c \
		window_work.c \
		image_work.c \
		fractol.c \
		conversation.c \
		color.c 
OBJS = $(addprefix $(OBJDIR), $(SRCS:.c=.o))
DEPENDS = ${OBJS:.o=.d} 
HEAD = -I./includes/

ifeq ($(OS),Windows_NT)
	detected_OS := Windows
else
	detected_OS := $(shell uname)
endif
ifeq ($(detected_OS),Linux)
	MAKES := ./libft/libft.a  libs/minilibx/libmlx.a
	LIBMAKE := libs/minilibx
	LIB :=  -L libft -lft -L libs/minilibx -lmlx_Linux -lXext -lX11 -lm
	HEAD += -I./libs/minilibx/
endif
ifeq ($(detected_OS),Darwin) 
	MAKES = ./libs/libft.a ./libs/minilibx_macos/libmlx.a 
	LIBMAKE := libs/minilibx_macos
	LIB := -L libft -lft -L libs/minilibx_macos -lmlx -framework OpenGL -framework Appkit
	HEAD += -I./libs/minilibx_macos/
endif

.PHONY: clean fclean re
all: $(NAME) 

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(GCC) -o $@ -c  $(HEAD) $<

$(MAKES):
	make -C  ./libft
	make -sC  $(LIBMAKE)

-include ${DEPENDS}

$(NAME): $(MAKES) $(OBJS)
	$(GCC) $(OBJS)  $(LIB) $(HEAD)  -o $(NAME)

clean:
	rm -f $(OBJS)
	rm -f *.d
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean
	make -C $(LIBMAKE) clean

re: fclean all
