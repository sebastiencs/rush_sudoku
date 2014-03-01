/*
** main.c for rush in /home/chapui_s/travaux/rush_sudoku
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Sat Mar  1 00:40:24 2014 chapui_s
** Last update Sat Mar  1 03:34:19 2014 chapui_s
*/

#include "unistd.h"
#include "sudoku.h"

void		disp_sudoku(t_root *list_cur, t_root *root, int **tab)
{
  unsigned int	i;
  unsigned int	j;

  i = 0;
  my_putstr("|------------------|\n");
  while (i < 9)
  {
    j = 0;
    my_putstr("| ");
    while (j < 9)
    {
      my_putnbr(tab[i][j]);
      if (j < 8)
	my_putstr(" ");
      j += 1;
    }
    my_putstr("|\n");
    i += 1;
  }
  my_putstr("|------------------|\n");
  if (list_cur->next != root->prev)
    my_putstr("####################\n");
}
