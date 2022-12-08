# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 15:26:16 by pgouasmi          #+#    #+#              #
#    Updated: 2022/12/08 16:27:47 by pgouasmi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCSLIB = ./libft/ft_isalnum.c	\
		./libft/ft_isalpha.c	\
		./libft/ft_isascii.c	\
		./libft/ft_isdigit.c	\
		./libft/ft_isprint.c	\
		./libft/ft_itoa.c		\
		./libft/ft_strchr.c		\
		./libft/ft_strdup.c		\
		./libft/ft_strjoin.c	\
		./libft/ft_strlcat.c	\
		./libft/ft_strlcpy.c	\
		./libft/ft_strlen.c		\
		./libft/ft_strncmp.c	\
		./libft/ft_strnstr.c	\
		./libft/ft_strrchr.c	\
		./libft/ft_strtrim.c	\
		./libft/ft_substr.c		\
		./libft/ft_tolower.c	\
		./libft/ft_toupper.c	\
		./libft/ft_atoi.c		\
		./libft/ft_itoa.c		\
		./libft/ft_split.c 		\
		./libft/ft_strtrim.c	\
		./libft/ft_substr.c		\
		./libft/ft_bzero.c		\
		./libft/ft_memcpy.c		\
		./libft/ft_memmove.c	\
		./libft/ft_memset.c		\
		./libft/ft_strmapi.c	\
		./libft/ft_striteri.c	\
		./libft/ft_calloc.c		\
		./libft/ft_memcmp.c		\
		./libft/ft_memchr.c		\
		./libft/ft_putchar_fd.c	\
		./libft/ft_putstr_fd.c	\
		./libft/ft_putendl_fd.c	\

SRCSPF = 	ft_printf.c			\
			ft_putchar_pf.c		\
			ft_putnbr_base.c	\
			ft_putnbr_base_p.c	\
			ft_putstr_pf.c		\
			
ALLSRCS = $(SRCSLIB) $(SRCSPF)
OBJS = ${ALLSRCS:.c=.o}
HEADER = ft_printf.h
CC = cc
FLAG = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJS) $(HEADER) Makefile
			ar -rcs $(NAME) $(OBJS)

%.o:	%.c $(HEADER) Makefile
			$(CC) $(FLAG) -I . -c $< -o $@

clean:
			rm -f $(OBJS)

fclean: 	clean
			rm -f $(NAME)