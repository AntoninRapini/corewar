/*
** my_strdup_size.c for my_strdup_size in /home/antonin.rapini/MyPrograms
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Oct 13 15:26:27 2016 Antonin Rapini
** Last update Sun Mar 12 19:45:41 2017 Antonin Rapini
*/

#include <stdlib.h>

char	*my_strndup(char *src, int size)
{
  char	*dest;
  int	i;

  i = 0;
  if ((dest = malloc(sizeof(char) * (size + 1))) == NULL)
    return (NULL);
  dest[size] = '\0';
  while (i < size)
    {
      dest[i] = src[i];
      i++;
    }
  return (dest);
}
