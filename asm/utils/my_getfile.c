/*
** my_getfile.c for corewar in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_corewar/asm/utils
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Mar 29 00:36:33 2017 Antonin Rapini
** Last update Fri Mar 31 11:53:40 2017 Antonin Rapini
*/

#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "utils.h"

char	**my_getfile(char *file)
{
  char	*buffer;
  char	**content;
  int	fd;
  int	size;
  int	i;

  i = 0;
  size = 0;
  if ((fd = my_open_champion(file)) == -1)
    return (NULL);
  while ((buffer = get_next_line(fd)) != NULL)
    {
      free(buffer);
      size++;
    }
  lseek(fd, 0, SEEK_SET);
  if ((content = malloc(sizeof(char *) * (size + 1))) == NULL)
    return (NULL);
  content[size] = NULL;
  while ((buffer = get_next_line(fd)) != NULL)
    {
      content[i] = buffer;
      i++;
    }
  return (content);
}
