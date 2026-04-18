##
## EPITECH PROJECT, 2026
## G-NWP-400-COT-4-1-myftp-95
## File description:
## Makefile
##

SRC = src/usage.c	\
	src/server.c	\
	src/commande.c	\
	src/main.c	\
	src/passif.c	\
	src/actif.c	\
	src/list.c	\
	src/cdup.c 	\
	src/cwd.c 	\

OBJ	=	$(SRC:.c=.o)

NAME	=        myftp

all:  $(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC)


clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
