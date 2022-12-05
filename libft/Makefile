# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 15:15:07 by pgouasmi          #+#    #+#              #
#    Updated: 2022/11/30 13:22:41 by pgouasmi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =	ft_isalnum.c	\
		ft_isalpha.c	\
		ft_isascii.c	\
		ft_isdigit.c	\
		ft_isprint.c	\
		ft_itoa.c		\
		ft_strchr.c		\
		ft_strdup.c		\
		ft_strjoin.c	\
		ft_strlcat.c	\
		ft_strlcpy.c	\
		ft_strlen.c		\
		ft_strncmp.c	\
		ft_strnstr.c	\
		ft_strrchr.c	\
		ft_strtrim.c	\
		ft_substr.c		\
		ft_tolower.c	\
		ft_toupper.c	\
		ft_atoi.c		\
		ft_itoa.c		\
		ft_split.c 		\
		ft_strtrim.c	\
		ft_substr.c		\
		ft_bzero.c		\
		ft_memcpy.c		\
		ft_memmove.c	\
		ft_memset.c		\
		ft_strmapi.c	\
		ft_striteri.c	\
		ft_calloc.c		\
		ft_memcmp.c		\
		ft_memchr.c		\
		ft_putchar_fd.c	\
		ft_putstr_fd.c	\
		ft_putendl_fd.c	\
		ft_putnbr_fd.c	\

B_SRCS =	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = ${SRCS:.c=.o}

BOBJS = ${B_SRCS:.c=.o}

HEADER = libft.h

CC = cc

FLAG = -Wall -Wextra -Werror

all: $(NAME)

bonus:		$(BOBJS) $(HEADER) Makefile
			ar rcs $(NAME) $(BOBJS)

$(NAME):	$(OBJS) $(HEADER) Makefile
			ar rcs $(NAME) $(OBJS)


%.o:		%.c $(HEADER) Makefile
			$(CC) $(FLAG) -I . -c $< -o $@

clean:
			rm -f $(OBJS)

fclean: 	clean
			rm -f $(NAME)

re:			fclean
			$(MAKE) all 

.PHONY: all clean fclean re