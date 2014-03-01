/*
** main.c for rush in /home/chapui_s/travaux/rush_sudoku
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Sat Mar  1 00:40:24 2014 chapui_s
** Last update Sat Mar  1 03:45:45 2014 chapui_s
*/

#include "unistd.h"
#include <stdlib.h>

#include "sudoku.h"

int		find_nb(int **tab, int line, int col)
{
  unsigned int	nb_to_test;

  nb_to_test = 1;
  while (nb_to_test < 10)
  {
    if (is_good(tab, nb_to_test, line, col) == 0)
    {
      tab[line][col] = nb_to_test;
      if (resolve_sudoku(tab, line, col + 1) == 1)
	return (1);
    }
    nb_to_test += 1;
  }
  tab[line][col] = 0;
  return (0);
}

int		resolve_sudoku(int **tab, int line, int col)
{
  if (col == 9)
  {
    line += 1;
    col = 0;
  }
  if (line == 9)
    return (1);
  if (tab[line][col] == 0)
    return (find_nb(tab, line, col));
  else
    return (resolve_sudoku(tab, line, col + 1));
}

int		main()
{
  t_root	*list;
  t_root	*tmp;

  list = read_map();
  tmp = list->next;
  while (tmp != list->prev)
  {
    resolve_sudoku(tmp->tabb, 0, 0);
    disp_sudoku(tmp, list, tmp->tabb);
    tmp = tmp->next;
  }
  return (0);
}
