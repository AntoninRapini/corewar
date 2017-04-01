/*
** util.c for  in /home/romain.pillot/projects/PSU_2016_minishell1/src/util
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Thu Mar  9 15:55:33 2017 romain pillot
** Last update Thu Mar 16 10:39:01 2017 romain pillot
*/

#include "util.h"
#include <stdlib.h>

bool	safe_free(void *ptr)
{
  bool	done;

  if ((done = ptr != NULL))
    free(ptr);
  return (done);
}

void    safe_freetab(char **tab)
{
  int   i;

  i = -1;
  while (tab && tab[++i])
    free(tab[i]);
  if (tab)
    free(tab);
}

bool	safe_freesub(char **ptr, bool free_sub)
{
  bool	done;

  if ((done = ptr != NULL))
    {
      if (free_sub && (done = *ptr != NULL))
	free(*ptr);
      free(ptr);
    }
  return (done);
}

void	*memfill(void *ptr, int val, int bytes)
{
  char	*cast;

  cast = (char *) ptr;
  while (bytes--)
    *cast++ = val;
  return (char *) ptr;
}
