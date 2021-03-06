/*
** core.c for  in /home/romain.pillot/projects/CPE_2016_corewar/vm/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Sat Apr  1 03:46:54 2017 romain pillot
** Last update Wed Apr  5 08:53:07 2017 romain pillot
*/

#include "vm.h"
#include "util.h"
#include <stdbool.h>
#include <stdlib.h>

static void	init(t_param params[4])
{
  params[0].type = T_IND;
  params[0].value = 0;
  params[1].type = T_IND;
  params[1].value = 0;
  params[2].type = T_IND;
  params[2].value = 0;
  params[3].type = T_IND;
  params[3].value = 0;
}

static bool	on_cooldown(t_vm *vm, t_process *proc)
{
  t_op          *op;
  t_param       params[4];
  int           param_bytes;

  init(params);
  if (!(proc->cycle_cooldown))
    {
      if ((op = parse_operation(vm->memory[proc->pc % MEM_SIZE]))->code != OP_NULL &&
	  (param_bytes = parse_params(proc, vm->memory, op, params)))
	op->execute(vm, proc, params);
      proc->pc += param_bytes;
      proc->cycle_cooldown = -1;
    }
  else if (proc->cycle_cooldown > 0)
      proc->cycle_cooldown--;
  else
    return (false);
  return (true);
}

static void	on_cycle(t_vm *vm, void **proc_ptr)
{
  t_process	*proc;
  t_op		*op;
  t_param	params[4];
  int		param_bytes;

  proc = (t_process *) (*proc_ptr);
  init(params);
  if (vm->current_cycle - vm->last_die_cycle == vm->cycle_to_die &&
      proc->last_live_cycle <= vm->last_die_cycle)
    return (process_kill(vm, (t_process **) proc_ptr));
  if (on_cooldown(vm, proc))
    return ;
  else if ((op = parse_operation(vm->memory[proc->pc % MEM_SIZE]))->code != OP_NULL &&
	   parse_params(proc, vm->memory, op, params))
    proc->cycle_cooldown = op->cycles;
  else
    proc->pc++;
}

static void	check_end(t_vm *vm)
{
  t_elem	*elem;
  t_elem	*previous;

  previous = NULL;
  if (!(elem = vm->processes->first))
    {
      vm->running = false;
      return ;
    }
  while (elem)
    {
      if (previous &&
	  ((t_process *) previous->get)->id != ((t_process *) elem->get)->id)
	return ;
      previous = elem;
      elem = elem->next;
    }
  display_format("The player %d(%s) has won.\n",
		 ((t_process *) previous->get)->id,
		 ((t_process *) previous->get)->name);
  vm->running = false;
}

void		launch_cycles(t_vm *vm)
{
  t_elem	*elem;
  t_elem	*next;

  process_insertall(vm);
  while (vm->running && ++(vm->current_cycle))
    {
      elem = vm->processes->first;
      while (elem && vm->running)
	{
	  next = elem->next;
	  on_cycle(vm, &(elem->get));
	  elem = next;
	  check_end(vm);
	}
      if ((vm->live_cooldown) <= 0)
	{
	  vm->cycle_to_die -= CYCLE_DELTA;
	  vm->live_cooldown = NBR_LIVE;
	}
      if (vm->current_cycle - vm->last_die_cycle == vm->cycle_to_die)
	vm->last_die_cycle = vm->current_cycle;
      if (!(--(vm->dump_cooldown)) && !(vm->running = false))
	dump_memory(vm->memory, 32);
    }
}
