/*
** my_wordtab_utils.c for my_wordtab_utils in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_tetris/utils
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sun Mar 12 20:25:38 2017 Antonin Rapini
** Last update Sun Apr  2 08:12:54 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "utils.h"

char	**my_init_wordtab(int size)
{
  char	**wordtab;
  int	i;

  i = 0;
  if ((wordtab = malloc(sizeof(char *) * (size + 1))) == NULL)
    return (NULL);
  while (i < size + 1)
    {
      wordtab[i] = NULL;
      i++;
    }
  return (wordtab);
}

void	my_free_wordtab(char **tab)
{
  int	i;

  i = 0;
  if (tab != NULL)
    {
      while (tab[i++])
	free(tab[i - 1]);
      free(tab);
    }
}

void	my_show_wordtab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i++])
    {
      my_putstr(tab[i - 1]);
      my_putchar('\n');
    }
}

int	my_wordtablen(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}
