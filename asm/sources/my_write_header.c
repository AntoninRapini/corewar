/*
** my_write_header.c for corewar in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_corewar/asm/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Mar 29 21:19:05 2017 Antonin Rapini
** Last update Fri Mar 31 22:00:50 2017 Antonin Rapini
*/

#include "my_asm.h"
#include "utils.h"
#include <stdlib.h>
#include <unistd.h>

void	my_write_prog_len(int fd, t_cor *cor)
{
  char	to_write[PROG_LEN_LENGTH];
  char	*bytes;
  int	i;

  i = 0;
  my_memset(to_write, 0, PROG_LEN_LENGTH);
  bytes = (char *)&(cor->prog_len);
  while (i < PROG_LEN_LENGTH)
    {
      to_write[i] = bytes[PROG_LEN_LENGTH - 1 - i];
      i++;
    }
  write(fd, to_write, PROG_LEN_LENGTH);
}

int my_write_header(int fd, t_cor *cor)
{
  write(fd, "\0", 1);
  write(fd, COREWAR_EXEC_MAGIC_STR, my_strlen(COREWAR_EXEC_MAGIC_STR));
  write(fd, cor->header->prog_name, PROG_NAME_LENGTH);
  my_write_prog_len(fd, cor);
  write(fd, cor->header->comment, COMMENT_LENGTH);
  write(fd, "\0\0\0\0", 4);
  return (0);
}
