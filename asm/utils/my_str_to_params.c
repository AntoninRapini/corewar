/*
** my_str_to_wordtab.c for bsminishell in /home/antonin.rapini/ModulesTek1/ShellProgramming/bsminishell/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Jan  4 14:22:56 2017 Antonin Rapini
** Last update Sat Apr  1 07:34:37 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "utils.h"
#include "my_asm.h"

int	my_getparamscount(char *str)
{
  int	wordcount;

  wordcount = 0;
  while (*str && *str != '#')
    {
      if (*str != ' ' && *str != ',' && *str != '\t' && *str != '#')
	{
	  wordcount++;
	  while (*str && *str != ' ' && *str != ',' && *str != '\t' && *str != '#')
	    str++;
	}
      else
	str++;
    }
  return (wordcount);
}

void	my_populate_params(t_param *params, char *str, int size)
{
  int	arr_i;
  int	wordsize;

  wordsize = 0;
  arr_i = 0;
  while (arr_i < size)
    {
      if (*str != ',' && *str != ' ' && *str != '\t' && *str != '#')
	{
	  while (*str && *str != ' ' && *str != ',' && *str != '#' && *str != '\t')
	    {
	      wordsize++;
	      str++;
	    }
	  params[arr_i].param = my_strndup(str - wordsize, wordsize);
	  wordsize = 0;
	  arr_i++;
	}
      else
	str++;
    }
  params[arr_i].param = NULL;
}

t_param		*my_str_to_params(char *str)
{
  t_param	*arr;
  int		size;

  size = my_getparamscount(str);
  if ((arr = malloc(sizeof(t_param) * (size + 1))) == NULL)
    return (NULL);
  my_populate_params(arr, str, size);
  return (arr);
}
