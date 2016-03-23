# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/21 12:17:37 by tguillem          #+#    #+#              #
#    Updated: 2016/03/22 15:44:53 by tguillem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -g -Wextra -Wall -Werror -I./
CC = gcc

NAME = libft.a
SRC = ft_memset.c ft_bzero.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c \
	  ft_strcat.c ft_strncat.c ft_strlcat.c ft_strstr.c ft_strcmp.c ft_atoi.c \
	  ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	  ft_toupper.c ft_tolower.c ft_putchar.c ft_putstr.c ft_putendl.c \
	  ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	  ft_putnbr_fd.c  ft_strncmp.c ft_strnstr.c ft_strchr.c ft_strrchr.c \
	  ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
	  ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
	  ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
	  ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_itoa.c \
	  ft_strsplit.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c \
	  ft_lstiter.c ft_lstsize.c ft_lstmap.c ft_iswhitespace.c ft_isblank.c \
	  ft_strtrimch.c ft_strtrimcmp.c ft_islower.c ft_isupper.c ft_max.c \
	  ft_putnbrbase.c ft_wstrlen.c ft_putwchar.c ft_putwstr.c ft_min.c \
	  ft_itoa_base.c get_next_line.c ft_time.c ft_count_digit.c \
	  ft_putwchar_fd.c ft_putwstr_fd.c ft_printf/ft_nbrlen.c \
	  ft_printf/ft_printf.c ft_printf/ft_printu.c \
	  ft_printf/internal_printf.c ft_printf/manage_number.c \
	  ft_printf/manage_specials.c ft_printf/manage_str.c \
	  ft_printf/manage_str.c ft_printf/manage_wstr.c ft_printf/manager_base.c \
	  ft_printf/parser.c ft_printf/utils.c ft_prgm.c ft_path.c

OBJ = $(SRC:.c=.o)
REMOVE = $(OBJ)

all: $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -o $@ -c $<
	@echo "libft> Building $<..."

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(REMOVE)

fclean: clean
	@/bin/rm -f $(NAME)

.PHONY: clean fclean re

re: fclean all
