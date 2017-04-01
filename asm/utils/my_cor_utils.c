/*
** my_cor_utils.c for corewar in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_corewar/asm/utils
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Tue Mar 28 05:40:58 2017 Antonin Rapini
** Last update Fri Mar 31 21:53:09 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "my_asm.h"
#include "utils.h"

void *my_free_cor(t_cor *cor)
{
  if (cor != NULL)
    {
      if (cor->header != NULL)
	free(cor->header);
      my_free_labellist(cor->labels);
      my_free_instlist(cor->instructs);
      my_free_wordtab(cor->file);
      free(cor);
    }
  return (NULL);
}

t_header	*my_init_header()
{
  t_header	*header;

  if ((header = malloc(sizeof(t_header))) == NULL)
    return (NULL);
  my_memset(header->prog_name, 0, PROG_NAME_LENGTH);
  my_memset(header->comment, 0, COMMENT_LENGTH);
  my_memset(header->prog_len_str, 0, PROG_LEN_LENGTH);
  return (header);
}

t_cor	*my_init_cor()
{
  t_cor	*cor;

  if ((cor = malloc(sizeof(t_cor))) == NULL)
    return (NULL);
  if ((cor->header = my_init_header()) == NULL)
    return (my_free_cor(cor));
  cor->file = NULL;
  cor->labels = NULL;
  cor->instructs = NULL;
  cor->prog_len = 0;
  return (cor);
}
