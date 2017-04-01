/*
** sources.h for base in /home/antonin.rapini/my_programs/include
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Mar  2 17:18:06 2017 Antonin Rapini
** Last update Fri Mar 31 21:46:23 2017 Antonin Rapini
*/

#ifndef SOURCES_H_
# define SOURCES_H_

#include "my_asm.h"

t_cor *my_get_champion(char *);
int my_get_header(char **, t_header *);
int my_get_code(int, t_cor *);
char my_get_paramtype(t_param *);
int my_check_instruction(t_instruct *);
int my_create_corfile(t_cor *, char *);
int my_write_header(int, t_cor *);
int my_write_instructions(int, t_cor *);
void my_clear_param(t_param *);
int my_add_label(int , t_cor *, t_labellist **);
int my_add_instruction(int, t_cor *, t_instlist **);
int my_write_label(int, t_param *, t_labellist *, int);
int my_write_value(int, int, int);
int my_check_label_calls(t_labellist *, t_instlist *);

#endif /* !SOURCES_H_ */
