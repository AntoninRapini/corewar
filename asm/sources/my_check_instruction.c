/*
** my_check_instruction.c for corewar in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_corewar/asm/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Mar 29 15:41:26 2017 Antonin Rapini
** Last update Sun Apr  2 15:23:45 2017 romain pillot
*/

#include "my_asm.h"
#include "utils.h"
#include "sources.h"
#include <stdlib.h>

static t_op const op_tab[] =
{
  {"live", 1, {T_DIR}, 1},
  {"ld", 2, {T_DIR | T_IND, T_REG}, 2},
  {"st", 2, {T_REG, T_IND | T_REG}, 3},
  {"add", 3, {T_REG, T_REG, T_REG}, 4},
  {"sub", 3, {T_REG, T_REG, T_REG}, 5},
  {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6},
  {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7},
  {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8},
  {"zjmp", 1, {T_DIR}, 9},
  {"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10},
  {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11},
  {"fork", 1, {T_DIR}, 12},
  {"lld", 2, {T_DIR | T_IND, T_REG}, 13},
  {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14},
  {"lfork", 1, {T_DIR}, 15},
  {"aff", 1, {T_REG}, 16},
  {0, 0, {0}, 0}
};

int	my_get_codingbyte(int code, t_param *params)
{
  int	codingbyte;
  int	i;
  int	to_add;

  i = 0;
  codingbyte = 0;
  if (code == 1 || code == 9 || code == 12 || code == 15)
    return (-1);
  while (params[i].param)
    {
      to_add = params[i].type == T_REG ? 1 : params[i].type == T_DIR ? 2 : 3;
      codingbyte = (codingbyte << 2) + to_add;
      i++;
    }
  while (i < 4)
    {
      codingbyte = (codingbyte << 2);
      i++;
    }
  return (codingbyte);
}

int	my_get_optab_index(char *name)
{
  int	i;

  i = 0;
  while (op_tab[i].mnemonique && my_strcmp(op_tab[i].mnemonique, name) != 0)
    i++;
  if (op_tab[i].mnemonique == NULL)
    return (-1);
  return (i);
}

int	my_get_paramsize(int type, int opcode)
{
  int	isindex;

  isindex = (opcode >= 9 && opcode <= 15) && opcode != 13;
  return (type == 1 ? 1 : type == 4 || isindex ? 2 : 4);
}

int	my_check_instruction(t_instruct *inst)
{
  int	i;
  int	j;
  char	type;

  if ((j = my_get_optab_index(inst->name)) == -1)
    return (1);
  i = 0;
  inst->code = j + 1;
  while (inst->params[i].param)
    {
      if ((type = my_get_paramtype(inst->params + i)) == -1)
	return (1);
      inst->params[i].type = type;
      inst->params[i].size = my_get_paramsize(type, inst->code);
      my_clear_param(inst->params + i);
      if ((type ^ op_tab[j].type[i]) != op_tab[j].type[i] - type)
	return (1);
      i++;
    }
    if (i < (int)(op_tab[j].nbr_args))
      return (1);
  inst->codingbyte = my_get_codingbyte(inst->code, inst->params);
  return (0);
}
