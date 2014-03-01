/*
** ldcc_fct3.c for fct2 in /home/denel-_l/rendu/PSU_2013_my_select
**
** Made by lowik_denel
** Login   <denel-_l@epitech.net>
**
** Started on  Thu Jan 16 12:45:18 2014 lowik_denel
** Last update Sat Mar  1 02:27:06 2014 chapui_s
*/

#include <stdlib.h>
#include "../sudoku.h"

t_root		*firstelem(t_root *root)
{
  if (root->next != root)
    return root->next;
  else
    return (NULL);
}

t_root		*lastelem(t_root *root)
{
  if (root->prev != root)
    return root->prev;
  else
    return (NULL);
}
