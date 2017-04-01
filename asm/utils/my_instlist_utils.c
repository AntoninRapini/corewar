/*
** my_instlist_utils.c for corewar in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_corewar/asm/utils
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Fri Mar 31 21:27:46 2017 Antonin Rapini
** Last update Fri Mar 31 21:48:06 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "my_asm.h"

void	*my_free_params(t_param *params)
{
  int	i;

  i = 0;
  if (params != NULL)
    {
      while (params[i].param)
	{
	  free(params[i].param);
	  i++;
	}
      free(params);
    }
  return (NULL);
}

void *my_free_instlist_item(t_instlist *item)
{
  if (item != NULL)
    {
      if (item->instruct != NULL)
	{
	  if (item->instruct->name != NULL)
	    free(item->instruct->name);
	  my_free_params(item->instruct->params);
	  free(item->instruct);
	}
      free(item);
    }
  return (NULL);
}

void		*my_free_instlist(t_instlist *list)
{
  t_instlist	*tmp;

  tmp = list;
  while (list != NULL)
    {
      list = list->next;
      my_free_instlist_item(tmp);
      tmp = list;
    }
  return (NULL);
}

t_instlist	*my_init_instlist_item()
{
  t_instlist	*item;

  if ((item = malloc(sizeof(t_instlist))) == NULL)
    return (NULL);
  if ((item->instruct = malloc(sizeof(t_instruct))) == NULL)
    return (my_free_instlist_item(item));
  item->next = NULL;
  item->instruct->name = NULL;
  item->instruct->params = NULL;
  item->instruct->code = 0;
  item->instruct->codingbyte = 0;
  item->instruct->pos = 0;
  return (item);
}
