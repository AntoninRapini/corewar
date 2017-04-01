/*
** my_putstr.c for my_putstr in /home/antonin.rapini/CPool_Day04
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Oct  6 12:21:08 2016 Antonin Rapini
** Last update Fri Dec  2 21:52:01 2016 Antonin Rapini
*/

#include <unistd.h>

void	my_putstr(char *str)
{
  int	index;

  index = 0;
  while (str[index++]);
  write(1, str, index - 1);
}
