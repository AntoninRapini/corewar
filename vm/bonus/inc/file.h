/*
** file.h for  in /home/romain.pillot/projects/CPE_2016_corewar/vm/include
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Thu Mar 30 14:01:15 2017 romain pillot
** Last update Fri Mar 31 23:59:28 2017 romain pillot
*/

#ifndef FILE_H_
# define FILE_H_

# include "vm.h"

int	open_file(char *file_name);

char	*file_content(t_process *process, int file_descriptor);

#endif /* !FILE_H_ */
