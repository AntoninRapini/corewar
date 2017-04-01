/*
** op_live.c for  in /home/romain.pillot/projects/CPE_2016_corewar/vm/src/mnemonic
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Sun Apr  2 03:16:05 2017 romain pillot
** Last update Wed Apr  5 08:20:29 2017 romain pillot
*/

#include "operation.h"
#include <stdlib.h>
#include "util.h"

void		op_live(t_vm *vm, t_process *process, t_param params[4])
{
  int		value;
  int		i;
  t_elem	*curr;

  curr = vm->processes->first;
  i = 0;
  value = parse_value(params[0], vm, process, NO_MOD);
  if (!i)
    {
      display_format("The player %d(%s) is alive.\n", process->id,
		     process->name);
      return ;
    }
  while (curr != NULL)
    {
      display_format("live: %d - %d\n", value, ((t_process *) curr->get)->id);
      if (value == ((t_process *) curr->get)->id)
	{
	  ((t_process *) curr->get)->last_live_cycle = vm->current_cycle;
	  display_format("The player %d(%s) is alive.\n",
			 value, ((t_process *)curr->get)->name);
	  return ;
	}
      curr = curr->next;
    }
}
