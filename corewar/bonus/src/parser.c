/*
** parser.c for  in /home/romain.pillot/projects/CPE_2016_corewar/vm/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Sat Apr  1 23:25:16 2017 romain pillot
** Last update Tue Apr  4 19:21:28 2017 romain pillot
*/

#include "vm.h"
#include "operation.h"
#include "util.h"

static t_op	ops[] =
  {
    {OP_LIVE, 1, 10, &op_live},
    {OP_LD, 2, 5, &op_ld},
    {OP_ST, 2, 5, &op_st},
    {OP_ADD, 3, 10, &op_add},
    {OP_SUB, 3, 10, &op_sub},
    {OP_AND, 3, 6, &op_and},
    {OP_OR, 3, 6, &op_or},
    {OP_XOR, 3, 6, &op_xor},
    {OP_ZJMP, 1, 20, &op_zjmp},
    {OP_LDI, 3, 25, &op_ldi},
    {OP_STI, 3, 25, &op_sti},
    {OP_FORK, 1, 800, &op_fork},
    {OP_LLD, 2, 10, &op_lld},
    {OP_LLDI, 3, 50, &op_lldi},
    {OP_LFORK, 1, 1000, &op_lfork},
    {OP_AFF, 1, 2, &op_aff},
    {OP_NULL, 0, 0, 0}
  };

int	parse_value(t_param param, t_vm *vm, t_process *process, char flag)
{
  bool	modulo;
  int	bytes;
  int	mod;

  if (param.type == T_DIR)
    return (param.value);
  else if (param.type == T_REG)
    return (param.value > 16 || param.value <= 0 ? -1 :
	    process->registers[param.value - 1]);
  modulo = param_type(flag, 0) == 1;
  bytes = param_type(flag, 1) == T_REG ? REG_SIZE :
    param_type(flag, 1) == T_IND ? IND_SIZE : 1;
  mod = modulo ? IDX_MOD : param.value + 1;
  return (bytes == 1 ?
	  vm->memory[(process->pc + param.value % mod) % MEM_SIZE] :
	  bytes_to_int(bytes == 2 ? 0 :
		       vm->memory[(process->pc + param.value % mod) % MEM_SIZE],
		       bytes == 2 ? 0 :
		       vm->memory[(process->pc + 1 + param.value % mod) % MEM_SIZE],
		       vm->memory[(process->pc + 2 + param.value % mod) % MEM_SIZE],
		       vm->memory[(process->pc + 3 + param.value % mod) % MEM_SIZE]));
}

int			parse_params(t_process *process,
				     unsigned char mem[MEM_SIZE],
				     t_op *op,
				     t_param params[4])
{
  int			i;
  int			pc;
  unsigned char		coding_byte;
  static int		(* const x[3])(t_process *p, unsigned char m[MEM_SIZE], int *pc) =
    { &type_register, &type_direct, &type_indirect };
  
  if (op->code == OP_LIVE || op->code == OP_ZJMP || op->code == OP_FORK ||
      op->code == OP_LFORK)
    {
      params[0].value = op->code == OP_LIVE ? type_direct(process, mem, &pc) :
	type_indirect(process, mem, &pc);
      return (op->code == OP_ZJMP ? 0 : pc);
    }
  coding_byte = mem[(process->pc + 1) % MEM_SIZE];
  pc = 2;
  i = -1;
  while (++i < op->args)
    {
      if ((params[i].type = param_type(coding_byte, i)) != T_DIR &&
	  params[i].type != T_IND && params[i].type != T_REG)
	return (0);
      params[i].value = op->code == OP_LDI ? i == 2 ? type_register(process, mem, &pc) :
	type_indirect(process, mem, &pc) :x [params[i].type - 1](process, mem, &pc);
    }
  return (pc);
}

t_op	*parse_operation(unsigned char op)
{
  return (op >= 1 && op <= OPS_NBR ?
	  &(ops[op - 1]) :
	  &(ops[OPS_NBR]));
}
