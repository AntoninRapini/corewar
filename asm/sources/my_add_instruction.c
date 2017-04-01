/*
** my_add_instruction.c for corewar in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_corewar/asm/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Fri Mar 31 11:35:56 2017 Antonin Rapini
** Last update Fri Mar 31 21:47:00 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "my_asm.h"
#include "sources.h"
#include "utils.h"

int	my_instructionlen(t_instruct *instruct)
{
  int	len;
  int	i;
  int	usesindex;

  usesindex = (instruct->code >= 9 && instruct->code <= 15)
    && instruct->code != 13;
  i = 0;
  len = 1;
  len += instruct->codingbyte != -1 ? 1 : 0;
  while (instruct->params[i].param)
    {
      if (instruct->params[i].type == T_REG)
	len += 1;
      else if (instruct->params[i].type == T_IND || usesindex)
	len += 2;
      else if (instruct->params[i].type == T_DIR)
	len += 4;
      i++;
    }
  return (len);
}

char	*my_get_instruction_name(char *line, int i)
{
  char	*name;
  int	j;

  j = 0;
  while (line[i + j] && (line[i + j] != ' ' && line[i + j] != '\t'))
    j++;
  if ((name = my_strndup(line + i, j)) == NULL)
    return (NULL);
  return (name);
}

t_instlist	*my_get_instruction(char *line, int pos)
{
  t_instlist	*item;
  int		i;

  i = 0;
  while (line[i] && (line[i] == ' ' || line[i] == '\t'))
    i++;
  if ((item = my_init_instlist_item()) == NULL)
    return (NULL);
  if ((item->instruct->name = my_get_instruction_name(line , i)) == NULL)
    return (my_free_instlist_item(item));
  i += my_strlen(item->instruct->name);
  if ((item->instruct->params = my_str_to_params(line + i)) == NULL)
    return (my_free_instlist_item(item));
  if (my_check_instruction(item->instruct))
    return (my_free_instlist_item(item));
  item->instruct->pos = pos;
  return (item);
}

int		my_add_instruction(int i, t_cor *cor, t_instlist **startinst)
{
  t_instlist	*currinst;

  if ((currinst = my_get_instruction(cor->file[i], cor->prog_len)) == NULL)
    return (1);
  if (cor->instructs == NULL)
    cor->instructs = currinst;
  else
    {
      cor->instructs->next = currinst;
      cor->instructs = cor->instructs->next;
    }
  if ((*startinst) == NULL)
    (*startinst) = currinst;
  cor->prog_len += my_instructionlen(cor->instructs->instruct);
  return (0);
}
