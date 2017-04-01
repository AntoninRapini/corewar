/*
** vm.h for  in /home/romain.pillot/projects/CPE_2016_corewar/vm/include
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Wed Mar 29 10:32:39 2017 romain pillot
** Last update Tue Apr  4 21:27:01 2017 romain pillot
*/

#ifndef VM_H_
# define VM_H_

# include <stdbool.h>
# include "list.h"

/*
** Magic code
*/
# define COREWAR_EXEC_MAGIC	0xea83f3

/*
** OP argument types
*/
# define T_REG			1
# define T_DIR			2
# define T_IND			3

/*
** Number of registers per processus
*/
# define REG_NUMBER		16

/*
** Multiples sizes
*/
# define IND_SIZE		2
# define DIR_SIZE		4
# define REG_SIZE		DIR_SIZE

/*
** Header infos
*/
# define PROG_NAME_LENGTH	128
# define COMMENT_LENGTH		2048
# define MAGIC_LENGTH		4
# define LEN_LENGTH		8
# define HEADER_LENGTH		2192

/*
** Cycles
*/
# define CYCLE_TO_DIE		1536
# define CYCLE_DELTA		4
# define NBR_LIVE		2048

/*
** Memory
*/
# define MEM_SIZE		(6*1024)
# define IDX_MOD		512
# define MAX_ARGS_NUMBER	4

/*
** Op's constant mnemonique values
*/
# define OPS_NBR		16
# define OP_NULL		0x00
# define OP_LIVE		0x01
# define OP_LD			0x02
# define OP_ST			0x03
# define OP_ADD			0x04
# define OP_SUB			0x05
# define OP_AND			0x06
# define OP_OR			0x07
# define OP_XOR			0x08
# define OP_ZJMP		0x09
# define OP_LDI			0x0A
# define OP_STI			0x0B
# define OP_FORK		0x0C
# define OP_LLD			0x0D
# define OP_LLDI		0x0E
# define OP_LFORK		0x0F
# define OP_AFF			0x10

/*
** FLAGS to get value from address
*/
# define NO_MOD			0b00000000
# define MOD			0b01000000
# define REG			0b00010000
# define IND			0b00100000
# define MOD_AND_IND		MOD | IND
# define MOD_AND_REG		MOD | REG

/*
** On process Fork:
** `data_len` contains the process instructions length,
** that should be used to get the instructions of the process
** from its starting address in the memory (cached in data_addr)
*/
typedef struct	s_process
{
  char		name[PROG_NAME_LENGTH];
  int		id;
  unsigned char	*data;
  int		data_addr;
  int		data_len;
  int		pc;
  int		cycle_cooldown;
  int		last_live_cycle;
  int		registers[REG_NUMBER];
  bool		carry;
}		t_process;

typedef struct	s_vm
{
  unsigned char	memory[MEM_SIZE + 1];
  int		dump_cooldown;
  int		live_cooldown;
  int		cycle_to_die;
  int		current_cycle;
  int		last_die_cycle;
  bool		running;
  t_list	*processes;
}		t_vm;

typedef struct	s_param
{
  int		value;
  char		type;
}		t_param;

typedef struct  s_op
{
  int           code;
  char          args;
  int           cycles;
  void          (*execute)(t_vm *vm, t_process *process, t_param params[4]);
}               t_op;

t_process	*process_init(t_vm *vm, unsigned char *prog, int id, int start_pc);

void		process_kill(t_vm *vm, t_process **ptr);

void		process_insertall(t_vm *vm);

int		bytes_to_int(unsigned char a,
			     unsigned char b,
			     unsigned char c,
			     unsigned char d);

char		param_type(char coding_byte, int index);

void		decode_header_name(char name[PROG_NAME_LENGTH],
				   unsigned char *content);

bool		valid_program(unsigned char *prog_content);

void		dump_memory(unsigned char memory[MEM_SIZE], int bline);

void		launch_cycles(t_vm *vm);

t_op		*parse_operation(unsigned char p);

int		parse_params(t_process *process, unsigned char mem[MEM_SIZE],
			     t_op *op,
			     t_param params[4]);

int		parse_value(t_param params,
			    t_vm *vm, t_process *process, char flag);

int		type_direct(t_process *process, unsigned char mem[MEM_SIZE], int *pc);

int		type_register(t_process *process, unsigned char mem[MEM_SIZE], int *pc);

int		type_indirect(t_process *process, unsigned char mem[MEM_SIZE], int *pc);

#endif /** !VM_H_ **/
