##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

NAME	=	libmy.a

CPPFLAGS	+=	-I ./include/ -Wextra -Wall

OBJ	=	$(SRC:.c=.o)

SRC	=	my_putchar.c		\
		my_putstr.c		\
		my_strlen.c		\
		my_lenarray.c		\
		my_put_nbr.c		\
		my_perror.c		\
		my_parray.c		\
		my_strlen.c		\
		my_strcmp.c		\
		my_strcpy.c		\
		my_strcat.c		\
		my_strdup.c		\
		my_printf.c		\
		my_str_to_array.c	\
		my_free_array.c		\

all :	$(NAME)
$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean :	clean
	$(RM) $(NAME)

re :	fclean all

.PHONY:	all clean fclean re