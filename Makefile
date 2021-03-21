##
## EPITECH PROJECT, 2021
## make
## File description:
## file
##

SRC	=	soko.c \
		soko_main.c \
		move.c \
		refresh_o.c \

NAME	=	my_sokoban

all:	$(NAME) clean

libmy:
	@make -sC lib/my/

$(NAME):	libmy
	@gcc -o $(NAME) $(SRC) -L./lib -lmy -g -lm -lncurses
	@echo -e "\033[06m\033[32mCompilation done => ${NAME}\033[00m"

clean:
	make -sC lib/my/ clean
	rm -f *~ include/*~ lib/my/*~ tests/*~

fclean:	clean
	make -sC lib/my/ fclean
	rm -f $(NAME)
	clear

re:	fclean all
