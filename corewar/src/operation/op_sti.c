/*
** op_live.c for  in /home/romain.pillot/projects/CPE_2016_corewar/vm/src/mnemonic
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Sun Apr  2 03:16:05 2017 romain pillot
** Last update Tue Apr  4 11:42:17 2017 romain pillot
*/

#include "operation.h"

void	op_sti(t_vm *vm, t_process *process, t_param params[4])
{
  int	value1;
  int	value2;
  int	reg_val;

  reg_val = -1;
  if ((reg_val = parse_value(params[0], vm, process, NO_MOD)) != -1)
    {
      value1 = parse_value(params[1], vm, process, NO_MOD);
      value2 = parse_value(params[2], vm, process, NO_MOD);
      vm->memory[(process->pc + (value1 + value2) % IDX_MOD) % MEM_SIZE] = reg_val;
    }
}
