# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/28 11:21:03 by sesquier          #+#    #+#              #
#    Updated: 2026/04/27 15:34:31 by sesquier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

# Dossiers sources
LIBFT_DIR = LIBFT_SRC
PRINTF_DIR = ft_printf
GNL_DIR = get_next_line

# Fichiers source
SRCS_LIBFT = $(addprefix $(LIBFT_DIR)/, \
    ft_atoi.c ft_atol.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
    ft_isdigit.c ft_strnstr.c ft_strjoin.c ft_striteri.c \
    ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
    ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
    ft_strrchr.c ft_tolower.c ft_toupper.c ft_strdup.c ft_calloc.c \
    ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_substr.c \
    ft_strtrim.c ft_tolower.c ft_toupper.c ft_itoa.c ft_split.c ft_strmapi.c \
    ft_is_whitespace.c ft_strcmp.c \
)

SRCS_BONUS = $(addprefix $(LIBFT_DIR)/, \
    ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstlast_bonus.c \
    ft_lstnew_bonus.c ft_lstsize_bonus.c ft_lstdelone_bonus.c \
    ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \
)

SRCS_PRINTF = $(addprefix $(PRINTF_DIR)/, \
    ft_intputchar.c ft_intputlowhex.c ft_intputnbr.c ft_intputnbrbase.c \
    ft_intputpadress.c ft_intputstr.c ft_intputunsignedint.c \
    ft_intputupphex.c ft_printf.c \
)

SRCS_GNL = $(addprefix $(GNL_DIR)/, \
    get_next_line_bonus.c get_next_line_utils_bonus.c \
)

SRCS = $(SRCS_LIBFT) $(SRCS_PRINTF) $(SRCS_GNL) $(SRCS_BONUS)

# Générer les .o à la racine
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar -rcs

%.o: %.c
	$(CC) $(CFLAGS) -I. -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
