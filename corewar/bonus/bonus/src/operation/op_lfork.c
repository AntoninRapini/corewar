/*
** op_live.c for  in /home/romain.pillot/projects/CPE_2016_corewar/vm/src/mnemonic
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Sun Apr  2 03:16:05 2017 romain pillot
** Last update Wed Apr  5 08:19:15 2017 romain pillot
*/

#include "operation.h"
#include "util.h"
#include <stdlib.h>

static void     cpy(unsigned char *process, unsigned char *fork, int i)
{
  int           j;
  int           k;

  j = -1;
  k = 0;
  while (++j < i)
    *fork++ = process[k++ % MEM_SIZE];
  *fork = 0;
}

void		op_lfork(t_vm *vm, t_process *process, t_param params[4])
{
  unsigned char *data;
  t_process     *fork;
  int           i;

  data = malloc(sizeof(char) * (process->data_len + 1));
  cpy(vm->memory + process->data_addr, data, process->data_len);
  fork = malloc(sizeof(t_process));
  fork->id = process->id;
  cpy(process->name, fork->name, PROG_NAME_LENGTH);
  fork->data = data;
  fork->data_addr = process->pc + params[0].value;
  fork->pc = fork->data_addr;
  fork->data_len = process->data_len;
  fork->cycle_cooldown = 0;
  fork->last_live_cycle = 0;
  list_add(vm->processes, fork);
  i = -1;
  while(++i < process->data_len)
    vm->memory[(fork->pc + i) % MEM_SIZE] = fork->data[i];
}
