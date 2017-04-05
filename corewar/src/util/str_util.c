/*
** str_util.c for  in /home/romain.pillot/projects/PSU_2016_minishell1/src/util
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Fri Mar  3 04:26:23 2017 romain pillot
** Last update Tue Mar 14 13:14:22 2017 romain pillot
*/

#include <stdlib.h>
#include "util.h"

int	count_char(char *str, char c)
{
  int	i;
  int	j;

  i = (j = 0);
  while (str && str[i] && ++i)
    if (str[i] == c)
      j++;
  return (j);
}

char	*rev_substr(char *str,
		    const char c,
		    const int index)
{
  int	i;
  int	j;
  int	k;
  char	*nw;

  i = (j = str_length(str));
  k = 0;
  while (--i >= 0)
    if (str && str[i] == c && ++k == index && !(k = 0))
      break;
  if (!str || !(nw = malloc(sizeof(char) * (j - i))))
    return (NULL);
  while (str[++i])
    nw[k++] = str[i];
  nw[k] = 0;
  return (nw);
}

char    *trimstr(char *str, char c)
{
  int   i;
  int   j;

  i = (j = 0);
  while (str && str[i])
    {
      if (c ? str[i] != c : str[i] != ' ' && str[i] != '\t')
	{
	  if (i && j && (c ? str[i - 1] == c :
			 str[i - 1] == ' ' || str [i - 1] == '\t'))
	    str[j++] = c ? c : ' ';
	  str[j++] = str[i++];
	}
      else
	i++;
    }
  if (str)
    str[j] = 0;
  return (str);
}

bool	equalstr(char *a, char *b)
{
  if (!a || !b)
    return (false);
  while (*a || *b)
    if (*a++ != *b++)
      return (false);
  return (true);
}

char    **splitstr(char *str, char delimiter)
{
  char  **tab;
  char  *hold;
  int   i;
  int   j;
  int   k;

  i = -1;
  trimstr(str, delimiter == ' ' ? 0 : delimiter);
  hold = str;
  if (!(tab = malloc(sizeof(char *) * ((count_char(str, delimiter) + 2)))))
    return (NULL);
  k = 0;
  while (str[++i])
    if (str[(j = i)] == delimiter || !(str[(j = i + 1)]))
      {
	tab[k++] = hold;
	hold = str + j + 1;
	str[j] = 0;
      }
  tab[k] = 0;
  return (tab);
}
