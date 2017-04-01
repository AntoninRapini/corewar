/*
** op_live.c for  in /home/romain.pillot/projects/CPE_2016_corewar/vm/src/mnemonic
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Sun Apr  2 03:16:05 2017 romain pillot
** Last update Mon Apr  3 17:06:12 2017 romain pillot
*/

#include "operation.h"

void	op_add(t_vm *vm, t_process *process, t_param params[4])
{
  int	registera;
  int	registerb;

  registera = parse_value(params[0], vm, process, NO_MOD);
  registerb = parse_value(params[1], vm, process, NO_MOD);
  if (registera != -1 && registerb != -1 && params[2].type == T_REG &&
      params[2].value > 0 && params[2].type < 17)
    {
      process->registers[params[2].value - 1] = registera + registerb;
      process->carry = true;
    }
  else
    process->carry = false;
}
