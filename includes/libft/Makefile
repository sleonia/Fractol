# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/06 18:14:41 by doberyn           #+#    #+#              #
#    Updated: 2019/08/11 14:57:34 by sleonia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, $(NAME), norm, clean, fclean, re

#****************************************************************************#
#					SETTINGS FOR CONCLUSION IN CONSOLE 						 #
#****************************************************************************#

BLACK = \033[30m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
PINK = \033[35m
AQUA = \033[36m
GREY = \033[37m
UNDERLINE = \033[4m
NORMAL = \033[0m

#****************************************************************************#
#									LIBFT 									 #
#****************************************************************************#

NAME = libft.a

SRC_IO_PATH = ./source/io/
SRC_MEMORY_PATH = ./source/memory/
SRC_STRING_PATH = ./source/string/

OBJ_PATH = ./objects/
OBJ_IO_PATH = ./objects/io/
OBJ_MEMORY_PATH = ./objects/memory/
OBJ_STRING_PATH = ./objects/string/

INC_PATH = ./includes/

SRC_IO = $(addprefix $(SRC_IO_PATH), $(SRC_IO_NAME))
SRC_MEMORY = $(addprefix $(OBJ_MEMORY_PATH), $(SRC_MEMORY_NAME))
SRC_STRING = $(addprefix $(OBJ_STRING_PATH), $(SRC_STRING_NAME))

OBJ_IO = $(addprefix $(OBJ_IO_PATH), $(OBJ_IO_NAME))
OBJ_MEMORY = $(addprefix $(OBJ_MEMORY_PATH), $(OBJ_MEMORY_NAME))
OBJ_STRING = $(addprefix $(OBJ_STRING_PATH), $(OBJ_STRING_NAME))
INC = $(addprefix -I, $(INC_PATH))

SRC_IO_NAME = 		ft_putchar.c		ft_putendl_fd.c		ft_putnbr_fd.c		ft_putstr_fd.c					\
					ft_putchar_fd.c		ft_putendl.c		ft_putnbr.c			ft_putnbr_fd.c		ft_putstr.c

SRC_MEMORY_NAME = 	ft_destroy_int_arr.c	ft_destroy_string_arr.c	ft_memalloc.c	ft_memccpy.c	ft_memchr.c	\
					ft_memcmp.c				ft_memcpy.c				ft_memdel.c		ft_memmove.c	ft_memset.c	\
					ft_bzero.c

SRC_STRING_NAME	=	ft_atoi.c		ft_isalnum.c		ft_isprint.c		ft_strchr.c		ft_strdel.c			\
					ft_striteri.c	ft_strlen.c			ft_strncat.c		ft_strnew.c		ft_strsplit.c		\
					ft_strup.c		read_file.c			ft_isalpha.c		ft_strtrim.c	get_next_line.c		\
					ft_strdup.c		ft_strjoin.c		ft_strlow.c			ft_strncmp.c	ft_strnstr.c		\
					ft_strstr.c		ft_tolower.c		ft_isascii.c		ft_len_arr.c	ft_isdigit.c		\
					ft_strcmp.c		ft_strequ.c			ft_strjoin_free.c	ft_strmap.c		ft_strncpy.c		\
					ft_strrchr.c	ft_strsub.c			ft_toupper.c		ft_getnbr.c		ft_strcat.c			\
					ft_strcpy.c		ft_striter.c		ft_strlcat.c		ft_strmapi.c	ft_strnequ.c		\
					ft_strrev.c		ft_itoa.c
			
OBJ_IO_NAME = $(SRC_IO_NAME:.c=.o)
OBJ_MEMORY_NAME = $(SRC_MEMORY_NAME:.c=.o)
OBJ_STRING_NAME = $(SRC_STRING_NAME:.c=.o)

#****************************************************************************#
#									ALL 									 #
#****************************************************************************#

all: $(NAME)

$(OBJ_IO_PATH)%.o: $(SRC_IO_PATH)%.c $(INC_PATH)/libft.h
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(OBJ_IO_PATH)
	@gcc -Wall -Werror -Wextra $(INC) -o $@ -c $<
	@echo -n \*

$(OBJ_MEMORY_PATH)%.o: $(SRC_MEMORY_PATH)%.c $(INC_PATH)/libft.h
	@mkdir -p $(OBJ_MEMORY_PATH)
	@gcc -Wall -Werror -Wextra $(INC) -o $@ -c $<
	@echo -n \*

$(OBJ_STRING_PATH)%.o: $(SRC_STRING_PATH)%.c $(INC_PATH)/libft.h
	@mkdir -p $(OBJ_STRING_PATH)
	@gcc -Wall -Werror -Wextra $(INC) -o $@ -c $<
	@echo -n \*

$(NAME): $(OBJ_IO) $(OBJ_MEMORY) $(OBJ_STRING)
	@echo "\n$(AQUA)***\t\t\t  $(YELLOW)🎉  LIBFT READY!🎉\t\t\t$(AQUA)      ***"
	@ar -rc $(NAME) $?
	@ranlib $(NAME)
	@echo "$(BLUE)=============$(RED)===============\
$(GREEN)===============$(YELLOW)===============$(BLUE)===============$(BLACK)"

#****************************************************************************#
#									OTHER			 						 #
#****************************************************************************#

norm:
	norminette -R CheckForbiddenSourceHeader

clean: 
	@/bin/rm -rf $(OBJ_PATH)
	@/bin/rm -rf $(OBJ_IO_PATH)
	@/bin/rm -rf $(OBJ_MEMORY_PATH)
	@/bin/rm -rf $(OBJ_STRING_PATH)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
