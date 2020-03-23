# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/24 16:32:39 by lbellona          #+#    #+#              #
#    Updated: 2020/03/23 22:01:30 by timuryakubo      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES 	= fractol.c

WWW 		= -Wall -Wextra -Werror

FT 			= fractol

SRCSDIR     = srcs
SRCS 	 	= $(addprefix $(SRCSDIR)/, $(SOURCES))

OBJS 	 	= $(SOURCES:.c=.o)
OBJS_DIR 	= $(addprefix $(SRCSDIR)/, $(OBJS))

INCLUDES	= -I includes/ -I libft/includes

all: liba $(FT)

liba:
	make -C ./libft/

$(FT): $(OBJS_DIR)
	cc $(WWW) $(OBJS_DIR) -o $@  -L libft -lft

$(SRCSDIR)/%.o:$(SRCSDIR)/%.c
	cc $(WWW) $(INCLUDES) -o $@ -c $<

clean:
	make -C ./libft/ clean
	/bin/rm -f $(OBJS_DIR)

fclean: clean
	make -C ./libft/ fclean
	/bin/rm -f $(FT)

re: fclean all
