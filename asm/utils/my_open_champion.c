/*
** my_open_champion.c for corewar in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_corewar/asm/utils
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Tue Mar 28 06:25:14 2017 Antonin Rapini
** Last update Tue Mar 28 06:41:02 2017 Antonin Rapini
*/

#include "utils.h"
#include <fcntl.h>
#include <unistd.h>

int	my_check_filename(char *file)
{
  int	i;

  i = my_strlen(file);
  if (i < 3)
    return (-1);
  return (my_strcmp(".s", file + i - 2));
}

int my_open_champion(char *file)
{
  if (my_check_filename(file))
    return (-1);
  return (open(file, O_RDONLY));
}
