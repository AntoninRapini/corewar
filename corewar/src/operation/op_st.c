/*
** op_live.c for  in /home/romain.pillot/projects/CPE_2016_corewar/vm/src/mnemonic
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Sun Apr  2 03:16:05 2017 romain pillot
** Last update Tue Apr  4 09:24:18 2017 romain pillot
*/

#include "operation.h"

void	op_st(t_vm *vm, t_process *process, t_param params[4])
{
  int	value;

  if (params[0].type != T_REG)
    return ;
  value = parse_value(params[0], vm, process, NO_MOD);
  if (params[1].type == T_REG
      && (params[1].value > 0 && params[1].value < 17))
    process->registers[params[1].value - 1] = value;
  else if (params[1].type == T_IND)
    vm->memory[(process->pc + 34 % IDX_MOD) % MEM_SIZE] = value;
}
