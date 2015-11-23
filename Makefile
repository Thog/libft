# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tguillem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/21 12:17:37 by tguillem          #+#    #+#              #
#    Updated: 2015/11/23 17:42:30 by tguillem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	+=	-Wextra -Wall -Werror -I./includes
CC = gcc

NAME = libft.a

SRC = ft_memset.c ft_bzero.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strstr.c ft_strcmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c  ft_strncmp.c ft_strnstr.c

SRCDIR = srcs
OBJDIR = objs
SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJ = $(SRC:.c=.o)
all: $(NAME)


$(NAME):
	$(CC) $(CFLAGS)  -c $(SRCS)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
