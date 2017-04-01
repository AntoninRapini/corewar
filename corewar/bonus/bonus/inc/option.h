/*
** main.h for  in /home/romain.pillot/projects/CPE_2016_corewar/vm/include
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Wed Mar 29 10:33:50 2017 romain pillot
** Last update Sat Apr  1 07:27:01 2017 romain pillot
*/

#ifndef OPTION_H_
# define OPTION_H_

# include <stdbool.h>
# include "vm.h"

bool	valid_options(t_vm *vm, int ac, char **args);

bool	opt_dump(t_vm *vm, char *arg, char *prog, int mod[2]);

bool    opt_prog_nbr(t_vm *vm, char *arg, char *prog, int mod[2]);

bool    opt_prog_addr(t_vm *vm, char *arg, char *prog, int mod[2]);

bool    opt_help(t_vm *vm, char *arg, char *prog, int mod[2]);

#endif /** !OPTION_H_ **/
