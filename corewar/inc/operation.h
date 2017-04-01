/*
** operation.h for  in /home/romain.pillot/projects/CPE_2016_corewar/vm/inc
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Sun Apr  2 03:31:51 2017 romain pillot
** Last update Sun Apr  2 09:56:53 2017 romain pillot
*/

#ifndef OPERATION_H_
# define OPERATION_H_

# include "vm.h"

void	op_live(t_vm *vm, t_process *process, t_param params[4]);

void    op_ld(t_vm *vm, t_process *process, t_param params[4]);

void    op_st(t_vm *vm, t_process *process, t_param params[4]);

void    op_add(t_vm *vm, t_process *process, t_param params[4]);

void    op_sub(t_vm *vm, t_process *process, t_param params[4]);

void    op_and(t_vm *vm, t_process *process, t_param params[4]);

void    op_or(t_vm *vm, t_process *process, t_param params[4]);

void    op_xor(t_vm *vm, t_process *process, t_param params[4]);

void    op_zjmp(t_vm *vm, t_process *process, t_param params[4]);

void    op_ldi(t_vm *vm, t_process *process, t_param params[4]);

void    op_sti(t_vm *vm, t_process *process, t_param params[4]);

void    op_fork(t_vm *vm, t_process *process, t_param params[4]);

void    op_lld(t_vm *vm, t_process *process, t_param params[4]);

void    op_lldi(t_vm *vm, t_process *process, t_param params[4]);

void    op_lfork(t_vm *vm, t_process *process, t_param params[4]);

void    op_aff(t_vm *vm, t_process *process, t_param params[4]);

#endif /* !OPERATION_H_ */
