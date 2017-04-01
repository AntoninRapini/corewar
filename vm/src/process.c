/*
** process.c for  in /home/romain.pillot/projects/CPE_2016_corewar/vm/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Thu Mar 30 12:48:47 2017 romain pillot
** Last update Wed Apr  5 08:05:14 2017 romain pillot
*/

#include "vm.h"
#include "util.h"
#include "list.h"
#include <unistd.h>
#include <stdlib.h>
#include "file.h"

static int	next_process_id(t_list *list, int id)
{
  t_elem	*elem;

  id = id == -1 ? list->size + 1 : id;
  elem = list->first;
  while (elem)
    {
      if (((t_process *) elem->get)->id == id)
	return (next_process_id(list, ++id));
      elem = elem->next;
    }
  return (id);
}

t_process       *process_init(t_vm *vm, unsigned char *prog, int id, int start_pc)
{
  t_process	*process;
  int		file;
  char		*content;

  if ((file = open_file(prog)) == -1 ||
      !(process = malloc(sizeof(t_process))) ||
      !(content = file_content(process, file)))
    return (NULL);
  if (!valid_program(content) || !id || !start_pc)
    {
      fdisplay_format(id && start_pc ? "%s: invalid program (invalid magic)\n" :
		      "%s: invalid option's parameter ((int)param > 0)\n", prog);
      free(content);
      free(process);
      return (NULL);
    }
  decode_header_name(process->name, content);
  process->id = next_process_id(vm->processes, id);
  process->data_addr = (process->pc = start_pc % MEM_SIZE);
  process->cycle_cooldown = (process->last_live_cycle = 0);
  process->registers[0] = process->id;
  process->data = strdup_len(content + HEADER_LENGTH, process->data_len);
  list_add(vm->processes, process);
  safe_free(content);
  close(file);
  return (process);
}

/*
** TODO: improve space between processes when a
**       starting address is specified (currently jump + 100 bytes)
*/
static void	write_data(t_process *process, unsigned char mem[MEM_SIZE], int index)
{
  int		i;
  bool		enough_place;

  i = -1;
  while (++i < process->data_len &&
	 (enough_place = !(mem[(index + i) % MEM_SIZE])));
  if (!enough_place)
    return (write_data(process, mem, index + i + 500));
  process->pc = index;
  process->data_addr = index;
  i = -1;
  while (++i < process->data_len)
    mem[(index + i) % MEM_SIZE] = process->data[i];
}

void		process_insertall(t_vm *vm)
{
  int		total_data;
  int		between;
  t_elem	*proc;
  int		start_addr;

  total_data = 0;
  proc = vm->processes->first;
  while (proc)
    {
      total_data += ((t_process *) proc->get)->data_len;
      proc = proc->next;
    }
  between = (MEM_SIZE - total_data) / vm->processes->size;
  total_data = 0;
  proc = vm->processes->first;
  while (proc)
    {
      memfill(((t_process *) proc->get)->registers, 0, REG_NUMBER);
      write_data((t_process *) proc->get, vm->memory,
		 (start_addr = ((t_process *) proc->get)->data_addr) == -1 ?
		 total_data : start_addr);
      total_data += start_addr == -1 ?
	between + ((t_process *) proc->get)->data_len : 0;
      proc = proc->next;
    }
}

void	process_kill(t_vm *vm, t_process **ptr)
{
  safe_free((*ptr)->data);
  safe_free(list_dremove(vm->processes, (void **) ptr));
}
