/*
** my_free.c for corewar in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_corewar/asm/utils
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Fri Mar 31 19:29:02 2017 Antonin Rapini
** Last update Fri Mar 31 19:29:35 2017 Antonin Rapini
*/

#include <stdlib.h>

void *my_free(void *ptr)
{
  if (ptr != NULL)
    my_free(ptr);
  return (NULL);
}
