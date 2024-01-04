# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 11:04:41 by ccosta-c          #+#    #+#              #
#    Updated: 2023/11/13 11:04:50 by ccosta-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ COLORS _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
RESET	= \033[0m
BLACK 	= \033[1;30m
RED 	= \033[1;31m
GREEN 	= \033[1;32m
YELLOW 	= \033[1;33m
BLUE	= \033[1;34m
PURPLE 	= \033[1;35m
CYAN 	= \033[1;36m
WHITE 	= \033[1;37m

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ COMMANDS _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
CC = cc
RM = rm -f
AR = ar -rcs

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ FLAGS _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
CFLAGS		= -Wall -Wextra -Werror -g
MKFLAGS		= --no-print-directory
MFLAGS	= -lXext -lX11
LIBFTFLAGS	= -L ./libft -lft

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ FOLDERS _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
DEPS		= includes
SRCS		= .
SRCS_BONUS	= bonus
LIBFT = ./libft/libft.a
MINILIBX = ./minilibx-linux/libmlx.a

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ FILES _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
SRC				=	parser.c \
					main.c \
					debugging.c \
					utils.c \
					frees.c \
					frees2.c \
					initialize.c \
					initialize2.c \
					checks.c \
					check_map.c \
					get_map.c \
					get_map2.c \
					verify_map.c \
					check_border.c \
					windows.c \
					rendering.c \
					raycaster.c \
					draw_wall.c \
					ft_key.c \
					ft_movements.c
OBJS 			:= $(SRC:.c=.o)
BONUS			=	bonus/parser.c \
					bonus/main.c \
					bonus/debugging.c \
					bonus/utils.c \
					bonus/frees.c \
					bonus/frees2.c \
					bonus/initialize.c \
					bonus/initialize2.c \
					bonus/initialize3.c \
					bonus/sprites.c \
					bonus/checks.c \
					bonus/check_map.c \
					bonus/get_map.c \
					bonus/get_map2.c \
					bonus/verify_map.c \
					bonus/check_border.c \
					bonus/windows.c \
					bonus/rendering.c \
					bonus/raycaster.c \
					bonus/draw_wall.c \
					bonus/ft_key.c \
					bonus/ft_movements.c \
					bonus/minimap.c \
					bonus/draw_static_map.c \
					bonus/draw_dinamic_map.c
OBJS_BONUS		:= $(BONUS:.c=.o)
NAME			= cub3D
NAME_BONUS		= cub3D_bonus
TARGET			= $(addprefix $(SRCS)/, $(OBJS))
TARGET_BONUS	= $(addprefix $(SRCS_BONUS)/, $(OBJS_BONUS))


#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ RULES _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
all: $(NAME)

$(LIBFT):
	@$(MAKE) -C ./libft

$(MINILIBX):
	@$(MAKE) -C ./minilibx-linux

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINILIBX) $(MFLAGS) -o $(NAME) -lm
	clear
	echo "$(GREEN)./cub3D is ready!$(RESET)"

%.o : %.c
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)$<$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) clean -C ./libft
	@$(MAKE) clean -C ./minilibx-linux
	@$(RM) $(OBJS)
	@$(RM) $(OBJS_BONUS)
	clear
	echo "$(RED)Object files have been deleted!$(RESET)"

fclean: clean
	@$(MAKE) fclean -C ./libft
	@$(MAKE) clean -C ./minilibx-linux
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)
	clear
	echo "$(RED)Object and Executable files have been deleted!$(RESET)"

bonus: $(OBJS_BONUS) $(LIBFT) $(MINILIBX)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) $(MINILIBX) $(MFLAGS) -o $(NAME_BONUS) -lm
	clear
	echo "$(GREEN)./cub3D_bonus is ready!$(RESET)"

debug:
	$(CC) $(CFLAGS) $(LIBXFLAGS) main.c $(SRC) libft/libft.a minilibx-linux/libmlx.a -g

.SILENT:
re: fclean all
