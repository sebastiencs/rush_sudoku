/*
** main.c for rush in /home/chapui_s/travaux/rush_sudoku
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Sat Mar  1 00:40:24 2014 chapui_s
** Last update Sat Mar  1 00:54:35 2014 chapui_s
*/

#include "unistd.h"
#include <stdlib.h>

void		my_putchar(char c)
{
  write(1, &c, 1);
}

void		my_putnbr(int nb)
{
  if (nb < 0)
  {
    my_putchar('-');
    nb = -nb;
  }
  if (nb >= 10)
    my_putnbr(nb / 10);
  my_putchar((nb % 10) + '0');
}

void		my_putstr(char *str)
{
  while (str && *str)
    write(1, str++, 1);
}

int		is_good_line(int **tab, int nb_to_test, int line)
{
  unsigned int	i;

  i = 0;
  while (i < 9)
  {
    if (tab[line][i] == nb_to_test)
      return (-1);
    i += 1;
  }
  return (0);
}

int		is_good_col(int **tab, int nb_to_test, int col)
{
  unsigned int	i;

  i = 0;
  while (i < 9)
  {
    if (tab[i][col] == nb_to_test)
      return (-1);
    i += 1;
  }
  return (0);
}

int		is_good_square(int **tab, int nb_to_test, int line, int col)
{
  unsigned int	line_cur;
  unsigned int	col_cur;
  unsigned int	i;
  unsigned int	j;

  i = 0;
  line_cur = (line < 3) ? (0) : (line < 6) ? (3) : (6);
  col_cur = (col < 3) ? (0) : (col < 6) ? (3) : (6);
  while (i < 3)
  {
    j = 0;
    while (j < 3)
    {
      if (tab[line_cur + i][col_cur + j] == nb_to_test)
	return (-1);
      j += 1;
    }
    i += 1;
  }
  return (0);
}

int		is_good(int **tab, int nb_to_test, int line, int col)
{
  int		result;

  result = 0;
  result += is_good_line(tab, nb_to_test, line);
  result += is_good_col(tab, nb_to_test, col);
  result += is_good_square(tab, nb_to_test, line, col);
  return (result);
}

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

int	resolve_sudoku(int **tab, int line, int col)
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

int	main()
{
  int	**tab;
  int	i;
  int	j;

  if ((tab = (int**)malloc(sizeof(int*) * 9)) == NULL)
  {
    my_putstr("error: malloc\n");
    return (-1);
  }
  i = 0;
  while (i < 9)
  {
    j = 0;
    if ((tab[i] = (int*)malloc(sizeof(int) * 9)) == NULL)
      return (-1);
    while (j < 9)
    {
      tab[i][j] = 0;
      j += 1;
    }
    i += 1;
  }

  resolve_sudoku(tab, 0, 0);

  i = 0;
  while (i < 9)
  {
    j = 0;
    while (j < 9)
    {
      my_putnbr(tab[i][j]);
      my_putstr(" ");
      j += 1;
    }
    my_putstr("\n");
    i += 1;
  }
  return (0);
}
