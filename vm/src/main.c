/*
** main.c for  in /home/romain.pillot/projects/CPE_2016_corewar/vm/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Wed Mar 29 10:33:03 2017 romain pillot
** Last update Wed Apr  5 08:22:14 2017 romain pillot
*/

#include <stdlib.h>
#include <getopt.h>
#include "vm.h"
#include "option.h"
#include "util.h"
#include "list.h"

static int	free_and_exit(t_vm **to_free, int statement, char *err)
{
  t_elem        *elem;
  t_elem        *next;
  void          *data;

  if (err)
    display(err, true);
  elem = (*to_free)->processes->first;
  while (elem)
    {
      next = elem->next;
      data = list_eremove((*to_free)->processes, elem);
      safe_free(((t_process *) data)->data);
      safe_free(data);
      elem = next;
    }
  if ((*to_free)->processes)
    free((*to_free)->processes);
  if (*to_free)
    free(*to_free);
  *to_free = NULL;
  return (statement);
}

static t_vm	*vm_init()
{
  t_vm		*vm;

  if (!(vm = malloc(sizeof(t_vm))))
    return (NULL);
  vm->processes = list_create();
  vm->dump_cooldown = -1;
  vm->live_cooldown = NBR_LIVE;
  vm->cycle_to_die = CYCLE_TO_DIE;
  vm->last_die_cycle = 0;
  vm->current_cycle = 0;
  vm->running = true;
  memfill(vm->memory, 0, MEM_SIZE);
  return (vm);
}

int	main(int ac, char **args)
{
  t_vm	*vm;

  if (!(vm = vm_init()) || !valid_options(vm, ac, args))
    return (free_and_exit(&vm, 84, NULL));
  if (vm->processes->size < 2 || vm ->processes->size > 4)
    return (free_and_exit(&vm, 84,
			  "Error: need at least 2 programs and at most 4 programs.\n"));
  launch_cycles(vm);
  return (free_and_exit(&vm, EXIT_SUCCESS, NULL));
}

void	dump_memory(unsigned char memory[MEM_SIZE], int bline)
{
  int	i;
  int	counter;
  i = -1;
  counter = 0;
  while (++i < MEM_SIZE)
    {
      putnbr_hexa(memory[i], &counter, bline);
      if (!(counter % bline))
	display_char('\n', false);
    }
  display_char('\n', false);
}
