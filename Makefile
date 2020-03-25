# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/24 16:32:39 by lbellona          #+#    #+#              #
#    Updated: 2020/03/25 23:12:43 by timuryakubo      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES 	= main.c

WWW 		= -Wall -Wextra -Werror

NAME 		= fractol
FT			= ./libft/
FT_LIB	= $(addprefix $(FT),libft.a)

SRCSDIR     = srcs
SRCS 	 	= $(addprefix $(SRCSDIR)/, $(SOURCES))

OBJS 	 	= $(SOURCES:.c=.o)
OBJS_DIR 	= $(addprefix $(SRCSDIR)/, $(OBJS))

INCLUDES	= -I includes/ -I libft/includes

# mlx library
OS			= $(shell uname)
ifeq ($(OS), Linux)
	MLX		= ./minilibx/
	MLX_LNK	= -L $(MLX) -l mlx -lXext -lX11
else
	MLX		= ./minilibx_macos/
	MLX_LNK	= -L $(MLX) -l mlx -framework OpenGL -framework AppKit
endif

MLX_INC	= -I $(MLX)
MLX_LIB	= $(addprefix $(MLX),mlx.a)

all: $(FT_LIB) $(MLX_LIB) $(NAME)

$(FT_LIB):
	make -C ./libft/

$(MLX_LIB):
	@make -C $(MLX)

$(NAME): $(OBJS_DIR)
	cc $(WWW) $(OBJS_DIR) $(MLX_LNK) -o $@  -L libft -lft

$(SRCSDIR)/%.o:$(SRCSDIR)/%.c
	cc $(WWW) $(INCLUDES) $(MLX_INC) -o $@ -c $<

clean:
	make -C $(FT) clean
	/bin/rm -f $(OBJS_DIR)
	make -C $(MLX) clean

fclean: clean
	make -C $(FT) fclean
	/bin/rm -f $(NAME)

re: fclean all
