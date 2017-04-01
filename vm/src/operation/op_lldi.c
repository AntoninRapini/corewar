/*
** op_live.c for  in /home/romain.pillot/projects/CPE_2016_corewar/vm/src/mnemonic
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Sun Apr  2 03:16:05 2017 romain pillot
** Last update Tue Apr  4 10:48:44 2017 romain pillot
*/

#include "operation.h"

void	op_lldi(t_vm *vm, t_process *process, t_param params[4])
{
  int   value1;
  int   value2;
  int   value3;
  int   addr;

  value1 = parse_value(params[0], vm, process, MOD | IND) + 4;
  value2 = parse_value(params[1], vm, process, NO_MOD);
  if (value1 != -1 && value2 != -2)
    {
      addr = (process->pc + (value1 + value2));
      value3 = bytes_to_int(vm->memory[addr % MEM_SIZE],
			    vm->memory[(addr + 1) % MEM_SIZE],
			    vm->memory[(addr + 2) % MEM_SIZE],
			    vm->memory[(addr + 3) % MEM_SIZE]);
      process->registers[0] = value3;
      process->carry = true;
    }
  else
    process->carry = false;

}
