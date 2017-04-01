/*
** str_util_more.c for  in /home/romain.pillot/projects/PSU_2016_minishell1/src/util
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Wed Mar  8 10:25:12 2017 romain pillot
** Last update Sun Apr  2 14:19:29 2017 Antonin Rapini
*/

#include <stdbool.h>
#include "util.h"
#include <stdlib.h>

bool	start_withstr(char *str, char *charset)
{
  if (!str || !charset)
    return (false);
  while (*charset)
    if (*str++ != *charset++)
      return (false);
  return (true);
}

bool    end_withstr(char *str, char *charset)
{
  int   i;
  int   j;

  if (!str || !charset)
    return (false);
  i = str_length(str) - 1;
  j = str_length(charset) - 1;
  while (j >= 0)
    if (i < j || str[i--] != charset[j--])
      return (false);
  return (true);
}

char	*strdupl(char *str)
{
  char	*new;
  char	*hold;

  if (!str || !(hold = (new = malloc(sizeof(char) * (str_length(str) + 1)))))
    return (NULL);
  while (*str)
    *new++ = *str++;
  *new = 0;
  return (hold);
}

char	*concatstr(char *a, char *b, bool free_a)
{
  char	*concat;
  char	*hold;
  char	*hold_a;

  if (!(hold = (concat = malloc(sizeof(char) *
				(str_length(a) + str_length(b) + 1)))))
    return (NULL);
  hold_a = a;
  while (a && *a)
    *concat++ = *a++;
  while (b && *b)
    *concat++ = *b++;
  *concat = 0;
  if (free_a && hold_a)
    free(hold_a);
  return (hold);
}

bool    containstr(char *str, char *charset)
{
  int   i;

  i = 0;
  if (!charset || !(*charset))
    return (false);
  while (str && *str)
    if (*str++ == charset[i])
      if (!(charset[++i]))
	return (true);
      else
	continue;
    else
      i= 0;
  return (false);
}
