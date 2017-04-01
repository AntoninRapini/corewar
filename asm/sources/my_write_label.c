/*
** my_write_label.c for corewar in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_corewar/asm/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Fri Mar 31 12:40:01 2017 Antonin Rapini
** Last update Fri Mar 31 22:03:27 2017 Antonin Rapini
*/

#include <stdlib.h>
#include <unistd.h>
#include "utils.h"
#include "my_asm.h"
#include "sources.h"

int	my_write_diff(int fd, t_param *param, int diff)
{
  int	max;

  max = param->size == 2 ? 255 : 65535;
  if (diff >= 0)
    {
      my_write_value(fd, 0 + (diff / max), param->size / 2);
      my_write_value(fd, diff, param->size / 2);
    }
  else
    {
      my_write_value(fd, max + (diff / max), param->size / 2);
      my_write_value(fd, max + diff  + 1, param->size / 2);
    }
  return (0);
}

int my_write_label(int fd, t_param *param, t_labellist *labels, int pos)
{
  while (labels != NULL)
    {
      if (my_strcmp(param->param, labels->label->name) == 0)
	return (my_write_diff(fd, param, labels->label->pos - pos));
      labels = labels->next;
    }
  return (1);
}
