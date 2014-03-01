/*
** sudoki-bi.c for sudo in /Users/benoitdenel/denel-_l/rendu/sudoki-bi
**
** Made by lowik_denel
** Login   <benoitdenel@epitech.net>
**
** Started on  Fri Feb 28 20:36:14 2014 lowik_denel
** Last update Sat Mar  1 03:39:55 2014 chapui_s
*/

#include <stdlib.h>
#include "../sudoku.h"

int		*filling_line(char *tmp)
{
  int		*line;
  int		i;
  int		j;

  i = 0;
  j = 2;
  line = malloc(sizeof(int) * 10);
  line[9] = '\0';
  while (tmp[j] != '\n' && tmp[j] != '|' && tmp[j])
    {
      if (tmp[j] == ' ')
	line[i] = 0;
      else
	line[i] = tmp[j] - '0';
      i++;
      j = j + 2;
    }
  return (line);
}

void		ffmal(t_root *it)
{
  int		i;

  i = 0;
  it->tabb = malloc(sizeof(int*) * 10);
  it->tabb[9] = '\0';
  while (i != 9)
    {
      it->tabb[i] = malloc(sizeof(int) * 10);
      it->tabb[i][9] = '\0';
      i++;
    }
}

void		load_it(int i)
{
  char		*tmp;
  int		j;
  int		k;
  t_root	*it;

  j = 0;
  k = 0;
  it = list->next;
  while(++j != i)
    it = it->next;
  ffmal(it);
  if ((tmp = get_next_line(0)) == NULL)
    return ;
  while (k <= 8)
  {
    tmp = get_next_line(0);
    it->tabb[k] = filling_line(tmp);
    k++;
  }
  tmp = get_next_line(0);
  pushbefore(list, ++i);
  load_it(i);
}

t_root		*read_map(void)
{
  int		i;

  i = 1;
  list = init();
  pushbefore(list, i);
  load_it(i);
  return (list);
}
