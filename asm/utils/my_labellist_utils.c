/*
** my_labellist_utils.c for corewar in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_corewar/asm/utils
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Fri Mar 31 19:31:54 2017 Antonin Rapini
** Last update Fri Mar 31 20:20:55 2017 Antonin Rapini
*/

#include "my_asm.h"
#include <stdlib.h>

void *my_free_labellist_item(t_labellist *label)
{
  if (label != NULL)
    {
      if (label->label != NULL)
	{
	  if (label->label->name != NULL)
	    free(label->label->name);
	  free(label->label);
	}
      free(label);
    }
  return (NULL);
}

void		*my_free_labellist(t_labellist *labels)
{
  t_labellist	*tmp;

  tmp = labels;
  while (labels != NULL)
    {
      labels = labels->next;
      my_free_labellist_item(tmp);
      tmp = labels;
    }
  return (NULL);
}

t_labellist	*my_init_labellist_item()
{
  t_labellist	*item;

  if ((item = malloc(sizeof(t_labellist))) == NULL)
    return (NULL);
  if ((item->label = malloc(sizeof(t_label))) == NULL)
    {
      free(item);
      return (NULL);
    }
  item->next = NULL;
  item->label->pos = 0;
  item->label->name = NULL;
  return (item);
}
