# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/06 18:14:41 by doberyn           #+#    #+#              #
#    Updated: 2019/07/20 09:38:17 by sleonia          ###   ########.fr        #
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

SRC_PATH = ./source/
OBJ_PATH = ./objects/
INC_PATH = ./includes/

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I, $(INC_PATH))

SRC_NAME =	ft_isnegative.c 		ft_memalloc.c   ft_putchar_fd.c 			ft_strcat.c     	ft_striteri.c   ft_strnequ.c    ft_tolower.c  \
			ft_isprint.c    		ft_memccpy.c    ft_putendl.c    			ft_strchr.c     	ft_strjoin.c    ft_strnew.c     ft_toupper.c  \
			ft_atoi.c       		ft_itoa.c       ft_memchr.c     			ft_putendl_fd.c 	ft_strclr.c     ft_strlcat.c    ft_strnstr.c  \
			ft_bzero.c      		ft_lstadd.c     ft_memcmp.c     			ft_putnbr.c     	ft_strcmp.c     ft_strlen.c     ft_strrchr.c  \
			ft_count_word.c 		ft_lstdel.c     ft_memcpy.c     			ft_putnbr_fd.c  	ft_strcpy.c     ft_strmap.c     ft_strsplit.c \
			ft_isalnum.c    		ft_lstdelone.c  ft_memdel.c    				ft_putstr.c     	ft_strdel.c     ft_strmapi.c    ft_strstr.c   \
			ft_isalpha.c    		ft_lstiter.c    ft_memmove.c    			ft_putstr_fd.c  	ft_strdup.c     ft_strncat.c    ft_strsub.c   \
			ft_isascii.c    		ft_lstmap.c     ft_memset.c     			ft_sqr.c        	ft_strequ.c     ft_strncmp.c    ft_strtrim.c  \
			ft_isdigit.c   			ft_lstnew.c     ft_putchar.c    			ft_sqrt.c       	ft_striter.c    ft_strncpy.c    ft_swap.c     \
			ft_strrev.c 			ft_strup.c		ft_strlow.c					ft_strjoin_free.c	ft_findsymb.c	get_next_line.c ft_getnbr.c   \
			ft_destroy_int_arr.c 	ft_len_arr.c 	ft_destroy_string_arr.c
			
OBJ_NAME = $(SRC_NAME:.c=.o)

#****************************************************************************#
#									ALL 									 #
#****************************************************************************#

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@gcc -Wall -Werror -Wextra $(INC) -o $@ -c $<
	@echo -n \*

$(NAME): $(OBJ)
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

fclean: clean
	@/bin/rm -rf $(OBJ_PATH)
	@/bin/rm -f $(NAME)

re: fclean all
