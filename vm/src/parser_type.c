/*
** parser_type.c for  in /home/romain.pillot/projects/CPE_2016_corewar/vm/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Sun Apr  2 05:40:37 2017 romain pillot
** Last update Sun Apr  2 15:45:52 2017 romain pillot
*/

#include "vm.h"

int	type_register(t_process *process, unsigned char mem[MEM_SIZE], int *pc)
{
  int	value;

  value = mem[(process->pc + *pc) % MEM_SIZE];
  (*pc)++;
  return (value);
}

int	type_indirect(t_process *process, unsigned char mem[MEM_SIZE], int *pc)
{
  int	value;

  value = bytes_to_int(0, 0,
		       mem[(process->pc + *pc) % MEM_SIZE],
		       mem[(process->pc + *pc + 1) % MEM_SIZE]);
  *pc += 2;
  return (value);
}

int     type_direct(t_process *process, unsigned char mem[MEM_SIZE], int *pc)
{
  int   value;

  value = bytes_to_int(mem[(process->pc + *pc) % MEM_SIZE],
		       mem[(process->pc + *pc + 1) % MEM_SIZE],
		       mem[(process->pc + *pc + 2) % MEM_SIZE],
		       mem[(process->pc + *pc + 3) % MEM_SIZE]);
  *pc += 4;
  return (value);
}
