/*
** asm.c for asm in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_corewar/asm
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Mon Mar 27 14:24:49 2017 Antonin Rapini
** Last update Fri Mar 31 16:50:27 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "my_asm.h"
#include "sources.h"
#include "utils.h"

int		main(int ac, char **av)
{
  t_cor		*cor;

  if (ac >= 2)
    {
      if ((cor = my_get_champion(av[1])) == NULL)
	return (84);
      if (my_create_corfile(cor, av[1]))
	{
	  my_free_cor(cor);
	  return (84);
	}
      my_free_cor(cor);
      return (0);
    }
  return (84);
}
