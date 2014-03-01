/*
** main.c for rush in /home/chapui_s/travaux/rush_sudoku
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Sat Mar  1 00:40:24 2014 chapui_s
** Last update Sat Mar  1 01:45:10 2014 chapui_s
*/

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
