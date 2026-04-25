# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/21 15:26:47 by sesquier          #+#    #+#              #
#    Updated: 2026/04/25 15:15:41 by sesquier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

LIBFT_DIR = LIBFT
MINILIBX_DIR = minilibx-linux

S_SRC = main.c init.c
D_SRC = srcs/

S_OBJ = $(S_SRC:.c=.o)
D_OBJ = .build/
OBJ = $(addprefix $(D_OBJ), $(S_OBJ))

CC = cc
CFLAGS = -O3 -march=native -funroll-loops -flto

#-Wall -Wextra -Werror

LIBFT = $(LIBFT_DIR)/libft.a
MINILIBX = $(MINILIBX_DIR)/libmlx_Linux.a

D_INC = includes/
INC_FLAGS = -I$(D_INC) -I$(LIBFT_DIR) -I$(MINILIBX_DIR)

MLX_FLAGS = -L$(MINILIBX_DIR) -lmlx_Linux -lXext -lX11 -lm

all: $(LIBFT) $(MINILIBX) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MINILIBX):
	$(MAKE) -C $(MINILIBX_DIR)

$(NAME): $(OBJ) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) $(INC_FLAGS) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $@

$(D_OBJ)%.o: $(D_SRC)%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(D_OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re+
