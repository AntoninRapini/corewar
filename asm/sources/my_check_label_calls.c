/*
** my_check_label_calls.c for corewar in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_corewar/asm/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Fri Mar 31 16:58:16 2017 Antonin Rapini
** Last update Fri Mar 31 18:43:37 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "my_asm.h"
#include "utils.h"

int my_label_exists(t_labellist *labels, char *param)
{
  while (labels != NULL)
    {
      if (my_strcmp(param, labels->label->name) == 0)
	return (1);
      labels = labels->next;
    }
  return (0);
}

int	my_check_label_calls(t_labellist *labels, t_instlist *instructs)
{
  int	i;

  while (instructs != NULL)
    {
      i = 0;
      while (instructs->instruct->params[i].param)
	{
	  if (instructs->instruct->params[i].islabel)
	    {
	      if (!my_label_exists(labels,
				   instructs->instruct->params[i].param))
		return (1);
	    }
	  i++;
	}
      instructs = instructs->next;
    }
  return (0);
}
