/*
** my_write_instructions.c for corewar in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_corewar/asm/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Mar 30 17:34:13 2017 Antonin Rapini
** Last update Fri Mar 31 14:58:12 2017 Antonin Rapini
*/

#include "sources.h"
#include "my_asm.h"
#include "utils.h"
#include <unistd.h>
#include <stdlib.h>

int	my_write_params(int fd, t_param *params, t_labellist *labels, int pos)
{
  int	i;
  int	nbr;

  i = 0;
  while (params[i].param)
    {
      if (params[i].islabel)
	{
	  if (my_write_label(fd, &(params[i]), labels, pos))
	    return (1);
	}
      else
	{
	  nbr = my_getnbr(params[i].param, NULL);
	  if (my_write_value(fd, nbr, params[i].size))
	    return (1);
	}
      i++;
    }
  return (0);
}

void	my_write_code(int fd, int code, int codingbyte)
{
  char	strcode[1];

  strcode[0] = code;
  write(fd, strcode, 1);
  if (codingbyte != -1)
    {
      strcode[0] = codingbyte;
      write(fd, strcode, 1);
    }
}

int my_write_instructions(int fd, t_cor *cor)
{
  while (cor->instructs != NULL)
    {
      my_write_code(fd, cor->instructs->instruct->code,
		    cor->instructs->instruct->codingbyte);
      if (my_write_params(fd, cor->instructs->instruct->params, cor->labels,
			  cor->instructs->instruct->pos))
	return (1);
      cor->instructs = cor->instructs->next;
    }
  return (0);
}
