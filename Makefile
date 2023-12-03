##
## EPITECH PROJECT, 2022
## MAKEFILE
## File description:
## Makefile
##

NAME	=	my_sokoban

CFLAGS	+= -I ./include/ -W -Wall -Wextra -lncurses

LFLAGS 	= 	-L ./lib/ -lmy

SRC	=	src/main.c	\
		src/help_set_free.c	\
		src/set_sokoban.c	\
		src/find_count.c	\
		src/check_map.c		\
		src/start_sokoban.c	\
		src/engine_sokoban.c	\
		src/player_moove.c	\

OBJ	=	$(SRC:.c=.o)

RMO	=	$(RM) src/*.o *~

MAKE	=	make

all: $(NAME)

build_lib :
	$(MAKE) -C ./lib/

$(NAME): build_lib $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) $(LFLAGS) -o $(NAME)

debug: MAKE += -E CFLAGS+=-g3
debug: CFLAGS += -g3
debug: $(NAME)

clean:
	$(RM) *~ \#*\#*

fclean: clean
	$(RM) $(NAME)
	$(RMO)
	make fclean -C ./lib/

re: fclean all

git:
	git add .
	git commit -m "$m"
	git push -u origin main

.PHONY: all build_lib debug lean fclean re git
