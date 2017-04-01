/*
** op_live.c for  in /home/romain.pillot/projects/CPE_2016_corewar/vm/src/mnemonic
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Sun Apr  2 03:16:05 2017 romain pillot
** Last update Tue Apr  4 10:41:31 2017 romain pillot
*/

#include "operation.h"

void	op_zjmp(t_vm *vm, t_process *process, t_param params[4])
{
  if (process->carry)
    process->pc = process->pc + params[0].value % IDX_MOD;
}
