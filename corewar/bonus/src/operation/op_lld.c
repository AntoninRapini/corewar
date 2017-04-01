/*
** op_live.c for  in /home/romain.pillot/projects/CPE_2016_corewar/vm/src/mnemonic
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Sun Apr  2 03:16:05 2017 romain pillot
** Last update Mon Apr  3 19:46:22 2017 romain pillot
*/

#include "operation.h"

void	op_lld(t_vm *vm, t_process *process, t_param params[4])
{
  int   value;
  int   reg;

  value = parse_value(params[0], vm, process, MOD);
  if (params[1].type == T_REG && params[1].value > 0
      && params[1].value < 17)
    {
      process->registers[params[1].value - 1] = value;
      process->carry = true;
    }
  else
    process->carry = false;
}
