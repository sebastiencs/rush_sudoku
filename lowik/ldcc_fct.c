/*
** ldcc_fct.c for fct in /home/denel-_l/rendu/PSU_2013_my_select
**
** Made by lowik_denel
** Login   <denel-_l@epitech.net>
**
** Started on  Thu Jan 16 12:45:35 2014 lowik_denel
** Last update Sat Mar  1 02:44:41 2014 chapui_s
*/

#include <stdlib.h>
#include "../sudoku.h"

t_root		*init(void)
{
  t_root	*root;

  root = (t_root*)malloc(sizeof(*root));
  if (root != NULL)
    {
      root->nb = 0;
      root->prev = root;
      root->next = root;
    }
  else
    {
      my_putstr("Malloc Fail !\n");
      exit(1);
    }
  return (root);
}

void		emptyliste()
{
  t_root	*it;
  t_root	*nextt;

  nextt = list->next;
  while (nextt != list)
    {
      it = nextt;
      nextt = it->next;
      free(it);
    }
}

void		delliste(t_root **list)
{
  emptyliste(*list);
  free(*list);
  *list = NULL;
}

void		pushbefore(t_root *element, int nb)
{
  t_root	*nouvel_element;

  nouvel_element = (t_root*)malloc(sizeof(*nouvel_element));
  if (nouvel_element != NULL)
    {
      nouvel_element->nb = nb;
      nouvel_element->prev = element->prev;
      nouvel_element->next = element;
      element->prev->next = nouvel_element;
      element->prev = nouvel_element;
    }
  else
    {
      my_putstr("Malloc Fail !\n");
      exit(1);
    }
}
