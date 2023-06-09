# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 17:52:53 by nsoares-          #+#    #+#              #
#    Updated: 2023/04/30 15:23:01 by nsoares-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror -g  
RM = rm -rf
LIBFT = ./libft/libft.a

# __________MLX_______________

MLX = -L ./minilibx_opengl_20191021 -lmlx -Imlx -framework OpenGL -framework AppKit

# _________SOURCES____________

SOURCE_FILES = main.c \
				src/init_mlx.c \
				src/hook.c \
				src/check_args.c \
				fractals/Mandelbrot.c \
				fractals/Julia.c \
				src/colors.c \
				src/fract_utils.c
				

OBJS_FILES = $(SOURCE_FILES:.c=.o)

# __________COLORS____________

BOLD_PURPLE	=	\033[1;35m
BOLD_CYAN	=	\033[1;36m
BOLD_YELLOW	=	\033[1;33m
NO_COLOR	=	\033[0m

# _________MESSAGE_____________

COMPILATION_START	=	echo "\n$(BOLD_YELLOW)Make: $(NO_COLOR)Compilation start...\n"

FRACTOL_READY  =   echo "\n$(BOLD_YELLOW)fract-ol ready! ✅ \n"

CLEANED		=	echo "\n$(BOLD_YELLOW)Clean: $(NO_COLOR)Removed all the \".o\" files \n"

FCLEANED	=	echo "\n$(BOLD_YELLOW)Fclean: $(NO_COLOR)Removed the executables \n"

RE          =   echo "\n$(BOLD_YELLOW)Re: $(NO_COLOR)Compilation restarted \n"

# __________RULES______________

all: compilation_start $(NAME)

$(NAME): $(OBJS_FILES)
		$(MAKE) --no-print-directory -C ./libft
		$(MAKE) --no-print-directory -C ./minilibx_opengl_20191021
		$(CC) $(CFLAGS) $(SOURCE_FILES) $(LIBFT) $(MLX) -o $(NAME)
		@ $(FRACTOL_READY)

compilation_start:
	@ $(COMPILATION_START)

clean:
	@ $(RM) $(OBJS_FILES)
	@ cd libft && make clean
	@ $(CLEANED)
	
fclean: clean
	@ $(RM) $(NAME)
	@ cd libft && make fclean
	@ cd ./minilibx_opengl_20191021 && make clean
	@ $(FCLEANED)
		
re:	fclean all
	@ $(RE) 
