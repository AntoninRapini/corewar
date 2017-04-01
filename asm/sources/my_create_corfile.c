/*
** my_create_corfile.c for corewar in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_corewar/asm/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Mar 29 20:56:03 2017 Antonin Rapini
** Last update Sat Apr  1 09:05:23 2017 Antonin Rapini
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "sources.h"
#include "utils.h"
#include "my_asm.h"

char	*my_create_filename(char *sfile)
{
  char	*filename;
  int	i;
  int	j;

  i = my_strlen(sfile);
  j = 0;
  while (i > 0 && sfile[i] != '/')
    i--;
  i = i == 0 ? i : i + 1;
  while (sfile[i + j] != '.')
    j++;
  if ((filename = malloc(sizeof(char) * (j + 5))) == NULL)
    return (NULL);
  j = 0;
  while (sfile[i++] != '.')
    {
      filename[j] = sfile[i - 1];
      j++;
    }
  filename[j] = '.';
  filename[j + 1] = 'c';
  filename[j + 2] = 'o';
  filename[j + 3] = 'r';
  filename[j + 4] = '\0';
  return (filename);
}

int	my_create_corfile(t_cor *cor, char *sfile)
{
  char	*corfile_name;
  int	fd;

  if ((corfile_name = my_create_filename(sfile)) == NULL)
    return (1);
  if ((fd = open(corfile_name, O_CREAT| O_WRONLY, 0640)) == -1)
    return (1);
  free(corfile_name);
  if (my_write_header(fd, cor) == 0)
    {
      if (my_write_instructions(fd, cor) == 0)
	{
	  close(fd);
	  return (0);
	}
    }
  close(fd);
  return (1);
}
