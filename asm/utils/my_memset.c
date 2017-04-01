/*
** my_memset.c for tetris in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_tetris/utils
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Fri Mar 17 01:56:52 2017 Antonin Rapini
** Last update Fri Mar 17 02:01:57 2017 Antonin Rapini
*/

#include <stdlib.h>

void	my_memset(void *obj, char value, int size)
{
  int	i;
  char	*tmp;

  if (obj != NULL)
    {
      i = 0;
      tmp = (char *)obj;
      while (i++ < size)
	tmp[i - 1] = value;
    }
}
