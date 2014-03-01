##
## Makefile for rush in /home/chapui_s/travaux/rush_sudoku
## 
## Made by chapui_s
## Login   <chapui_s@epitech.eu>
## 
## Started on  Sat Mar  1 00:31:34 2014 chapui_s
## Last update Sat Mar  1 01:18:25 2014 chapui_s
##

NAME	= Sudoki-Bi

SRC	= main.c \
	  utils.c \
	  is_good.c

OBJ	= $(SRC:.c=.o)

CC	= gcc

RM	= rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
