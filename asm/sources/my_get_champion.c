/*
** my_check_file.c for corewar in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_corewar/asm/utils
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Tue Mar 28 06:12:23 2017 Antonin Rapini
** Last update Sat Apr  1 07:20:02 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "my_asm.h"
#include "sources.h"
#include "utils.h"

t_cor	*my_get_champion(char *filename)
{
  t_cor	*cor;
  int	ret;

  if ((cor = my_init_cor()) == NULL)
    return (NULL);
  if ((cor->file = my_getfile(filename)) == NULL)
    return (my_free_cor(cor));
  if ((ret = my_get_header(cor->file, cor->header)) == -1)
    return (my_free_cor(cor));
  if (my_get_code(ret, cor))
    return (my_free_cor(cor));
  if (my_check_label_calls(cor->labels, cor->instructs))
    return (my_free_cor(cor));
  return (cor);
}
