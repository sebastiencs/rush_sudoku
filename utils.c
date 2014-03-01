/*
** utils.c for rush in /home/chapui_s/travaux/rush_sudoku
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Sat Mar  1 01:17:22 2014 chapui_s
** Last update Sat Mar  1 02:42:16 2014 chapui_s
*/

#include "unistd.h"

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

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str && str[i])
    i += 1;
  return (i);
}
