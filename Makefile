#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lberezyn <lberezyn@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/28 13:44:48 by lberezyn          #+#    #+#              #
#    Updated: 2018/10/28 13:44:49 by lberezyn         ###   ########.fr        #
#                                                                              #
#******************************************************************************#


NAME        = scop

CC          = clang

CFLAGS      = -Wall -Wextra -Werror -O3

SRCS_DIR    = ./src
OBJS_DIR    = ./obj
HEADERS_DIR = ./include

SRCS        = main.c parser.c utils.c parsing_utils.c sdl_init.c

OBJS        = $(SRCS:.c=.o)

INCLUDES    = -I include/
INCLUDES   += -I libft/
INCLUDES   += -I /frameworks/SDL2_image.framework/SDL2_image/Headers
INCLUDES   += -I /Library/Frameworks/SDL2.framework/Versions/Current/Headers


HEADERS     = scop.h
HEADERS    := $(addprefix $(HEADERS_DIR)/, $(HEADERS))


LIBRARIES   = -lm -lpthread -framework OpenGL -framework OpenCL
LIBRARIES  += ./libft/libft.a -framework AppKit
LIBRARIES  += ./frameworks/SDL2_image.framework/Versions/Current/SDL2_image
LIBRARIES  += ./frameworks/SDL2.framework/SDL2

TO_LINKING  = $(addprefix $(OBJS_DIR)/, $(OBJS)) $(INCLUDES) $(LIBRARIES)

VPATH       = $(SRCS_DIR) $(OBJS_DIR) ./frameworks


all         : $(NAME)

$(NAME)     : $(OBJS_DIR) $(OBJS) $(HEADERS)
	@make -C libft
	@$(CC) $(CFLAGS) -o $(NAME) $(TO_LINKING)
	@printf "\e[38;5;46m./$(NAME) SUCCESSFULLY BUILD 🖥\e[0m\n"

$(OBJS_DIR) :
	@mkdir $(OBJS_DIR)
	@printf "\e[38;5;46m$(OBJS_DIR)    FOLDER CREATED\e[0m\n"

$(OBJS)     : %.o : %.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $(OBJS_DIR)/$@ $(INCLUDES)

clean       :
	@rm -f $(OBJS)
	@make -C libft clean
	@printf "🗑  \e[38;5;226m$(OBJS) DELETED\e[0m\n"

fclean      : clean
	@rm -f $(NAME)
	@make -C libft fclean
	@printf "🗑  \e[38;5;226m./$(NAME) DELETED\e[0m\n"

re          : fclean all

.PHONY: clean fclean re
