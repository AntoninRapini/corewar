/*
** out_util_more.c for  in /home/romain.pillot/projects/CPE_2016_corewar/vm/src/util
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Fri Mar 31 20:39:29 2017 romain pillot
** Last update Fri Mar 31 20:42:12 2017 romain pillot
*/

#include <unistd.h>

void	display_n(char *str, int bytes)
{
  write(1, str, bytes);
}
