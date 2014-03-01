/*
** xmalloc.c for xmal in /home/denel-_l/rendu/CPE_2013_Rush1
**
** Made by lowik_denel
** Login   <denel-_l@epitech.net>
**
** Started on  Sun Dec 15 10:18:07 2013 lowik_denel
** Last update Sat Mar  1 02:45:18 2014 chapui_s
*/

#include <stdlib.h>
#include <unistd.h>
#include "../sudoku.h"

void	*xmalloc(size_t size)
{
  void	*tmp;

  tmp = NULL;
  tmp = malloc(size);
  my_memset(tmp, (--size));
  if (tmp == NULL)
    {
      write(1, "MALLOC FAIL\n", 13);
      exit(1);
    }
  return (tmp);
}

void	*xtmalloc(size_t size)
{
  void	*tmp;

  tmp = NULL;
  tmp = malloc(size);
  if (tmp == NULL)
    {
      write(1, "MALLOC FAIL\n", 13);
      exit(1);
    }
  return (tmp);
}

char		*my_memset(char *str, int i)
{
  int		j;

  j = -1;
  while (++j < i)
    str[j] = 0;
  str[i] = '\0';
  return (str);
}
