# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: akramp <marvin@codam.nl>                     +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/10 16:40:57 by akramp         #+#    #+#                 #
#    Updated: 2020/02/23 17:41:18 by akramp        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS =  -Wall -Werror -Wextra

TEST = -g -o test

CC = gcc

LIPATH = ./litest/

SRC = ft_printf.c struct_fill.c sp_d_i.c ft_libft.c ft_libft_2.c sp_u.c \
		sp_c.c sp_s.c sp_p.c sp_x.c

OBJ :=	${SRC:%.c=%.o}

PINK	= 	\033[38;5;206m
P1	= 	\033[38;5;175m
P2	= \033[38;5;225m
PINK3	= 	\033[38;5;211m
YY  = \033[38;5;222m
WH	= \033[38;5;96m
X		= \033[38;5;
Y		= 1
Z		= m
TZE		= $(eval Y=$(shell echo $$((($(Y)%10)+167))))
LI		= 0
BLUE = \033[38;5;33m
RED = \033[38;5;160m
GREEN = \033[38;5;112m
RANDOM := $$((RANDOM % 10))

all: $(NAME)

%.o: %.c
	@echo "$(X)$(Y)$(Z)[ ✿ ] Compiling $@$(WH)\n"
	$(TZE)
	@$(CC) $(FLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	@ar -rc $(NAME) $(OBJ)
	@echo "$(WH)----------------------------"
	@echo "$(P2)ଘ(੭ˊᵕˋ)੭$(YY)* ੈ ✩‧₊˚$(P1)\t\tDone! $(WH)"
	@echo "$(WH)----------------------------"
	@echo "$(PINK3)            _       _    __ ";
	@echo "$(P1) _ __  _ __(_)_ __ | |_ / _|";
	@echo "$(P2)| '_ \| '__| | '_ \| __| |_";
	@echo "$(PINK3)| |_) | |  | | | | | |_|  _|";
	@echo "$(P1)| .__/|_|  |_|_| |_|\__|_|  ";
	@echo "$(P2)|_|                       $(P2)♡  ";
	@echo "\n$(P2)🌸✨     Angeli Kramp    ✨🌸$(PINK) $(WH)"
	@echo "$(WH)----------------------------"

test: $(OBJ)
	@$(CC) printf_main.c $(SRC)
	@echo "$(X)$(Y)$(Z)[ ✿ ] 	      Compiling ... $(WH)\n"
	@echo "$(WH)----------------------------"
	@echo "$(P2)ଘ(੭ˊᵕˋ)੭$(YY)* ੈ ✩‧₊˚$(P1)\t\tDone! $(WH)"

clean:
	@echo "$(PINK)🦄	Cleaning ...$(WH)\n"
	rm -f $(OBJ) a.out
	rm -f ./*~ ./*#
	@echo "\n$(P2)✨	Cleaning Done!$(WH)"

fclean: clean
	@echo "$(PINK)🦄	Removing $(NAME) ...\n$(WH)"
	-rm -f $(NAME)
	@echo "\n$(P2)✨	Removed $(NAME)!$(WH)"

re: fclean all
