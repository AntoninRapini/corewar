/*
** op_live.c for  in /home/romain.pillot/projects/CPE_2016_corewar/vm/src/mnemonic
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Sun Apr  2 03:16:05 2017 romain pillot
** Last update Tue Apr  4 11:24:06 2017 romain pillot
*/

#include "operation.h"
#include "util.h"

void	op_aff(t_vm *vm, t_process *process, t_param params[4])
{
  int	reg;
  int	value;

  if ((reg = parse_value(params[0], vm, process, NO_MOD)) == -1)
    {
      process->carry = false;
      return ;
    }
  value = process->registers[reg - 1];
  display_char(value == 42 ? '*' : value % 256, false);
  process->carry = true;
}
