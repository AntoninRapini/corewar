/*
** op_live.c for  in /home/romain.pillot/projects/CPE_2016_corewar/vm/src/mnemonic
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Sun Apr  2 03:16:05 2017 romain pillot
** Last update Tue Apr  4 09:27:51 2017 romain pillot
*/

#include "operation.h"

void	op_xor(t_vm *vm, t_process *process, t_param params[4])
{
  int   value1;
  int   value2;
  int   reg;

  value1 = parse_value(params[0], vm, process, NO_MOD);
  value2 = parse_value(params[1], vm, process, NO_MOD);
  if (value1 != -1 && value2 != -1 && params[2].type == REG
      && params[2].value > 0 && params[2].value < 17)
    {
      process->registers[params[2].value - 1] = value1 ^ value2;
      process->carry = true;
    }
  else
    process->carry = false;
}
