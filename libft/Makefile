# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 09:45:36 by tnicolas          #+#    #+#              #
#    Updated: 2017/11/15 14:58:55 by pmilan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INC_DIR = .

FILES = ft_strlen.c \
		  ft_putchar.c \
		  ft_putstr.c \
		  ft_putendl.c \
		  ft_putnbr.c \
		  ft_putchar_fd.c \
		  ft_putstr_fd.c \
		  ft_putendl_fd.c \
		  ft_putnbr_fd.c \
		  ft_strcmp.c \
		  ft_strncmp.c \
		  ft_strcpy.c \
		  ft_strncpy.c \
		  ft_strcat.c \
		  ft_strncat.c \
		  ft_toupper.c \
		  ft_tolower.c \
		  ft_isalpha.c \
		  ft_isdigit.c \
		  ft_isalnum.c \
		  ft_isascii.c \
		  ft_isprint.c \
		  ft_atoi.c \
		  ft_itoa.c \
		  ft_strstr.c \
		  ft_strnstr.c \
		  ft_strchr.c \
		  ft_strrchr.c \
		  ft_memalloc.c \
		  ft_memdel.c \
		  ft_strnew.c \
		  ft_strdel.c \
		  ft_strclr.c \
		  ft_striter.c \
		  ft_striteri.c \
		  ft_strmap.c \
		  ft_strmapi.c \
		  ft_strequ.c \
		  ft_strnequ.c \
		  ft_strsub.c \
		  ft_strjoin.c \
		  ft_strtrim.c \
		  ft_strsplit.c \
		  ft_strdup.c \
		  ft_memset.c \
		  ft_bzero.c \
		  ft_memcpy.c \
		  ft_memccpy.c \
		  ft_memmove.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_strlcat.c \
		  ft_lstnew.c \
		  ft_lstdelone.c \
		  ft_lstdel.c \
		  ft_lstadd.c \
		  ft_lstiter.c \
		  ft_lstmap.c \
		  ft_realloc.c


HFILES = libft.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror

INC_DIR = ./
SRCS_DIR = ./
OBJ_DIR = ./

INC := $(addprefix -I , $(INC_DIR))
SRCS := $(addprefix $(SRCS_DIR), $(FILES))
OBJ := $(addprefix $(OBJ_DIR), $(FILES:.c=.o))

NORMAL = "\x1B[0m"
RED = "\x1B[31m"
GREEN = "\x1B[32m"
YELLOW = "\x1B[33m"
BLUE = "\x1B[34m"
MAGENTA = "\x1B[35m"
CYAN = "\x1B[36m"
WHITE = "\x1B[37m"

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@printf $(CYAN)"-> create lib\n"$(WHITE)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c $(HFILES)
	@printf $(YELLOW)"-> $<\n"$(WHITE)
	@$(CC) -c $(INC) $< -o $@ $(CFLAGS)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(dir $(OBJ))

clean:
	@printf $(RED)"-x remove .o files\n"$(WHITE)
	@rm -f $(OBJ)

clean_name:
	@printf $(RED)"-x remove $(NAME)\n"$(WHITE)
	@rm -f $(NAME)

fclean: clean
	@printf $(RED)"-x remove $(NAME)\n"$(WHITE)
	@rm -f $(NAME)

re: fclean all

open:
	@vim +12 `find . -iname "*.c" -o -iname "*.h" -o -iname "*.txt" \
		-o -iname "Makefile" -o -iname ".gitignore"` `find ~ -iname ".vimrc" \
	   -o -iname ".vim/vim_help_file"`

exec: all
	@clear
	@$(CC) main.c -o libft_test $(INC) -L . $(CFLAGS) -lft
	@./libft_test

norm:
	@printf $(BLUE)"NORME LIBFT\n"$(WHITE)
	@norminette $(SRCS) $(HFILES)

.PHONY: all clean clean_swp fclean re open exec norm
