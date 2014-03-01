/*
** ldcc_fct2.c for fct in /home/denel-_l/rendu/PSU_2013_my_select
**
** Made by lowik_denel
** Login   <denel-_l@epitech.net>
**
** Started on  Thu Jan 16 12:45:07 2014 lowik_denel
** Last update Sat Mar  1 02:43:42 2014 chapui_s
*/

#include <stdlib.h>
#include "../sudoku.h"

void		add_inqueue(t_root *root, int nb)
{
  pushbefore(root, nb);
}

void		del_elem(t_root *element)
{
  element->prev->next = element->next;
  element->next->prev = element->prev;
  free(element);
}

void		del_firstelem(t_root *root)
{
  if (root->next != root)
    del_elem(root->next);
}

void		del_lastelem(t_root *root)
{
  if (root->prev != root)
    del_elem(root->prev);
}
