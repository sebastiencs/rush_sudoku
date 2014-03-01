/*
** my_getnbr.c for my_getnbr in /home/denel-_l/rendu/Piscine-C-Jour_04
**
** Made by lowik_denel
** Login   <denel-_l@epitech.net>
**
** Started on  Fri Oct  4 17:52:08 2013 lowik_denel
** Last update Sat Mar  1 02:49:03 2014 chapui_s
*/

#include <stdlib.h>
#include "../sudoku.h"

void		loop_getnbr(char *src, int *nb, int *count)
{
  while (*count < (my_strlen(src)))
    {
      if ((src[*count] < 48) || (src[*count] > 57))
	*count = my_strlen(src) + 1;
      else
	{
	  *nb = *nb + (src[*count] - '0');
	  *nb = *nb * 10;
	  *count = *count + 1;
	}
    }
}

int		my_getnbr(char *src)
{
  int		nb;
  int		count;
  int		count_neg;

  nb = 0;
  count = 0;
  count_neg = 0;
  while ((src[count] < 48) || src[count] > 57)
    {
      if (src[count] == '-')
	count_neg = count_neg + 1;
      count = count + 1;
    }
  loop_getnbr((src), &nb, &count);
  nb = nb / 10;
  nb = ((count_neg % 2) == 0 ? nb : -nb);
  return (nb);
}
