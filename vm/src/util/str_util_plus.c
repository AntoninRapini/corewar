/*
** str_util_plus.c for  in /home/romain.pillot/projects/PSU_2016_tetris/src/util
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Wed Mar 15 09:14:24 2017 romain pillot
** Last update Tue Apr  4 21:30:57 2017 romain pillot
*/

#include "util.h"
#include <stdlib.h>

char    *fillstr(char *str, char c, int bytes)
{
  int   i;

  if (!str)
    return (NULL);
  i = -1;
  while (++i < bytes)
    str[i] = c;
  return (str);
}

char	*get_filename(char *str)
{
  int	i;

  i = str_length(str);
  while (str[--i])
    if (str[i] == '.')
      str[i] = 0;
  return (str);
}

char	*copystr(unsigned char *from, int lenf,
		 unsigned char *to, int index)
{
  int	len;
  int	i;

  i = 0;
  if (!from || !to || index < 0)
    return (NULL);
  while (i < lenf)
    to[index++] = from[i++];
  to[index] = 0;
  return (to);
}

char    *strdup_len(char *str, int len)
{
  int	i;
  char	*new;

  if (!str || !(new = malloc(sizeof(char) * (len + 1))))
    return (NULL);
  i = -1;
  while (++i < len)
    new[i] = str[i];
  new[i] = 0;
  return (new);
}
