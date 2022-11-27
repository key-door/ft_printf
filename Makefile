# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keys <keys@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/31 17:20:52 by kyoda             #+#    #+#              #
#    Updated: 2022/11/28 00:17:59 by keys             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFTDIR = ./libft
INCLUDEDIR = include/

CC 			= cc
CFLAGS		= -Wall -Wextra -Werror

SRCS = 	ft_printf.c \
		ft_putstr.c \
		ft_puthex.c \
		ft_putnbr.c \
		ft_putptr.c \
		ft_putchr.c \
		ft_putnbr_u.c

OBJDIR = obj/
OBJS  = $(addprefix $(OBJDIR), $(SRCS:.c=.o))

LIBFTNAME	= libft/libft.a
FT			= $(LIBFTNAME)

all : $(NAME)

$(NAME) : $(OBJS) $(FT)
	ar rcs $(NAME) $^

$(OBJDIR)%.o: %.c
	@mkdir -p $$(dirname $@)
	$(CC) $(INCLUDE) $(CFLAGS) -o $@ -c $<

$(FT)	:
	$(MAKE)  bonus -C $(LIBFTDIR)

libft	:
	@$(MAKE) --no-print-directory bonus -C $(LIBFTDIR)

clean :
	@$(MAKE) --no-print-directory clean -C $(LIBFTDIR)
	$(RM) -r $(OBJDIR)

fclean : clean
	@$(MAKE) --no-print-directory fclean -C $(LIBFTDIR)
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re libft
