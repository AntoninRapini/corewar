/*
** option.c for  in /home/romain.pillot/projects/CPE_2016_corewar/vm/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Wed Mar 29 12:19:11 2017 romain pillot
** Last update Sun Apr  2 14:15:29 2017 Antonin Rapini
*/

#include "vm.h"
#include "option.h"
#include <stdlib.h>
#include "util.h"

static bool	(* const opt_funcs[])(t_vm *vm,
				      char *arg, char *prog, int mod[2]) =
{
  &opt_help,
  &opt_dump,
  &opt_prog_nbr,
  &opt_prog_addr,
};

/*
** Index of parsed options
*/
static int	i = 0;

bool		valid_options(t_vm *vm, int ac, char **args)
{
  char		opt;
  char		*arg;
  char		*prog;
  int		modifiers[2];

  modifiers[0] = -1;
  modifiers[1] = -1;
  while (args[++i])
    {
      if (args[i][0] != '-' && modifiers[0] == -1 && modifiers[0] == -1)
	if (!process_init(vm, args[i], -1, -1))
	  return (false);
      if (args[i][0] != '-' || !(opt = args[i][1]))
	continue;
      arg = i + 1 >= ac ? NULL : args[i + 1][0] == '-' ? NULL : args[i + 1];
      prog = i >= ac - 2 ? NULL : args[i + 2][0] == '-' ? NULL : args[i + 2];
      if (!opt_funcs[opt == 'h' ? 0 :
		     opt == 'd' ? 1 :
		     opt == 'n' ? 2 :
		     opt == 'a' ? 3 : 0](vm, arg, prog, modifiers))
	return (false);
    }
  if (modifiers[0] != -1 || modifiers[1] != -1)
    display("Error: expected a program name\n", true);
  return (modifiers[0] == -1 && modifiers[1] == -1);
}

bool	opt_help(t_vm *vm, char *arg, char *prog, int mod[2])
{
  (void) vm;
  (void) arg;
  (void) prog;
  (void) mod;
  display("USAGE\n"
	  "\t./corewar [-dump nbr_cycle] [[-n prog_number] [-a load_address]"
	  "prog_name] ...\n"
	  "\nDESCRIPTION\n"
	  "\t-dump nbr_cycle "
	  "dumps the memory after the nbr_cycle execution (if the round isn't\n"
	  "\t\t\talready over) with the following format:  32 bytes/line in\n"
	  "\t\t\thexadecimal (A0BCDEFE1DD3...)\n"
	  "\t-n prog_number  "
	  "sets the next program's number.  By default, the first free number\n"
	  "\t\t\tin the parameter order\n"
	  "\t-a load_address "
	  "sets the next program's loading address.  When no address is\n"
	  "\t\t\tspecified, optimize the"
	  "addresses so that the processes are as far\n"
	  "\t\t\taway from each other as possible.  "
	  "The addresses are MEM_SIZE modulo\n", false);
  return (false);
}

bool	opt_dump(t_vm *vm, char *arg, char *prog, int mod[2])
{
  (void) prog;
  (void) mod;
  if (!arg)
    {
      display("-dump: missing argument\n", true);
      return (false);
    }
  if ((vm->dump_cooldown = getnbr(arg)) <= 0)
    {
      display("-dump: invalid parameter ((int)param > 0)\n", true);
      return (false);
    }
  i++;
  return (true);
}

bool	opt_prog_nbr(t_vm *vm, char *arg, char *prog, int mod[2])
{
  if (mod[0] != -1 || !arg)
    {
      display("-n: too many options (expected a program name) "
	      "or missing argument\n", true);
      return (false);
    }
  mod[0] = getnbr(arg);
  if (prog)
    {
      if (!process_init(vm, prog, mod[0], mod[1]))
	return (false);
      mod[0] = -1;
      mod[1] = -1;
      i++;
    }
  i++;
  return (true);
}

bool	opt_prog_addr(t_vm *vm, char *arg, char *prog, int mod[2])
{
  if (mod[1] != -1 || !arg)
    {
      display("-a: too many options (expected a program name) "
	      "or missing argument\n", true);
      return (false);
    }
  mod[1] = getnbr(arg);
  if (prog)
    {
      if (!process_init(vm, prog, mod[0], mod[1]))
	return (false);
      mod[0] = -1;
      mod[1] = -1;
      i++;
    }
  i++;
  return (true);
}
