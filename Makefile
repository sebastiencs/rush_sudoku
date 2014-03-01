##
## Makefile for rush in /home/chapui_s/travaux/rush_sudoku
## 
## Made by chapui_s
## Login   <chapui_s@epitech.eu>
## 
## Started on  Sat Mar  1 00:31:34 2014 chapui_s
## Last update Sat Mar  1 02:46:17 2014 chapui_s
##

NAME	= Sudoki-Bi

SRC	= main.c \
	  utils.c \
	  is_good.c \
	  disp.c \
	  get_next_line.c \
	  lowik/sudoki-bi.c \
	  lowik/ldcc_fct.c \
	  lowik/ldcc_fct2.c \
	  lowik/ldcc_fct3.c \
	  lowik/xmalloc.c \
	  lowik/my_getnbr.c

OBJ	= $(SRC:.c=.o)

CC	= gcc

CFLAGS	+= -Wall -Wextra

RM	= rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
